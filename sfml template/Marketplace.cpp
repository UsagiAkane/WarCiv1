#include "Marketplace.h"

Marketplace::Marketplace() :Building("Marketplace", 80, 320, 4, 0, 0, 2, 1, 0) {
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("BuildingsIcons\\Marketplace.png");
	sprite_.setTexture(*texture);
}

bool Marketplace::isBuildable(std::vector<Technologies> techno) {
	std::for_each(techno.begin(), techno.end(), [](Technologies tech) { return tech.get_name() == "Currency" && tech.get_is_learned() == true ? true : false; });
}