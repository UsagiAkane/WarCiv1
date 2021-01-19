#include "Town.h"

Town::Town(int position_x, int position_y, std::string name) {
	this->texture_.loadFromFile(PATH_TO_ICON_TOWN);
	this->town_sprite_.setTexture(texture_);
	this->position_x_ = position_x;
	this->position_y_ = position_y;
	this->town_sprite_.setPosition(static_cast<float>(position_x), static_cast<float>(position_y));
	this->font_.loadFromFile("18536.ttf");
	this->population_text_.setCharacterSize(25);
	this->population_text_.setFont(this->font_);
	this->population_text_.setPosition(static_cast<float>(this->position_x_ + 10), static_cast<float>(position_y));
	this->name_ = name;
	this->health_ = 10;
	this->damage_ = 1;
	this->production_ = 0;
	this->gold_income_ = 0;
	this->food_ = 5;
	this->population_ = 1;
	this->population_limit_ = 10;
	this->happines_ = 100;
	this->player_id_ = 1;//debug
	this->science_ = 0;
	this->isMenu = 0;//debug
}

void Town::create_unit(Map& map, int unit, std::vector<Unit>& actor) {
	Settlers* settlers = new Settlers();
	Militia* militia = new Militia();
	Legion* legion = new Legion();
	Cavalry* cavalry = new Cavalry();
	Chariot* chariot = new Chariot();
	for (auto i : this->buildings_) {
		settlers->set_rank(i.get_rank_multiplier());
		militia->set_rank(i.get_rank_multiplier());
		legion->set_rank(i.get_rank_multiplier());
		cavalry->set_rank(i.get_rank_multiplier());
		chariot->set_rank(i.get_rank_multiplier());
	}
	switch (unit) {
	case 1:
		if (this->production_ >= settlers->get_production_price()) {
			if (map.get_unit_ind(position_x_, position_y_) % 10 == 0) {
				if (population_ > 1) {
					this->production_ -= settlers->get_production_price();
					settlers->set_player_id(this->player_id_);
					settlers->spawn(position_x_, position_y_, map);
					actor.push_back(*settlers);
					this->population_--;
				}
				else std::cout << "<error> no humans in town(need >1)\n";
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << settlers->get_production_price() << ")\n";
		break;
	case 2:
		if (this->production_ >= militia->get_production_price()) {
			if (map.get_unit_ind(position_x_, position_y_) % 10 == 0) {
				this->production_ -= militia->get_production_price();
				militia->set_player_id(this->player_id_);
				militia->spawn(position_x_, position_y_, map);
				actor.push_back(*militia);
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << militia->get_production_price() << ")\n";
		break;
	case 3:
		if (this->production_ >= legion->get_production_price()) {
			if (map.get_unit_ind(position_x_, position_y_) % 10 == 0) {
				this->production_ -= legion->get_production_price();
				legion->set_player_id(this->player_id_);
				legion->spawn(position_x_, position_y_, map);
				actor.push_back(*legion);
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << legion->get_production_price() << ")\n";
		break;
	case 4:
		if (this->production_ >= cavalry->get_production_price()) {
			if (map.get_unit_ind(position_x_, position_y_) % 10 == 0) {
				this->production_ -= cavalry->get_production_price();
				cavalry->set_player_id(this->player_id_);
				cavalry->spawn(position_x_, position_y_, map);
				actor.push_back(*cavalry);
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << cavalry->get_production_price() << ")\n";
		break;
	case 5:
		if (this->production_ >= chariot->get_production_price()) {
			if (map.get_unit_ind(position_x_, position_y_) % 10 == 0) {
				this->production_ -= chariot->get_production_price();
				chariot->set_player_id(this->player_id_);
				chariot->spawn(position_x_, position_y_, map);
				actor.push_back(*chariot);
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << chariot->get_production_price() << ")\n";
		break;
	}
}
//1-Aqueduct, 2-Barracks, 3-Walls, 4-Lib, 5-Market
void Town::create_building(int building) {
	Aqueduct* aqueduct = new Aqueduct();			//1
	Barracks* barracks = new Barracks();			//2
	CityWalls* cityWalls = new CityWalls();			//3
	Library* library = new Library();				//4
	Marketplace* marketplace = new Marketplace();	//5

	switch (building) {
	case 1:
		if (this->production_ >= aqueduct->get_production_price()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings_.begin(), buildings_.end(), [](Building& index) {return index.get_name() == "Aqueduct"; }))) {		//HAVE OR NOT
				this->production_ -= aqueduct->get_production_price();
				this->buildings_.push_back(*aqueduct);
				this->population_limit_ += aqueduct->get_increase_limit();
				this->health_ += aqueduct->get_increase_hp();
				std::cout << "\nAqueduct builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << aqueduct->get_production_price() << ")\n";
		break;
	case 2:
		if (this->production_ >= barracks->get_production_price()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings_.begin(), buildings_.end(), [](Building& index) {return index.get_name() == "Barracks"; }))) {		 //HAVE OR NOT
				this->production_ -= barracks->get_production_price();
				this->buildings_.push_back(*barracks);
				this->population_limit_ += barracks->get_increase_limit();
				this->health_ += barracks->get_increase_hp();
				std::cout << "\nBarracks builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << barracks->get_production_price() << ")\n";
		break;
	case 3:
		if (this->production_ >= cityWalls->get_production_price()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings_.begin(), buildings_.end(), [](Building& index) {return index.get_name() == "City Walls"; }))) {	//HAVE OR NOT
				this->production_ -= cityWalls->get_production_price();
				this->buildings_.push_back(*cityWalls);
				this->population_limit_ += cityWalls->get_increase_limit();
				this->health_ += cityWalls->get_increase_hp();
				std::cout << "\nCity Walls builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << cityWalls->get_production_price() << ")\n";
		break;
	case 4:
		if (this->production_ >= library->get_production_price()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings_.begin(), buildings_.end(), [](Building& index) {return index.get_name() == "Library"; }))) { 		//HAVE OR NOT
				this->production_ -= library->get_production_price();
				this->buildings_.push_back(*library);
				this->population_limit_ += library->get_increase_limit();
				this->health_ += library->get_increase_hp();
				std::cout << "\nLibrary builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << library->get_production_price() << ")\n";
		break;
	case 5:
		if (this->production_ >= marketplace->get_production_price()) {	//PRICE
			if (!static_cast<bool>(std::count_if(buildings_.begin(), buildings_.end(), [](Building& index) {return index.get_name() == "Marketplace"; }))) {	//HAVE OR NOT
				this->production_ -= marketplace->get_production_price();
				this->buildings_.push_back(*marketplace);
				this->population_limit_ += marketplace->get_increase_limit();
				this->health_ += marketplace->get_increase_hp();
				std::cout << "\nMarketplace builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		else
			std::cout << "<error> no resourses: prod(" << this->production_ << "/" << marketplace->get_production_price() << ")\n";
		break;
	}
}
void Town::set_color_by_id() {
	if (this->player_id_ == 1)
		town_sprite_.setColor(sf::Color(180, 180, 255));//blue
	else if (this->player_id_ == 2)
		town_sprite_.setColor(sf::Color(255, 180, 180));//red
	else if (this->player_id_ == 3)
		town_sprite_.setColor(sf::Color(255, 255, 100));//yellow
	else if (this->player_id_ == 4)
		town_sprite_.setColor(sf::Color(180, 255, 180));//green
	else if (this->player_id_ == 5)
		town_sprite_.setColor(sf::Color(100, 255, 255));//purple
	else if (this->player_id_ == 6)
		town_sprite_.setColor(sf::Color(220, 125, 220));//pink
	else if (this->player_id_ > 6)
		town_sprite_.setColor(sf::Color(50, 50, 50));//dark
}
#pragma region GETERS
//GETERS
int Town::get_health() {
	return this->health_;
}
int Town::get_production() {
	return this->production_;
}
int Town::get_gold_income() {
	return this->gold_income_;
}
int Town::get_food() {
	return this->food_;
}
int Town::get_trade() {
	return this->trade_;
}
int Town::get_population() {
	return this->population_;
}
int Town::get_population_limit() {
	return this->population_limit_;
}
int Town::get_happines() {
	return this->happines_;
}
int Town::get_player_id() {
	return this->player_id_;
}
int Town::get_science() {
	return this->science_;
}
int Town::get_damage() {
	return this->damage_;
}
std::string Town::get_name() {
	return this->name_;
}
int Town::get_position_x() {
	return this->position_x_;
}
int Town::get_position_y() {
	return this->position_y_;
}
#pragma endregion
#pragma region SETERS
//SETTERS
void Town::set_position(int x, int y) {
	this->position_x_ = x;
	this->position_y_ = y;
	this->town_sprite_.setPosition(this->position_x_, this->position_y_);
	this->population_text_.setPosition(this->position_x_ + 10, this->position_y_);
}
void Town::set_health(int health) {
	this->health_ = health;
}
void Town::set_production(int prod) {
	this->production_ = production_;
}
void Town::set_gold_income(int goldIncome) {
	this->gold_income_ = goldIncome;
}
void Town::set_food(int food) {
	this->food_ = food;
}
void Town::set_trade(int trade) {
	this->trade_ = trade;
}
void Town::set_population(int population) {
	this->population_ = population;
}
void Town::set_happines(int happines) {
	this->happines_ = happines;
}
void Town::set_player_id(int player_id) {
	this->player_id_ = player_id;
}
void Town::set_population_limit(int population_limit) {
	this->population_limit_ = population_limit;
}
void Town::set_science(int science) {
	this->science_ = science;
}
void Town::set_name(std::string name) {
	this->name_ = name;
}
void Town::set_damage(int damage) {
	this->damage_ = damage;
}
#pragma endregion
//OTHER
bool isMouseInWindow(sf::RenderWindow& w) { return (sf::Mouse::getPosition(w).x >= 0 && sf::Mouse::getPosition(w).x < w.getSize().x) && ((sf::Mouse::getPosition(w).y >= 0 && sf::Mouse::getPosition(w).y < w.getSize().y)) ? true : false; }
void Town::statInfo(sf::RenderWindow& w) {
	sf::Texture menuTexture;
	menuTexture.loadFromFile("Icons\\VerticalScroll.png");
	sf::Sprite menuSprite(menuTexture);
	menuSprite.setPosition(this->town_sprite_.getPosition().x + 32, this->town_sprite_.getPosition().y);
	menuSprite.setScale(sf::Vector2f(4, 4));

	sf::Font font;
	font.loadFromFile("18536.ttf");
	sf::Text tProdaction, tHealth, tFood, tPopulationLimit, tPopulation, tHappines;
	//inicializate----------------------------------
	tProdaction.setFont(font);
	std::string productionstr = "Production = ";
	productionstr += std::to_string(this->production_);
	tProdaction.setString(productionstr);
	tProdaction.setFillColor(sf::Color::Black);
	tProdaction.setCharacterSize(14);
	tProdaction.setPosition(this->town_sprite_.getPosition().x + 32 + 40, this->town_sprite_.getPosition().y + 32);

	tHealth.setFont(font);
	std::string healthstr = "Health = ";
	healthstr += std::to_string(this->health_);
	tHealth.setString(healthstr);
	tHealth.setFillColor(sf::Color::Black);
	tHealth.setCharacterSize(14);
	tHealth.setPosition(this->town_sprite_.getPosition().x + 32 + 40, this->town_sprite_.getPosition().y + 32 + 23 * 1);

	tFood.setFont(font);
	std::string Foodstr = "Food = ";
	Foodstr += std::to_string(this->food_);
	tFood.setString(Foodstr);
	tFood.setFillColor(sf::Color::Black);
	tFood.setCharacterSize(14);
	tFood.setPosition(this->town_sprite_.getPosition().x + 32 + 40, this->town_sprite_.getPosition().y + 32 + 23 * 2);

	tPopulation.setFont(font);
	std::string poppstr = "Population = ";
	poppstr += std::to_string(this->population_);
	tPopulation.setString(poppstr);
	tPopulation.setFillColor(sf::Color::Black);
	tPopulation.setCharacterSize(14);
	tPopulation.setPosition(this->town_sprite_.getPosition().x + 32 + 40, this->town_sprite_.getPosition().y + 32 + 23 * 3);

	tPopulationLimit.setFont(font);
	std::string popstr = "Population\nLimit = ";
	popstr += std::to_string(this->population_);
	tPopulationLimit.setString(popstr);
	tPopulationLimit.setFillColor(sf::Color::Black);
	tPopulationLimit.setCharacterSize(14);
	tPopulationLimit.setPosition(this->town_sprite_.getPosition().x + 32 + 40, this->town_sprite_.getPosition().y + 32 + 23 * 4);

	tHappines.setFont(font);
	std::string hepstr = "Happines = ";
	hepstr += std::to_string(this->happines_);
	tHappines.setString(hepstr);
	tHappines.setFillColor(sf::Color::Black);
	tHappines.setCharacterSize(14);
	tHappines.setPosition(this->town_sprite_.getPosition().x + 32 + 40, this->town_sprite_.getPosition().y + 32 + 23 * 6);

	w.draw(menuSprite);
	w.draw(tProdaction);
	w.draw(tHealth);
	w.draw(tFood);
	w.draw(tPopulation);
	w.draw(tPopulationLimit);
	w.draw(tHappines);
}
void Town::draw(sf::RenderWindow& w, Map& map) {
	if (!map.is_fog(position_x_, position_y_)) {
		std::string prod;
		prod = std::to_string(this->population_);
		this->population_text_.setString(prod);
		w.draw(this->town_sprite_);
		w.draw(this->population_text_);
		if (this->isMenu)
			statInfo(w);
	}
}
void Town::end_of_turn(Map& map, int& gold, int& science) {
	//map.getTile(this->positionX, this->positionY).getName();
	int buildingTotalGoldIncome = 0;
	for (auto i : buildings_) {
		buildingTotalGoldIncome += i.get_gold_per_turn();
	}
	gold += buildingTotalGoldIncome + population_;
	int buildingTotalScienceIncome = 0;
	for (auto i : buildings_) {
		buildingTotalScienceIncome += i.get_science_multiplier();
	}
	science += buildingTotalScienceIncome;

	this->happines_ += gold + this->food_ + this->population_limit_;
	if (this->food_ > 30 && this->happines_ > 1000 && this->population_ < population_limit_) {
		this->population_++;
		this->food_ = 0;
		this->happines_ = 0;
	}

	this->food_ += map.get_tile(this->position_x_, this->position_y_).get_food();
	this->production_ += map.get_tile(this->position_x_, this->position_y_).get_production();
	this->trade_ += map.get_tile(this->position_x_, this->position_y_).get_trade();

	if (population_ > 9) {
		if (population_text_.getPosition().x == this->position_x_ + 10)
			population_text_.setPosition(population_text_.getPosition().x - 7, population_text_.getPosition().y);
	}
	if (population_ < 10) {
		if (population_text_.getPosition().x == this->position_x_ + 3)
			population_text_.setPosition(population_text_.getPosition().x + 7, population_text_.getPosition().y);
	}
}
std::string Town::get_save_town_info() {
	std::string unitInfo;
	unitInfo += this->name_;
	unitInfo += " ";
	unitInfo += std::to_string(this->player_id_);
	unitInfo += " ";
	unitInfo += std::to_string(this->position_x_);
	unitInfo += " ";
	unitInfo += std::to_string(this->position_y_);
	unitInfo += " ";
	unitInfo += std::to_string(this->health_);
	unitInfo += " ";
	unitInfo += std::to_string(this->damage_);
	unitInfo += " ";
	unitInfo += std::to_string(this->population_);
	unitInfo += " ";
	unitInfo += std::to_string(this->population_limit_);
	unitInfo += " ";
	unitInfo += std::to_string(this->production_);
	unitInfo += " ";
	unitInfo += std::to_string(this->food_);
	unitInfo += " ";
	unitInfo += std::to_string(this->trade_);
	unitInfo += " ";
	unitInfo += std::to_string(this->happines_);
	unitInfo += " ";
	unitInfo += std::to_string(this->gold_income_);
	unitInfo += " ";
	unitInfo += std::to_string(this->science_);
	unitInfo += "\n~\n";
	for (auto i : buildings_) {
		unitInfo += i.get_name();
		unitInfo += "%";
	}

	return unitInfo;
}
void Town::spawn(int x, int y, Map& map) {
	set_position(x, y);
	map.push_unit(x, y, this->player_id_ * 100 + 50);
	set_color_by_id();
}