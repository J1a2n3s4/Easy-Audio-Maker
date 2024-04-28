#pragma once
#include <SFML/Graphics.hpp>

class VolumeGraph {
public:
	void Process(sf::RenderWindow * WSK, sf::Vector2f WinSize,float Volume,float Attack, float Release, float Length);
	VolumeGraph();
	const float x = 50;
	const float y = 200;
	const float sizeX = 200;
	const float sizeY = 100;
private:
	sf::RectangleShape Grid[20][10];
	sf::ConvexShape Attack;
	sf::ConvexShape Release;
	sf::ConvexShape MaxVolume;


};