#include "Button.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

bool click = false;

Header* WSKH;
Options* WSKO;


bool Button::checkCol(sf::Vector2i Mouse)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > X) {
		if (Mouse.x < X + size.x) {
			xCol = true;
		}
	}
	if (Mouse.y > Y) {
		if (Mouse.y < Y + size.y) {
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

Button::Button(int x, int y, std::string name, sf::Vector2f Size)
{
	
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	text.setCharacterSize(12);
	text.setFont(czc);
	text.setString(name);
	text.setOutlineColor(sf::Color(0, 100, 100));
	text.setOutlineThickness(1);
	X = x;
	Y = y;
	size = Size;
	Visual.setFillColor(sf::Color(20, 20, 20));
	Visual.setOutlineThickness(2.0);
	Visual.setOutlineColor(sf::Color(220, 220, 220));
	Visual.setSize(size);
}

Button::Button() {

}

void Button::Process(sf::Vector2i Mouse, sf::Vector2f Win, sf::RenderWindow* WSK)
{
	Visual.setPosition(X * (1000 / Win.x), Y * (1000 / Win.y));
	Render(WSK);
	text.setPosition(Visual.getPosition().x + Visual.getSize().x * Visual.getScale().x / 2 - text.getLocalBounds().width / 2 * Visual.getScale().x, Visual.getPosition().y + Visual.getSize().y / 2 * Visual.getScale().x - text.getLocalBounds().height / 1.5 * Visual.getScale().x);
	text.setScale(1000 / Win.x, 1000 / Win.y);
	Visual.setScale(1000 / Win.x, 1000 / Win.y);
	if (checkCol(Mouse)) {
		Visual.setFillColor(sf::Color(50, 50, 50));
	}
	else {
		Visual.setFillColor(sf::Color(20, 20, 20));
	}
}

void Button::Render(sf::RenderWindow* WSK)
{
	WSK->draw(Visual);
	WSK->draw(text);
}

bool ButtonHeader::checkCol(sf::Vector2i Mouse)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > x) {
		if (Mouse.x < x + size.x) {
			xCol = true;
		}
	}
	if (Mouse.y > y) {
		if (Mouse.y < y + size.y) {
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
bool ButtonOptions::checkCol(sf::Vector2i Mouse)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > x) {
		if (Mouse.x < x + size.x) {
			xCol = true;
		}
	}
	if (Mouse.y > y) {
		if (Mouse.y < y + size.y) {
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




void ButtonHeader::Render(sf::RenderWindow* WSK)
{
	WSK->draw(Visual);
	WSK->draw(text);
}

void ButtonOptions::Render(sf::RenderWindow* WSK)
{
	WSK->draw(Visual);
	WSK->draw(text);
}

ButtonHeader::ButtonHeader(sf::Vector2f size, int x, int y, std::string str, Header* ParentWSK)
{
	WSKH = ParentWSK;
	Visual.setSize(size);
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	text.setCharacterSize(12);
	text.setFont(czc);
	text.setString(str);
	text.setOutlineColor(sf::Color(0, 100, 100));
	text.setOutlineThickness(1);
	this->x = x;
	this->y = y;
	this->size = size;
	Visual.setFillColor(sf::Color(20, 20, 20));
	Visual.setOutlineThickness(2.0);
	Visual.setOutlineColor(sf::Color(220, 220, 220));


}

ButtonOptions::ButtonOptions(sf::Vector2f size, int x, int y, std::string str, Options* ParentWSK)
{
	WSKO = ParentWSK;
	Visual.setSize(size);
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	text.setCharacterSize(12);
	text.setFont(czc);
	text.setString(str);
	text.setOutlineColor(sf::Color(0, 100, 100));
	text.setOutlineThickness(1);
	this->x = x;
	this->y = y;
	this->size = size;
	Visual.setFillColor(sf::Color(20, 20, 20));
	Visual.setOutlineThickness(2.0);
	Visual.setOutlineColor(sf::Color(220, 220, 220));
}




void ButtonHeader::Process(sf::Vector2i Mouse, sf::Vector2f Win,sf::RenderWindow * WSK,sf::Event Ev) {
	Visual.setPosition(ButtonHeader::x * 1000 / Win.x, ButtonHeader::y * 1000 / Win.y);
	Render(WSK);
	text.setPosition(Visual.getPosition().x + Visual.getSize().x * Visual.getScale().x / 2 - text.getLocalBounds().width / 2 * Visual.getScale().x, Visual.getPosition().y + Visual.getSize().y / 2 * Visual.getScale().x - text.getLocalBounds().height / 1.5 * Visual.getScale().x);
	text.setScale(1000 / Win.x, 1000 / Win.y);
	Visual.setScale(1000 / Win.x, 1000 / Win.y);
	if (checkCol(Mouse)) {
		Visual.setFillColor(sf::Color(50, 50, 50));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			if (!click) {
				WSKH->OpenWin(text.getString());
				click = true;
			}
		}
		else {
			click = false;
		}
	}
	else {
		Visual.setFillColor(sf::Color(20, 20, 20));
	}
}

void ButtonOptions::Process(sf::Vector2i Mouse, sf::Vector2f Win, sf::RenderWindow* WSK, sf::Event Ev, struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK) {
	Visual.setPosition(ButtonOptions::x * 1000 / Win.x, ButtonOptions::y * 1000 / Win.y);
	Render(WSK);
	text.setPosition(Visual.getPosition().x + Visual.getSize().x * Visual.getScale().x / 2 - text.getLocalBounds().width / 2 * Visual.getScale().x, Visual.getPosition().y + Visual.getSize().y / 2 * Visual.getScale().x - text.getLocalBounds().height / 1.5 * Visual.getScale().x);
	text.setScale(1000 / Win.x, 1000 / Win.y);
	Visual.setScale(1000 / Win.x, 1000 / Win.y);
	if (checkCol(Mouse)) {
		Visual.setFillColor(sf::Color(50, 50, 50));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (!click) {
				if (text.getString() == "Accept") {
					WSKO->Accept( WSKCH, WSKLAST, HWSK);
				}
				else if (text.getString() == "Cancel") {
					WSKO->Cancel(WSKCH, WSKLAST, HWSK);
				}
			}
		}
		else {
			click = false;
		}
	}
	else {
		Visual.setFillColor(sf::Color(20, 20, 20));
	}
}