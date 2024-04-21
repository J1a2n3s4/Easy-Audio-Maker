#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Node.h>
#include <Button.h>

class PlayTrack {
public:
	PlayTrack();
	void Start();
	void Continue();
	void Stop();
	float time;
	void Process(sf::RenderWindow * WSK, sf::Vector2i Mouse);

private:
	sf::RectangleShape Grid[300][6];
	std::vector<SoundNode> Sounds;
	sf::Sprite CurrTimeLine;
	bool checkCol(sf::Vector2i Mouse);
	void checkSound();
	sf::Texture LineTex;
};