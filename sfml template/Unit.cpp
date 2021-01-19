#include "Unit.h"
//Checking whether a unit can attack
void Unit::checkForAttackAndAttackHide(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w, int direction) {
	int time = 0;//variable that show which unit you need to attack
	bool tmp = true;
	for (auto i : enemies_id)//try to find enemy in enemy vector
	{
		if (i == (map.get_unit_ind(mouse_x, mouse_y) / 100))//compare id of all players and enemies id
		{
			for (auto j : enemies)//
			{
				if (j.get_index() == (map.get_unit_ind(mouse_x, mouse_y) % 100))//find enemy in enemy vector
				{
					tmp = false;
					attack(enemies.at(time), map, mouse_x, mouse_y);//attack him
					animation_of_attack(direction, w, map);
					break;
				}
				time++;
			}
			break;
		}
	}
	if (map.get_unit_ind(mouse_x, mouse_y) / 100 != this->player_id_ && map.get_unit_ind(mouse_x, mouse_y) != 0 && tmp == true) {
		enemies_id.push_back(map.get_unit_ind(mouse_x, mouse_y) / 100);
	}
}

void Unit::animation_of_attack(int value, sf::RenderWindow& w, Map& map) {
	sf::Texture textureTMP;
	textureTMP.loadFromFile("Icons\\swordicon.png");
	sf::Sprite tmp(textureTMP);
	sf::Texture textureTMPs;
	textureTMPs.loadFromFile("Icons\\shieldicon.png");
	sf::Sprite tmps(textureTMPs);
	//right
	if (value == 1) {
		tmp.setPosition(static_cast<float>(position_x_ + 10), static_cast<float>(position_y_));
		tmp.setScale(static_cast<float>(0.9), static_cast <float>(0.9));
		tmps.setScale(static_cast <float>(0.7), static_cast <float>(0.7));
		tmps.setPosition(static_cast<float>(position_x_ + 30), static_cast<float>(position_y_ + 3));
	}
	//left
	else if (value == 2) {
		textureTMP.loadFromFile("Icons\\swordiconflip.png");
		tmp.setPosition(static_cast<float>(position_x_ - 10), static_cast<float>(position_y_));
		tmp.setScale(static_cast <float>(0.9), static_cast <float>(0.9));
		tmps.setScale(static_cast <float>(0.7), static_cast <float>(0.7));
		tmps.setPosition(static_cast<float>(position_x_ - 20), static_cast<float>(position_y_ + 3));
	}
	//top
	else if (value == 3) {
		tmp.setPosition(static_cast<float>(position_x_), static_cast<float>(position_y_ - 10));
		tmp.setScale(static_cast <float>(0.9), static_cast <float>(0.9));
		tmps.setScale(static_cast <float>(0.7), static_cast <float>(0.7));
		tmps.setPosition(static_cast<float>(position_x_ + 6), static_cast<float>(position_y_ - 20));
	}
	//down
	else if (value == 4) {
		textureTMP.loadFromFile("Icons\\swordiconflipdown.png");
		tmp.setPosition(static_cast<float>(position_x_), static_cast<float>(position_y_ + 10));
		tmp.setScale(static_cast <float>(0.9), static_cast <float>(0.9));
		tmps.setScale(static_cast <float>(0.7), static_cast <float>(0.7));
		tmps.setPosition(static_cast<float>(position_x_ + 9), static_cast<float>(position_y_ + 30));
	}

	w.draw(warrior_sprite_);
	w.draw(tmps);
	w.draw(tmp);
	w.display();
	Sleep(600);
}

void Unit::move_right_hidden(Map& map, int mouse_x, int mouse_y) {
	if (this->health_ > 0) {
		position_x_ += BORDER_PIXEL_32;
		this->warrior_sprite_.setPosition(static_cast<float>(position_x_), static_cast<float>(position_y_));
		this->steps_ -= map.get_tile(mouse_x, mouse_y).get_move();
		map.move_unit(position_x_ - BORDER_PIXEL_32, position_y_, position_x_, position_y_, this->player_id_);
	}
}

void Unit::move_left_hidden(Map& map, int mouse_x, int mouse_y) {
	if (this->health_ > 0) {
		position_x_ -= BORDER_PIXEL_32;
		this->warrior_sprite_.setPosition(static_cast<float>(position_x_), static_cast<float>(position_y_));
		this->steps_ -= map.get_tile(mouse_x, mouse_y).get_move();
		map.move_unit(position_x_ + BORDER_PIXEL_32, position_y_, position_x_, position_y_, this->player_id_);
	}
}

void Unit::move_down_hidden(Map& map, int mouse_x, int mouse_y) {
	if (this->health_ > 0) {
		position_y_ += BORDER_PIXEL_32;
		this->warrior_sprite_.setPosition(static_cast<float>(position_x_), static_cast<float>(position_y_));
		this->steps_ -= map.get_tile(mouse_x, mouse_y).get_move();
		map.move_unit(position_x_, position_y_ - BORDER_PIXEL_32, position_x_, position_y_, this->player_id_);
	}
}

void Unit::move_top_hidden(Map& map, int mouse_x, int mouse_y) {
	if (this->health_ > 0) {
		position_y_ -= BORDER_PIXEL_32;
		this->warrior_sprite_.setPosition(static_cast<float>(position_x_), static_cast<float>(position_y_));
		this->steps_ -= map.get_tile(mouse_x, mouse_y).get_move();
		map.move_unit(position_x_, position_y_ + BORDER_PIXEL_32, position_x_, position_y_, this->player_id_);
	}
}

Unit::Unit(std::string name, int health, int armor, int damage, int speed, unsigned short rank, int salary, int production_price, int price, int index, int player_id, int max_speed) {
	this->name_ = name;
	this->health_ = health;
	this->armor_ = armor;
	this->damage_ = damage;
	this->steps_ = speed;
	this->rank_ = 0;
	this->salary_ = salary;
	this->production_price_ = production_price;
	this->price_ = price;
	this->index_ = index;
	this->player_id_ = player_id;
	this->is_active_ = true;
	this->count_of_kill_ = 0;
	this->is_alive_ = 1;
	this->position_x_ = 0;
	this->position_y_ = 0;
	this->max_steps_ = max_speed;
}

void Unit::move(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w) {
	if (is_active_ != false) {
		////right
		if (((mouse_x <= this->position_x_ + BORDER_PIXEL_60 && mouse_x >= this->position_x_ + BORDER_PIXEL_30) && (mouse_y >= position_y_ && mouse_y <= this->position_y_ + BORDER_PIXEL_30)))//check position of mouse
		{
			if (map.get_tile(mouse_x, mouse_y).get_move() <= this->steps_) {
				if ((map.get_unit_ind(mouse_x, mouse_y)) % 100 != 0) //check index of unit
					checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w, 1);   //Checking whether a unit can attack
				if ((map.get_unit_ind(mouse_x, mouse_y)) == 0 && !(map.get_tile(mouse_x, mouse_y).is_water()))//check is tile empty
					move_right_hidden(map, mouse_x, mouse_y);//move to this position if empty
			}
		}
		////left
		else if (((mouse_x >= this->position_x_ - BORDER_PIXEL_30 && mouse_x <= this->position_x_) && (mouse_y >= position_y_ && mouse_y <= this->position_y_ + BORDER_PIXEL_30)))//check position of mouse
		{
			if (map.get_tile(mouse_x, mouse_y).get_move() <= this->steps_) {
				if ((map.get_unit_ind(mouse_x, mouse_y)) % 100 != 0)//check index of unit
					checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w, 2); //Checking whether a unit can attack
				if ((map.get_unit_ind(mouse_x, mouse_y)) == 0 && !(map.get_tile(mouse_x, mouse_y).is_water()))//check is tile empty
					move_left_hidden(map, mouse_x, mouse_y);//move to this position if empty
			}
		}
		////top
		else if ((mouse_y >= position_y_ - BORDER_PIXEL_30 && mouse_y <= position_y_) && (mouse_x >= position_x_ && mouse_x <= position_x_ + BORDER_PIXEL_30))//check position of mouse
		{
			if (map.get_tile(mouse_x, mouse_y).get_move() <= this->steps_) {
				if ((map.get_unit_ind(mouse_x, mouse_y)) % 100 != 0)//check index of unit
					checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w, 3); //Checking whether a unit can attack
				if ((map.get_unit_ind(mouse_x, mouse_y)) == 0 && !(map.get_tile(mouse_x, mouse_y).is_water()))//check is tile empty
					move_top_hidden(map, mouse_x, mouse_y);//move to this position if empty
			}
		}
		////down
		else if ((mouse_y <= position_y_ + BORDER_PIXEL_60 && mouse_y >= position_y_ + BORDER_PIXEL_30) && (mouse_x >= position_x_ && mouse_x <= position_x_ + BORDER_PIXEL_30))//check position of mouse
		{
			if (map.get_tile(mouse_x, mouse_y).get_move() <= this->steps_) {
				if ((map.get_unit_ind(mouse_x, mouse_y)) % 100 != 0)//check index of unit
					checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w, 4); //Checking whether a unit can attack
				if ((map.get_unit_ind(mouse_x, mouse_y)) == 0 && !(map.get_tile(mouse_x, mouse_y).is_water()))//check is tile empty
					move_down_hidden(map, mouse_x, mouse_y);//move to this position if empty
			}
		}
		this->check_steps();
		this->check_up_unit();
	}
}

void Unit::attack(Unit& uEnemy, Map& map, int x, int y) {
	//damage to attacker
	if (this->health_ <= 0) {
	}
	this->health_ -= ((uEnemy.get_damage() + uEnemy.get_rank()) - (this->armor_));
	this->set_armor(this->armor_ - (uEnemy.get_damage() + uEnemy.get_rank()));
	//damage to defender unit

	uEnemy.health_ -= ((this->get_damage() + this->get_rank()) - (uEnemy.get_armor() + map.get_tile(x, y).get_defense()));
	uEnemy.set_armor(armor_ - (this->get_damage() + this->get_rank()));

	if (this->get_health() <= 0) {
		this->death(map);
		uEnemy.set_count_of_kill(+1);
	}

	if (uEnemy.get_health() <= 0) {
		uEnemy.death(map);
		this->count_of_kill_ += 1;
	}
}

void Unit::recharge() {
	this->steps_ = max_steps_;
	this->is_active_ = true;
}

void Unit::get_show_info_debug() {
	std::cout << "============================================" << this->health_ << std::endl;
	std::cout << "Health: " << this->health_ << std::endl;
	std::cout << "Armor: " << this->armor_ << std::endl;
	std::cout << "Damage:" << this->damage_ << std::endl;
	std::cout << "Count of kill: " << this->count_of_kill_ << std::endl;
	std::cout << "Index: " << this->index_ << std::endl;
	std::cout << "Rank: " << this->rank_ << std::endl;
	std::cout << "Alive: " << this->is_alive_ << std::endl;
	std::cout << "X: " << this->position_x_ << std::endl;
	std::cout << "Y: " << this->position_y_ << std::endl;
}

void Unit::skip_turn() {
	this->is_active_ = false;
}

void Unit::burrow() {
	this->is_active_ = false;
}

bool Unit::get_is_alive() {
	if (health_ <= 0) {
		is_alive_ = false;
		return false;
	}
	else
		return true;
}

bool Unit::get_is_active() {
	return this->is_active_;
}

void Unit::wait() {
	this->is_active_ = false;
}

int Unit::get_damage() {
	return this->damage_;
}

int Unit::get_health() {
	return this->health_;
}

int Unit::get_armor() {
	return this->armor_;
}

int Unit::get_rank() {
	return this->rank_;
}

void Unit::set_damage(int damage) {
	this->damage_ = damage;
}

void Unit::set_health(int health) {
	this->health_ = health;
}

void Unit::set_rank(int rank) {
	this->rank_ = rank;
}

void Unit::set_count_of_kill(unsigned int count_of_kill) {
	this->count_of_kill_ = count_of_kill;
}

void Unit::set_active(bool active) {
	this->is_active_ = active;
}

void Unit::set_position(int x, int y) {
	this->position_x_ = x;
	this->position_y_ = y;
	this->warrior_sprite_.setPosition(static_cast<float>(x), static_cast<float>(y));
}

void Unit::set_player_id(int id) {
	this->player_id_ = id;
}

void Unit::draw(sf::RenderWindow& w, Map& map) {
	if (!map.is_fog(position_x_, position_y_))
		if (this->is_alive_)
			w.draw(this->warrior_sprite_);
}

void Unit::spawn(int x, int y, Map& map) {
	this->position_x_ = x;
	this->position_y_ = y;
	this->warrior_sprite_.setPosition(static_cast<float>(x), static_cast<float>(y));
	map.push_unit(x, y, (this->player_id_ * 100) + this->index_);
	set_color_by_id();
	if (this->player_id_ == 1)
		map.radar_fog(x / 32, y / 32);
}

void Unit::death(Map& map) {
	this->is_alive_ = false;
	this->is_active_ = false;
	this->max_steps_ = 0;
	map.del_unit(position_x_, position_y_);
}

void Unit::set_color_by_id() {
	if (this->player_id_ == 1)
		warrior_sprite_.setColor(sf::Color(180, 180, 255));//blue
	else if (this->player_id_ == 2)
		warrior_sprite_.setColor(sf::Color(255, 180, 180));//red
	else if (this->player_id_ == 3)
		warrior_sprite_.setColor(sf::Color(255, 255, 100));//yellow
	else if (this->player_id_ == 4)
		warrior_sprite_.setColor(sf::Color(180, 255, 180));//green
	else if (this->player_id_ == 5)
		warrior_sprite_.setColor(sf::Color(100, 255, 255));//purple
	else if (this->player_id_ == 6)
		warrior_sprite_.setColor(sf::Color(220, 125, 220));//pink
	else if (this->player_id_ > 6)
		warrior_sprite_.setColor(sf::Color(50, 50, 50));//dark
}

void Unit::check_up_unit() {
	if (this->count_of_kill_ >= 2) {
		this->rank_ += 1;
		this->count_of_kill_ = 0;
	}
}

void Unit::check_steps() {
	if (steps_ <= 0)
		this->is_active_ = false;
}

bool Unit::is_enemy_in_enemy_id_list(std::vector<Unit> enemies_id) {}

std::string Unit::get_save_unit_info() {
	std::string unitInfo;
	unitInfo += std::to_string(this->health_);
	unitInfo += " ";
	unitInfo += std::to_string(this->armor_);
	unitInfo += " ";
	unitInfo += std::to_string(this->damage_);
	unitInfo += " ";
	unitInfo += std::to_string(this->steps_);
	unitInfo += " ";
	unitInfo += std::to_string(this->rank_);
	unitInfo += " ";
	unitInfo += std::to_string(this->count_of_kill_);
	unitInfo += " ";
	unitInfo += std::to_string(this->index_);
	unitInfo += " ";
	unitInfo += std::to_string(this->player_id_);
	unitInfo += " ";
	unitInfo += std::to_string(this->position_x_);
	unitInfo += " ";
	unitInfo += std::to_string(this->position_y_);
	unitInfo += " 1";
	unitInfo += "|";

	return unitInfo;
}

void Unit::del_by_position_in_vector(std::vector<Unit>& units) {  //test
	int tmp = 0;
	int positionX = this->get_sprite().getPosition().x;
	int positionY = this->get_sprite().getPosition().y;
	std::for_each(units.begin(), units.end(), [&tmp, &positionX, &positionY](Unit& u) { if (u.get_sprite().getPosition().x == positionX && u.get_sprite().getPosition().y == positionY) return tmp;
	else tmp++; });
	units.erase(tmp + units.begin());
}

int Unit::find_index_of_enemy(int mouse_x, int mouse_y, Map& map) {
	//right
	if (((mouse_x <= this->position_x_ + BORDER_PIXEL_60 && mouse_x >= this->position_x_ + BORDER_PIXEL_30) && (mouse_y >= position_y_ && mouse_y <= this->position_y_ + BORDER_PIXEL_30)))//check position of mouse
		return (map.get_unit_ind(mouse_x, mouse_y) / 100);
	////left
	else if (((mouse_x >= this->position_x_ - BORDER_PIXEL_30 && mouse_x <= this->position_x_) && (mouse_y >= position_y_ && mouse_y <= this->position_y_ + BORDER_PIXEL_30)))//check position of mouse
		return (map.get_unit_ind(mouse_x, mouse_y) / 100);
	////top
	else if ((mouse_y >= position_y_ - BORDER_PIXEL_30 && mouse_y <= position_y_) && (mouse_x >= position_x_ && mouse_x <= position_x_ + BORDER_PIXEL_30))//check position of mouse
		return (map.get_unit_ind(mouse_x, mouse_y) / 100);
	////down
	else if ((mouse_y <= position_y_ + BORDER_PIXEL_60 && mouse_y >= position_y_ + BORDER_PIXEL_30) && (mouse_x >= position_x_ && mouse_x <= position_x_ + BORDER_PIXEL_30))//check position of mouse
		return (map.get_unit_ind(mouse_x, mouse_y) / 100);
	//else
	else return 1;
}

void Unit::set_armor(int armor) {
	this->armor_ = armor;
}

void Unit::set_steps(int steps) {
	this->steps_ = steps;
}

sf::Sprite Unit::get_sprite() {
	return this->warrior_sprite_;
}

int Unit::get_index() {
	return this->index_;
}

int Unit::get_position_x() {
	return this->position_x_;
}

int Unit::get_position_y() {
	return this->position_y_;
}

std::string Unit::get_name() {
	return this->name_;
}

int Unit::get_player_id() {
	return this->player_id_;
}

int Unit::get_max_speed() {
	return this->max_steps_;
}

int Unit::get_production_price() {
	return this->production_price_;
}

int Unit::get_price() {
	return this->price_;
}

int Unit::get_steps() {
	return this->steps_;
}

Unit::~Unit() {}