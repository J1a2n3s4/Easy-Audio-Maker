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
	Sound.loadFromFile(Sample);
	Vis.setSize(sf::Vector2f(Length,100));


}
