#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <Button.h>

class Checkbox {
public:
	void setPosition(int xpos, int ypos);
	Checkbox(std::string path, std::string name, int X, int Y);
	bool checkCol(sf::Vector2i Mouse);
	void Process(sf::Vector2f WinSize,sf::RenderWindow * WSK);
	int y;
	bool active;
private:
	
	int x;
	
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

class CheckboxPreset {
public:
	sf::Text text;
	sf::Font czc;
	void setPosition(int xpos, int ypos);
	CheckboxPreset(std::string name, int X, int Y, sf::Font* czc);
	bool checkCol(sf::Vector2i Mouse);
	void Process(sf::Vector2f WinSize, sf::RenderWindow* WSK);
	int y;
	bool active;
private:

	int x;
	
	sf::RectangleShape Rect;

	sf::Vector2f Size;
};

class PresetsContainer {
public:
	sf::Font czcionkaMAIN;
	void addPreset();
	sf::RectangleShape BG;
	int chosenPresetID;
	void Process(sf::Vector2i Mouse, sf::Vector2f WinSize, sf::RenderWindow* WSK);
	PresetsContainer();
	std::vector<CheckboxPreset> Presets;
	sf::RectangleShape SelectOutline;

};