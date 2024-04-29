#include "Node.h"
#include <iostream>

bool SoundNode::checkCol(sf::Vector2i Mouse,float TrackPos)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > Vis.getPosition().x) {
		if (Mouse.x < Vis.getPosition().x + Length*30) {
			xCol = true;
		}
	}
	if (Mouse.y < Vis.getPosition().y) {
		if (Mouse.y > Vis.getPosition().y - 50) {
			yCol = true;
		}
	}
	if (xCol and yCol) {
		return true;
	}
	else {
		return false;
	}
}

SoundNode::SoundNode(int X, int Y, float Vol, float Att, float Dec,float len, float Pit)
{
	Pos = X;
	OctavePos = Y;
	Volume = Vol;
	Attack = Att;
	Decay = Dec;
	Pitch = Pit;
	Length = len;
	std::cout << "pos " << X;

	Vis.setSize(sf::Vector2f(Length*30,25));
	Vis.setFillColor(sf::Color(30, 30, 90));
	Vis.setOutlineThickness(1);
	Vis.setOutlineColor(sf::Color(15, 15, 45));
	Vis.setOrigin(0,25);
}
