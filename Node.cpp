#include "Node.h"

SoundNode::SoundNode(int X, int Y, std::string Sample, float Vol, float Att, float Dec, float Le,float len, float Pit)
{
	Pos = X;
	OctavePos = Y;
	Volume = Vol;
	Attack = Att;
	Decay = Dec;
	Pitch = Pit;
	Left = Le;
	Length = len;
	
	Vis.setSize(sf::Vector2f(Length*30,25));
	Vis.setFillColor(sf::Color(30, 30, 90));
	Vis.setOutlineThickness(1);
	Vis.setOutlineColor(sf::Color(15, 15, 45));
	Sound.loadFromFile(Sample);
	Vis.setOrigin(0,25);
}
