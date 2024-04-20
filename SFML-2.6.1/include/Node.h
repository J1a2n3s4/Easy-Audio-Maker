#pragma once
#include <Presets.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class SoundNode {
public:
	int Pos;
	int OctavePos;
	sf::Sound Playable;
	sf::SoundBuffer Sound;
	float Volume;
	float Attack;
	float Decay;
	float Pitch;
	float Left;
	float Length;
	SoundNode(int X, int Y, std::string Sample,float Volume,float Attack,float Decay,float Left,float Length, float Pitch);
};