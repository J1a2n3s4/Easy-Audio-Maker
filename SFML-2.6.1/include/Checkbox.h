#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Checkbox {
public:
	Checkbox(std::string path, std::string name, int X, int Y);
	bool checkCol(sf::Vector2i Mouse);
	void Process(sf::Vector2f WinSize,sf::RenderWindow * WSK);
private:
	bool active;
	int x;
	int y;
	sf::Texture tex;
	sf::Font czc;
	sf::RectangleShape Rect;
	sf::Text text;
	sf::Sprite Icon;
	sf::Vector2f Size;
};

class SingleCheckboxContainer {
public:
	sf::RectangleShape BG;
	int chosenBoxID;
	void Process(sf::Vector2i Mouse, sf::Vector2f WinSize, sf::RenderWindow * WSK);
	SingleCheckboxContainer();

};