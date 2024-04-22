#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Node.h>
#include <Button.h>
#include <Presets.h>

class PlayTrack {
public:
	presets CurrPreset;
	float x = 303;
	float y = 41;
	void setBPM(int bpm);
	PlayTrack(presets preset);
	void Start();
	void Continue();
	void Stop();
	float time;
	void Process(sf::RenderWindow * WSK, sf::Vector2i Mouse, sf::Time delta);

private: 
	sf::Vector2f size;
	int BPM = 60;
	bool playing = false;
	sf::RectangleShape Grid[300][6];
	std::vector<SoundNode> Sounds;
	sf::Sprite CurrTimeLine;
	void checkCol(sf::Vector2i Mouse);
	void checkSound();
	sf::Texture LineTex;
};