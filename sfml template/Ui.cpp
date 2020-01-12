#include "Ui.h"

Ui::Ui()
{
	//this->DownLeftRect.setFillColor(sf::Color(50,50,50));
	//this->DownMiddleRect.setFillColor(sf::Color(50, 50, 50));
	//this->DownRightRect.setFillColor(sf::Color(50, 50, 50));
	sf::Texture* tex = new sf::Texture;
	tex->loadFromFile("Icons\\VerticalScroll.png");
	vScrollSprite.setTexture(*tex);
	this->font.loadFromFile("18536.ttf");
	this->tgold.setFont(this->font);
	this->tsience.setFont(this->font);
	this->tturn.setFont(this->font);
	this->tyear.setFont(this->font);

	this->tgold.setFillColor(sf::Color(0, 0, 0));
	this->tsience.setFillColor(sf::Color(0, 0, 0));
	this->tturn.setFillColor(sf::Color(0, 0, 0));
	this->tyear.setFillColor(sf::Color(0, 0, 0));
}

void Ui::resize(sf::RenderWindow& w)
{
	//this->DownLeftRect.setSize(sf::Vector2f(w.getSize().x / 10, w.getSize().x / 10));
	//this->DownMiddleRect.setSize(sf::Vector2f(w.getSize().x / 2, w.getSize().x / 10));
	//this->DownRightRect.setSize(sf::Vector2f(w.getSize().x / 10, w.getSize().x / 10));
	//DownLeftRect.setPosition(static_cast<float>(w.getView().getCenter().x - w.getSize().x / 2), static_cast<float>(w.getView().getCenter().y + w.getSize().y / 2 - DownLeftRect.getSize().y));
	//DownMiddleRect.setPosition(static_cast<float>(w.getView().getCenter().x - DownMiddleRect.getSize().x / 2 * DownMiddleRect.getScale().x), static_cast<float>(w.getView().getCenter().y + w.getSize().y / 2 - DownMiddleRect.getSize().y));
	//DownRightRect.setPosition(static_cast<float>(w.getView().getCenter().x + w.getSize().x / 2 - DownRightRect.getSize().x), static_cast<float>(w.getView().getCenter().y + w.getSize().y / 2 - DownRightRect.getSize().y));


	vScrollSprite.setScale(sf::Vector2f(static_cast<float>(w.getSize().x) / 300, static_cast<float>(w.getSize().x) / 300));
	this->vScrollSprite.setPosition(static_cast<float>(w.getView().getCenter().x - w.getSize().x / 2), static_cast<float>(w.getView().getCenter().y + w.getSize().y / 2 - 57 * vScrollSprite.getScale().y));

	this->tgold.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tgold.setPosition(vScrollSprite.getPosition().x+10 * vScrollSprite.getScale().x, vScrollSprite.getPosition().y+10* vScrollSprite.getScale().y);

	this->tsience.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tsience.setPosition(vScrollSprite.getPosition().x + 10 * vScrollSprite.getScale().x, vScrollSprite.getPosition().y + 20 * vScrollSprite.getScale().y);

	this->tturn.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tturn.setPosition(vScrollSprite.getPosition().x + 10 * vScrollSprite.getScale().x, vScrollSprite.getPosition().y + 30 * vScrollSprite.getScale().y);

	this->tyear.setCharacterSize(static_cast<float>(w.getSize().x) / 60);
	this->tyear.setPosition(vScrollSprite.getPosition().x + 10 * vScrollSprite.getScale().x, vScrollSprite.getPosition().y +40 * vScrollSprite.getScale().y);


}

void Ui::setParams(int gold, int sience, int turn, int year) 
{
	std::string tmp;
	tmp = "Gold: ";
	tmp += std::to_string(gold);
	this->tgold.setString(tmp);
	
	tmp = "Sci.: ";
	tmp += std::to_string(sience);
	this->tsience.setString(tmp);
	
	tmp = "Turn: ";
	tmp += std::to_string(turn);
	this->tturn.setString(tmp);

	tmp = "Year: ";
	tmp += std::to_string(year);
	this->tyear.setString(tmp);
}

void Ui::draw(sf::RenderWindow& w)
{
	w.draw(this->vScrollSprite);
	w.draw(this->tgold);
	w.draw(this->tsience);
	w.draw(this->tturn);
	w.draw(this->tyear);
	//	w.draw(this->DownLeftRect);
	//	w.draw(this->DownMiddleRect);
	//	w.draw(this->DownRightRect);
}
