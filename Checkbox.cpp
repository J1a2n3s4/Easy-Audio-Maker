#include "Checkbox.h"
#include <iostream>
#include <cmath>

bool click2 = false;



Button AddButton(5,918,"+",sf::Vector2f(20,20));

Checkbox Add("Assets/Plus.png", "Add", 320, 100);
Checkbox Edit("Assets/Edit.png", "Edit", 365, 100);
Checkbox Delete("Assets/X.png", "Delete", 410, 100);
Checkbox Move("Assets/Move.png", "Move", 470, 100);

void Checkbox::setPosition(int xpos, int ypos)
{
	x = xpos;
	y = ypos;
}

Checkbox::Checkbox(std::string path, std::string name, int X, int Y)
{
	tex.loadFromFile(path);
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	Icon.setTexture(tex);
	text.setFont(czc);
	text.setCharacterSize(12);
	text.setString(name);
	Size.x = text.getLocalBounds().width + 16;
	Size.y = 16;
	Rect.setSize(Size);
	x = X;
	y = Y;
	active = false;
	Rect.setFillColor(sf::Color(10, 10, 10));
	Rect.setOutlineColor(sf::Color(200, 200, 200));
	Rect.setOutlineThickness(1);
}



bool Checkbox::checkCol(sf::Vector2i Mouse)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > x) {
		if (Mouse.x < x + Size.x) {
			xCol = true;
		}
	}
	if (Mouse.y > y) {
		if (Mouse.y < y + Size.y) {
			yCol = true;
		}
	}


	if (xCol and yCol) {
		return true;
	}
	else {
		return false;
	}
}

void Checkbox::Process(sf::Vector2f WinSize, sf::RenderWindow * WSK)
{
	text.setPosition((x + 14)* (1000 / WinSize.x), (y+2) * (1000 / WinSize.y));
	Icon.setPosition((x + 2)* (1000 / WinSize.x), (y+2) * (1000 / WinSize.y));
	Rect.setPosition(x * (1000 / WinSize.x), y * (1000 / WinSize.y));

	text.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	Icon.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	Rect.setScale(1000 / WinSize.x, 1000 / WinSize.y);

	if (active) {
		Rect.setOutlineThickness(2);
		Rect.setFillColor(sf::Color(30, 30, 30));
	}
	else {
		Rect.setFillColor(sf::Color(10, 10, 10));
		Rect.setOutlineThickness(1);
	}
	
	WSK->draw(Rect);
	WSK->draw(Icon);
	WSK->draw(text);

}

void SingleCheckboxContainer::Process(sf::Vector2i Mouse, sf::Vector2f WinSize, sf::RenderWindow* WSK)
{
	Add.Process(WinSize,WSK);
	Edit.Process(WinSize,WSK);
	Delete.Process(WinSize,WSK);
	Move.Process(WinSize,WSK);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (Add.checkCol(Mouse)) {
			chosenBoxID = 0;
			Add.active = true;
			Edit.active = false;
			Delete.active = false;
			Move.active = false;
			std::cout << "add mode ON\n";

		}else if (Edit.checkCol(Mouse)) {
			chosenBoxID = 1;
			Edit.active = true;
			Add.active = false;
			Delete.active = false;
			Move.active = false;
			std::cout << "edit mode ON\n";
		}
		else if (Delete.checkCol(Mouse)) {
			chosenBoxID = 2;
			Delete.active = true;
			Edit.active = false;
			Add.active = false;
			Move.active = false;
			std::cout << "delete mode ON\n";
		}
		else if (Move.checkCol(Mouse)) {
			chosenBoxID = 3;	
			Edit.active = false;
			Add.active = false;
			Delete.active = false;
			Move.active = true;
			std::cout << "move mode ON\n";
		}

	}
}

SingleCheckboxContainer::SingleCheckboxContainer()
{
	chosenBoxID = 0;
	BG.setSize(sf::Vector2f(1000, 100));
	BG.setPosition(303, 40);
}

void CheckboxPreset::setPosition(int xpos, int ypos)
{
	x = xpos;
	y = ypos;
}

CheckboxPreset::CheckboxPreset(std::string name, int X, int Y, sf::Font * czc)
{
	
	text.setCharacterSize(12);
	text.setFont(*czc);
	text.setString(name);
	text.setOutlineColor(sf::Color(0, 100, 100));
	text.setOutlineThickness(1);
	Size.x = name.length() * 8 + 12;
	Size.y = 16;
	Rect.setSize(Size);
	x = X;
	y = Y;
	active = false;
	Rect.setFillColor(sf::Color(10, 10, 10));
	Rect.setOutlineColor(sf::Color(200, 200, 200));
	Rect.setOutlineThickness(1);
}

bool CheckboxPreset::checkCol(sf::Vector2i Mouse)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > x) {
		if (Mouse.x < x + Size.x) {
			xCol = true;
		}
	}
	if (Mouse.y > y) {
		if (Mouse.y < y + Size.y) {
			yCol = true;
		}
	}
	if (xCol and yCol) {
		return true;
	}
	else {
		return false;
	}
}

void CheckboxPreset::Process(sf::Vector2f WinSize, sf::RenderWindow* WSK)
{
	text.setPosition(x * (1000 / WinSize.x), (y + 2) * (1000 / WinSize.y));
	Rect.setPosition(x * (1000 / WinSize.x), y * (1000 / WinSize.y));

	text.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	Rect.setScale(1000 / WinSize.x, 1000 / WinSize.y);

	if (active) {
		Rect.setOutlineThickness(2);
		Rect.setFillColor(sf::Color(30, 30, 30));
	}
	else {
		Rect.setFillColor(sf::Color(10, 10, 10));
		Rect.setOutlineThickness(1);
	}

	WSK->draw(Rect);
	WSK->draw(text);
}

void PresetsContainer::addPreset()
{
	if (Presets.size() < 12) {
		Presets.push_back(CheckboxPreset("PRESET " + std::to_string(Presets.size()), 30 + 90 * Presets.size(), 920,&czcionkaMAIN));
	}

}

void PresetsContainer::Process(sf::Vector2i Mouse, sf::Vector2f WinSize, sf::RenderWindow* WSK)
{
	AddButton.Process(Mouse,WinSize,WSK);
	for (int i = 0; i < Presets.size(); i++) {
		
		Presets[i].Process(WinSize, WSK);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			
			if (Presets[i].checkCol(Mouse)) {
					chosenPresetID = i;
					for (int j = 0; j < Presets.size(); j++) {
						Presets[j].active = false;
					}
					Presets[i].active = true;
			}
		}
		
		
	}
	if (Presets.size() * 90 + 10 > WinSize.x) {
		for (int i = 0; i < std::ceil(Presets.size()/2); i++) {
			Presets[i + std::ceil(Presets.size() / 2)].setPosition((i*90+30),950);
		}
	}
	else {
		for (int i = 0; i < std::ceil(Presets.size() / 2); i++) {
			Presets[i].setPosition(i * 90 + 30, 920);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!click2) {
			if (AddButton.checkCol(Mouse)) {
				addPreset();
			}
			click2 = true;
		}

	}
	else {
		click2 = false;
	}

}

PresetsContainer::PresetsContainer()
{
	czcionkaMAIN.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	chosenPresetID = 0;
	SelectOutline.setSize(sf::Vector2f(30, 1));
	SelectOutline.setOutlineColor(sf::Color(70,70,210));
	SelectOutline.setOutlineThickness(1);
	Presets.push_back(CheckboxPreset("PRESET "+std::to_string(Presets.size()),30 + 90 * Presets.size(),920, &czcionkaMAIN));
}
