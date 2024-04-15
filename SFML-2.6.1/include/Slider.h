#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Slider {
private:
	sf::Font czc;
	sf::RectangleShape Track;
	sf::Sprite Pick;
	sf::Texture PickTexture;
	sf::Text name;
	int value;
	float X;
	float Y;
public:
	int getValue();
	Slider(std::string Name,float Procent, float xPos, float yPos,float Max);
	void Process(sf::RenderWindow * WSK, sf::Vector2i MosuePos);
};