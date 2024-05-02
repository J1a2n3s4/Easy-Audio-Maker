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
	void Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Time delta, sf::Vector2f WinSize);
	void checkCol(sf::Vector2i Mouse, sf::Vector2f Win);
	std::vector<int> checkSound();
	std::vector<SoundNode> Sounds;
	float time;
	int EditMode;
private: 
	sf::Vector2f size;
	int BPM = 120;
	bool playing = true;
	sf::RectangleShape Grid[300][20];

	sf::Sprite CurrTimeLine;
	
	sf::Texture LineTex;
};