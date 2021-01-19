#pragma once
#include<SFML/Graphics.hpp>

#define LOGS_COUNT 8

class Ui {
private:
	//sf::RectangleShape DownLeftRect;
	//sf::RectangleShape DownRightRect;
	//sf::RectangleShape DownMiddleRect;
	sf::Font font_;
	sf::Text tgold_;
	sf::Text tsience_;
	sf::Text tturn_;
	sf::Text tyear_;
	std::vector<sf::Text> g_log_;
	sf::Sprite v_scroll_sprite_;
public:
	bool is_log = false;
	int current_log = 0;

	Ui();
	void game_log(sf::RenderWindow& w);
	void resize(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	void set_params(int gold, int sience, int turn, int year);

	//for user
	void set_string_logs(std::string text, bool does_clear = false);
};
