#pragma once
#include <SFML/Graphics.hpp>
#include <Button.h>

class Footer {
public:
	Footer();
	void Process(sf::RenderWindow* WSK, sf::Vector2i Mouse,sf::Vector2f WinSize);
private:
	sf::RectangleShape BG;
	sf::Vector2f size;
};

