#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Header.h>
#include <Options.h>

class Button {
protected:
	int x;
	int y;
	sf::Vector2f size;
	bool checkCol(sf::Vector2i Mouse);
	void Render(sf::RenderWindow* WSK);

public:
	sf::Font czc;
	sf::Text text;
	sf::RectangleShape Visual;
	void Process(sf::Vector2i Mouse, sf::Vector2f Win, sf::RenderWindow* WSK, sf::Event Ev);
	Button();

};

class ButtonHeader : Button {
protected:
	int x;
	int y;
	sf::Vector2f size;
	
public:
	sf::Font czc;
	sf::Text text;
	sf::RectangleShape Visual;
	bool checkCol(sf::Vector2i Mouse);
	void Render(sf::RenderWindow* WSK);
	ButtonHeader(sf::Vector2f size, int x, int y, std::string str, Header * ParentWSK);
	void Process(sf::Vector2i Mouse, sf::Vector2f Win, sf::RenderWindow* WSK, sf::Event Ev);

};


class ButtonOptions : Button {
protected:
	int x;
	int y;
	sf::Vector2f size;
public:
	sf::Font czc;
	sf::Text text;
	sf::RectangleShape Visual;
	bool checkCol(sf::Vector2i Mouse);
	void Render(sf::RenderWindow* WSK);
	ButtonOptions(sf::Vector2f size, int x, int y, std::string str, Options * ParentWSK);
	void Process(sf::Vector2i Mouse, sf::Vector2f Win, sf::RenderWindow* WSK, sf::Event Ev, struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK);

};