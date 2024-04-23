#pragma once
#include <SFML/Graphics.hpp>
#include <Checkbox.h>

class editHeader {
private:

	sf::Text timeTXT;
	SingleCheckboxContainer Checks;
	sf::Font czc;

public:
	void Process(sf::Vector2i Mouse, sf::Vector2f WinSize, sf::RenderWindow* WSK, float time);
	editHeader();
};

