#include "VolumeGraph.h"

void VolumeGraph::Process(sf::RenderWindow* WSK, sf::Vector2f WinSize, float Volume, float attack, float release,float Length)
{

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			Grid[i][j].setScale(1000 / WinSize.x, 1000 / WinSize.y);
			Grid[i][j].setPosition((i * 10 + x) * (1000 / WinSize.x), (j * 10 + y - 3) * (1000 / WinSize.y));

			WSK->draw(Grid[i][j]);
		}
	}

	//ustawienie lini maksymalnej glosnosci 
	MaxVolume.setPoint(0, sf::Vector2f(x + attack/Length* 200 - 50, sizeY - Volume - 3));
	MaxVolume.setPoint(3, sf::Vector2f(x + attack/Length* 200 - 50, sizeY - Volume - 5));
	MaxVolume.setPoint(1, sf::Vector2f(x + sizeX - release/Length* 200 - 50, sizeY - Volume - 3));
	MaxVolume.setPoint(2, sf::Vector2f(x + sizeX - release/Length* 200 - 50, sizeY - Volume - 5));
	// ustawienie ataku
	Attack.setPoint(0, sf::Vector2f(x - 50,sizeY-3));
	Attack.setPoint(1, sf::Vector2f(x - 50,sizeY));
	Attack.setPoint(3, sf::Vector2f(x + attack / Length * 200 - 50, sizeY - Volume - 3));
	Attack.setPoint(2, sf::Vector2f(x + attack / Length * 200 - 50, sizeY - Volume - 5));
	// ustawienie odejscia
	Release.setPoint(0, sf::Vector2f(x + sizeX - release / Length * 200 - 50, sizeY - Volume - 3) );
	Release.setPoint(1, sf::Vector2f(x + sizeX - release / Length * 200 - 50, sizeY - Volume - 5));
	Release.setPoint(2, sf::Vector2f(x + sizeX - 50, sizeY - 3));
	Release.setPoint(3, sf::Vector2f(x + sizeX - 50, sizeY));

	Attack.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	MaxVolume.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	Release.setScale(1000 / WinSize.x, 1000 / WinSize.y);

	Attack.setPosition(x * (1000 / WinSize.x), y * (1000 / WinSize.y));
	MaxVolume.setPosition(x * (1000 / WinSize.x), y * (1000 / WinSize.y));
	Release.setPosition(x * (1000 / WinSize.x), y * (1000 / WinSize.y));

	if (attack > 0) {
		WSK->draw(Attack);
	}
	if (release > 0) {
		WSK->draw(Release);
	}
	WSK->draw(MaxVolume);
	
}


VolumeGraph::VolumeGraph() {
	Attack.setFillColor(sf::Color(200, 200, 200));
	Release.setFillColor(sf::Color(200, 200, 200));
	MaxVolume.setFillColor(sf::Color(200, 200, 200));
	Attack.setPointCount(4);
	Release.setPointCount(4);
	MaxVolume.setPointCount(4);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			Grid[i][j].setSize(sf::Vector2f(10,10));
			Grid[i][j].setOutlineColor(sf::Color(100, 100, 100));
			Grid[i][j].setOutlineThickness(1);
			Grid[i][j].setFillColor(sf::Color(20, 20, 80));

		}
	}
}