#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Slider {
private:
	float Max;
	sf::Font czc;
	sf::RectangleShape Track;
	sf::Sprite Pick;
	sf::Texture PickTexture;
	sf::Text name;
	float value;
	float X;
	float Y;
public:
	void setPos(float x, float y);
	void setValues(float val, float max);
	float getValue();
	Slider(std::string Name,float Procent, float xPos, float yPos,float Max, sf::Vector2f size);
	void Process(sf::RenderWindow * WSK, sf::Vector2i MousePos, sf::Vector2f WinSize);
};

class MoveSlider {
private:
	float Max;
	sf::Font czc;
	sf::RectangleShape Track;
	sf::Sprite Pick;
	sf::Texture PickTexture;
	sf::Text name;
	float value;
	float X;
	float Y;
public:

	void setValues(float val, float max);
	float getValue();
	MoveSlider(std::string Name, float val, float xPos, float yPos, float max);
	void Process(sf::RenderWindow* WSK, sf::Vector2i MousePos, sf::Vector2f WinSize);
};