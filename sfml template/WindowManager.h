#pragma once
#include "Actor.h"
#include "GameManager.h"

class WindowManager {
private:
	sf::RenderWindow w_;
	bool is_menu_ = true; //true

public:
	WindowManager();
	//create new game if false or empty, load game if true
	void new_game_window(bool doesLoad = false);
	//move camera
	void camera_control(sf::View& view, sf::Window& window);
	//check is mouse in window coordination
	bool is_mouse_in_window(sf::RenderWindow& w);
	//function to get pos mouse in window
	int get_pos_mouse_by_window_x(sf::RenderWindow& w);
	//function to get pos mouse in window
	int get_pos_mouse_by_window_y(sf::RenderWindow& w);
	//main menu function has a few buttons
	void main_menu(sf::RenderWindow& w);
	//game menu function has a few buttons but is a little bit another
	void game_menu(sf::RenderWindow& w, GameManager& game);

	sf::RenderWindow& get_window();
};
