#include "Footer.h"



Footer::Footer()
{
	BG.setFillColor(sf::Color(20, 20, 20));
	BG.setOutlineColor(sf::Color(200, 200, 200));
	BG.setOutlineThickness(2);
	size.x = 1000;
	size.y = 100;
	BG.setSize(sf::Vector2f(1000,100));
	BG.setPosition(0,1000);
}

void Footer::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Vector2f WinSize)
{
	BG.setScale(1000/WinSize.x,1000/WinSize.y);
	BG.setOrigin(0,size.y/WinSize.y);
	WSK->draw(BG);
}
