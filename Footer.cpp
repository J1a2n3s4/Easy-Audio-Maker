#include "Footer.h"
#include <iostream>


Footer::Footer()
{
	BG.setFillColor(sf::Color(50, 50, 50));
	BG.setOutlineColor(sf::Color(200, 200, 200));
	BG.setOutlineThickness(1);
	size.x = 1000;
	size.y = 200;
	BG.setSize(sf::Vector2f(1000,100));
	BG.setPosition(0,1000);
}

void Footer::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Vector2f WinSize)
{
	BG.setPosition(1,WinSize.y);
	BG.setScale(999/WinSize.x,1000/WinSize.y);
	BG.setSize(sf::Vector2f(WinSize.x-2,100));
	BG.setOrigin(0,size.y*(1000/WinSize.y)/2);
	WSK->draw(BG);
}
