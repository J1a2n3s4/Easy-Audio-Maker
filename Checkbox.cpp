#include "Checkbox.h"
#include <iostream>

Checkbox Add("Assets/Plus.png", "Add", 320, 100);
Checkbox Edit("Assets/Edit.png", "Edit", 370, 100);
Checkbox Delete("Assets/X.png", "Delete", 420, 100);
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
			std::cout << "add mode ON\n";
		}else if (Edit.checkCol(Mouse)) {
			chosenBoxID = 1;
			std::cout << "edit mode ON\n";
		}
		else if (Delete.checkCol(Mouse)) {
			chosenBoxID = 2;
			std::cout << "delete mode ON\n";
		}
		else if (Move.checkCol(Mouse)) {
			chosenBoxID = 3;
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
