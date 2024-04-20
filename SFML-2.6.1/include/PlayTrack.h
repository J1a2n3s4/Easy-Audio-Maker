#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Node.h>

class PlayTrack {
public:
	void Start();
	void Continue();
	void Stop();
	void changeTime();
private:
	sf::RectangleShape Grid[300][6];
	std::vector<SoundNode> Sounds;
	sf::Sprite CurrTimeLine;
};