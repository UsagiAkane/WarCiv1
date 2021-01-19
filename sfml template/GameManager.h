#pragma once
#include"AI.h"
#include"Map.h"
#include"Ui.h"

class GameManager {
private:
	Ui ui_;
	std::vector<Actor> actors_;
	Map map_;
	int current_year_;
public:
	sf::Sprite ref;
	bool is_ref;

	GameManager();

	Map& get_map();
	std::vector<Actor>& get_actors();

	void set_year(int year); //set current year
	auto getYear() -> int&; //return current year
	void draw(sf::RenderWindow& w, sf::View& v);
	Actor& find_actor_hidden(int ID); // find and return vector by ID
	Actor& find_actor(int mouse_x, int mouse_y); //get mouse position and return vector of units of actor
	void save_game();
	void load_game();
	void deleteAllActors();
	Ui& get_ui();
};
