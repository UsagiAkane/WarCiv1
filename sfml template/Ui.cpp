#include "Ui.h"

Ui::Ui() {
	sf::Texture* tex = new sf::Texture;
	tex->loadFromFile("Icons\\VerticalScroll.png");
	v_scroll_sprite_.setTexture(*tex);
	this->font_.loadFromFile("18536.ttf");
	this->tgold_.setFont(this->font_);
	this->tsience_.setFont(this->font_);
	this->tturn_.setFont(this->font_);
	this->tyear_.setFont(this->font_);

	this->tgold_.setFillColor(sf::Color(0, 0, 0));
	this->tsience_.setFillColor(sf::Color(0, 0, 0));
	this->tturn_.setFillColor(sf::Color(0, 0, 0));
	this->tyear_.setFillColor(sf::Color(0, 0, 0));

	sf::Text log;
	for (int i = 0; i < LOGS_COUNT; i++) {
		this->g_log_.push_back(log);
		this->g_log_[i].setFont(this->font_);
		this->g_log_[i].setFillColor(sf::Color(255, 255, 255));
		this->g_log_[i].setString("");
		//this->gLog[i].setScale(0.7, 0.7);
	}
}

void Ui::game_log(sf::RenderWindow& w) {}

void Ui::resize(sf::RenderWindow& w) {
	v_scroll_sprite_.setScale(sf::Vector2f(static_cast<float>(w.getSize().x) / 300, static_cast<float>(w.getSize().x) / 300));
	this->v_scroll_sprite_.setPosition(static_cast<float>(w.getView().getCenter().x - w.getSize().x / 2), static_cast<float>(w.getView().getCenter().y + w.getSize().y / 2 - 57 * v_scroll_sprite_.getScale().y));

	this->tgold_.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tgold_.setPosition(v_scroll_sprite_.getPosition().x + 10 * v_scroll_sprite_.getScale().x, v_scroll_sprite_.getPosition().y + 10 * v_scroll_sprite_.getScale().y);

	this->tsience_.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tsience_.setPosition(v_scroll_sprite_.getPosition().x + 10 * v_scroll_sprite_.getScale().x, v_scroll_sprite_.getPosition().y + 20 * v_scroll_sprite_.getScale().y);

	this->tturn_.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tturn_.setPosition(v_scroll_sprite_.getPosition().x + 10 * v_scroll_sprite_.getScale().x, v_scroll_sprite_.getPosition().y + 30 * v_scroll_sprite_.getScale().y);

	this->tyear_.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tyear_.setPosition(v_scroll_sprite_.getPosition().x + 10 * v_scroll_sprite_.getScale().x, v_scroll_sprite_.getPosition().y + 40 * v_scroll_sprite_.getScale().y);
}

void Ui::set_params(int gold, int sience, int turn, int year) {
	std::string tmp;
	tmp = "Gold: ";
	tmp += std::to_string(gold);
	this->tgold_.setString(tmp);

	tmp = "Sci.: ";
	tmp += std::to_string(sience);
	this->tsience_.setString(tmp);

	tmp = "Turn: ";
	tmp += std::to_string(turn);
	this->tturn_.setString(tmp);

	tmp = "Year: ";
	tmp += std::to_string(year);
	this->tyear_.setString(tmp);
}

void Ui::set_string_logs(std::string text, bool does_clear) {
	if (!does_clear) {
		if (current_log < LOGS_COUNT) {
			this->g_log_.at(current_log).setString(text);
			current_log++;
		}
		else
			this->current_log = 0;
	}
	else {
		for (int i = 0; i < LOGS_COUNT; i++) {
			this->g_log_[i].setString(" ");
		}
		this->g_log_[0].setString(text);
		current_log = 0;
	}
}

void Ui::draw(sf::RenderWindow& w) {
	w.draw(this->v_scroll_sprite_);
	w.draw(this->tgold_);
	w.draw(this->tsience_);
	w.draw(this->tturn_);
	w.draw(this->tyear_);

	for (int i = 0; i < LOGS_COUNT; i++) {
		//Move all other logs
		if (i != 0)
			this->g_log_[i].setPosition(g_log_[i - 1].getPosition().x, g_log_[i - 1].getPosition().y + this->g_log_[i].getCharacterSize());
		else
			//move first log
			this->g_log_[i].setPosition(w.getView().getCenter().x - w.getSize().x / 2, w.getView().getCenter().y - w.getSize().y / 2);

		//change size
		this->g_log_[i].setCharacterSize(static_cast<float>(w.getSize().x) / 60);

		//if player doesn't use log-hide it
		if (is_log)
			w.draw(this->g_log_[i]);
	}
}