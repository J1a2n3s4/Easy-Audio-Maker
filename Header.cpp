#include <Header.h>
#include <SFML/Graphics.hpp>
#include <iostream>






void Header::Process(sf::Vector2f Win, sf::RenderWindow* WSK, sf::Vector2i Mouse,sf::Event Ev)
{
	WSK->draw(Visual);
	OptsBG.setPosition(10 * 1000 / Win.x,42  * 1000 / Win.y);
	OptsBG.setScale(1000/Win.x, 1000 / Win.y);
	if (OptsVisible) {
		WSK->draw(OptsBG);
	}

};


Header::Header()
{



	SELFWSK = this;
	OptsBG.setSize(sf::Vector2f(70, 125));
	Visual.setSize(sf::Vector2f(1000,40));
	Visual.setFillColor(sf::Color(10,10,10));
	OptsBG.setFillColor(sf::Color(20,20,20));
	OptsBG.setOutlineThickness(2);
	OptsBG.setOutlineColor(sf::Color(220,220,220));
}

void Header::ToggleOpts() {
	OptsVisible = !OptsVisible;
}


void Header::OpenWin(std::string name) {
	if (name == "Options") {
		std::cout << "options opened/closed\n";
		SettingsOpened = !SettingsOpened;
	}
	else if (name == "Open") {
		std::cout << "opening files opened\n";
	}
	else if (name == "Save") {
		std::cout << "Saving window opened\n";
	}
	else if (name == "Sound In") {
		std::cout << "importing sound opened\n";
	}
	else if (name == "Export") {
		std::cout << "Exporting opened\n";
	}
	else if (name == "File") {
		std::cout << "File opts opened\n";
		ToggleOpts();
	}
}