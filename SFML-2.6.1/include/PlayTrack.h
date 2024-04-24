#pragma once
#include <SFML/Graphics.hpp>
#include <list>
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
	void Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Time delta, sf::Vector2f WinSize);
	float time;

private: 
	sf::Vector2f size;
	int BPM = 60;
	bool playing = true;
	sf::RectangleShape Grid[300][20];
	std::list<SoundNode> Sounds;
	sf::Sprite CurrTimeLine;
	void checkCol(sf::Vector2i Mouse);
	void checkSound();
	sf::Texture LineTex;
};