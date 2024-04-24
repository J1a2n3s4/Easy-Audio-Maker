#pragma once
#include <Slider.h>
#include <string>
#include <Header.h>

struct Settings {
	int Volume;
	int BPM;
	std::string Extension;

};

class Options {
public:
	sf::Text ValuesTXT[2];
	int Volume;
	sf::Font czc;
	std::string Ext;
	Options(struct Settings);
	void Accept(struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK);
	void Cancel(struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK);
	void Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Vector2f WinSize);
};




