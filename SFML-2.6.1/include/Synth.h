#pragma once
#include <Checkbox.h>
#include <Button.h>

class SynthTab {
public:
	void process(sf::RenderWindow* WSK, sf::Vector2f WinSize, sf::Vector2i Mouse);
	SynthTab();
private:
	sf::Font czc;
	sf::Sprite OscShapes[3];
	sf::Text OscTexts[3];
	sf::Texture Square;
	sf::Texture Triangle;
	sf::Texture Sine;
	sf::RectangleShape BG;
	sf::Texture * ShapeChose[3] = {&Sine,&Sine,&Sine};
	void CheckBoxes(sf::Vector2i Mouse);
};