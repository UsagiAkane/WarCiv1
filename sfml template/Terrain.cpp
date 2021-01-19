#include <iostream>
#include "Terrain.h";

Terrain::Terrain() {
	this->name_ = "<Terrain>";
	this->move_ = 0;
	this->food_ = 0;
	this->production_ = 0;
	this->trade_ = 0;
	this->defense_ = 0;
}

sf::Texture Terrain::get_texture() {
	return this->texture_;
}

std::string Terrain::get_name() {
	return this->name_;
}

int Terrain::get_move() {
	return this->move_;
}

int Terrain::get_food() {
	return this->food_;
}

int Terrain::get_production() {
	return this->production_;
}

int Terrain::get_trade() {
	return this->trade_;
}

int Terrain::get_defense() {
	return this->defense_;
}

bool Terrain::is_water() {
	return this->name_ == "ocean" ? true : false;
}

void Terrain::__getInfo_DEBUG() {
	std::cout << "\n-----tile-----\n";
	std::cout << "name = " << this->name_ << std::endl;
	std::cout << "move = " << this->move_ << std::endl;
	std::cout << "food = " << this->food_ << std::endl;
	std::cout << "prodaction = " << this->production_ << std::endl;
	std::cout << "trade = " << this->trade_ << std::endl;
	std::cout << "defense = " << this->defense_;
	std::cout << "\n---tile-end---\n";
}
void Terrain::get_info(sf::RenderWindow& w) {
	sf::Texture menuTexture;
	menuTexture.loadFromFile("Icons\\VerticalScroll.png");
	sf::Sprite menuSprite(menuTexture);
	menuSprite.setPosition(this->sprite_.getPosition().x - 184, this->sprite_.getPosition().y - 228);
	menuSprite.setScale(sf::Vector2f(4, 4));

	sf::Font font;
	font.loadFromFile("18536.ttf");
	sf::Text tProdaction, tHealth, tFood, tPopulationLimit, tPopulation, tHappines;
	//inicializate----------------------------------
	tProdaction.setFont(font);
	std::string productionstr = "name = ";
	productionstr += this->name_;
	tProdaction.setString(productionstr);
	tProdaction.setFillColor(sf::Color::Black);
	tProdaction.setCharacterSize(14);
	tProdaction.setPosition(this->sprite_.getPosition().x - 184 + 40, this->sprite_.getPosition().y - 228);

	tHealth.setFont(font);
	std::string healthstr = "move = ";
	healthstr += std::to_string(this->move_);
	tHealth.setString(healthstr);
	tHealth.setFillColor(sf::Color::Black);
	tHealth.setCharacterSize(14);
	tHealth.setPosition(this->sprite_.getPosition().x - 184 + 40, this->sprite_.getPosition().y - 228 + 23 * 1);

	tFood.setFont(font);
	std::string Foodstr = "Food = ";
	Foodstr += std::to_string(this->food_);
	tFood.setString(Foodstr);
	tFood.setFillColor(sf::Color::Black);
	tFood.setCharacterSize(14);
	tFood.setPosition(this->sprite_.getPosition().x - 184 + 40, this->sprite_.getPosition().y - 228 + 23 * 2);

	tPopulation.setFont(font);
	std::string poppstr = "prodaction = ";
	poppstr += std::to_string(this->production_);
	tPopulation.setString(poppstr);
	tPopulation.setFillColor(sf::Color::Black);
	tPopulation.setCharacterSize(14);
	tPopulation.setPosition(this->sprite_.getPosition().x - 184 + 40, this->sprite_.getPosition().y - 228 + 23 * 3);

	tPopulationLimit.setFont(font);
	std::string popstr = "trade = ";
	popstr += std::to_string(this->trade_);
	tPopulationLimit.setString(popstr);
	tPopulationLimit.setFillColor(sf::Color::Black);
	tPopulationLimit.setCharacterSize(14);
	tPopulationLimit.setPosition(this->sprite_.getPosition().x - 184 + 40, this->sprite_.getPosition().y - 228 + 23 * 4);

	tHappines.setFont(font);
	std::string hepstr = "defense = ";
	hepstr += std::to_string(this->defense_);
	tHappines.setString(hepstr);
	tHappines.setFillColor(sf::Color::Black);
	tHappines.setCharacterSize(14);
	tHappines.setPosition(this->sprite_.getPosition().x - 184 + 40, this->sprite_.getPosition().y - 228 + 23 * 6);

	w.draw(menuSprite);
	w.draw(tProdaction);
	w.draw(tHealth);
	w.draw(tFood);
	w.draw(tPopulation);
	w.draw(tPopulationLimit);
	w.draw(tHappines);
}

void Terrain::draw(sf::RenderWindow& w) {
	w.draw(sprite_);
}