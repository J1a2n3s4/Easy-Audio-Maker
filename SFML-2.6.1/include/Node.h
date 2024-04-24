#pragma once
#include <Presets.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class SoundNode {
public:
	int Pos;
	int OctavePos;
	float Volume;
	float Attack;
	float Decay;
	float Pitch;
	float Length;
	bool played = false;
	sf::RectangleShape Vis;
	SoundNode(int X, int Y, float Vol, float Att, float Dec, float len, float Pit);
};