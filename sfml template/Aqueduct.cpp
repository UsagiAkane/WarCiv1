#include "Aqueduct.h"

Aqueduct::Aqueduct() : Building("Aqueduct", 120, 480, 2, 20, 0, 0, 0, 0) {
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("BuildingsIcons\\Aqueduct.png");
	sprite_.setTexture(*texture);
}

bool Aqueduct::isBuildable(std::vector<Technologies> techno) {
	std::for_each(techno.begin(), techno.end(), [](Technologies tech) { return tech.get_name() == "Construction" && tech.get_is_learned() == true ? true : false; });
}