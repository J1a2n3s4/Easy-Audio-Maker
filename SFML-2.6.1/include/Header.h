#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Header {
private:
	Header* SELFWSK;
	sf::RectangleShape Visual;
	sf::RectangleShape OptsBG;
public:
	bool SettingsOpened = false;
	bool OptsVisible = false;
	void ToggleOpts();
	void Process(sf::Vector2f Win, sf::RenderWindow* WSK, sf::Vector2i Mouse,sf::Event Ev);
	Header();
	void OpenWin(std::string name);
};