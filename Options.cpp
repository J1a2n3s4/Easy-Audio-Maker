#include "Options.h"

const int ValuesLen = 2;

Slider VolumeSlider("Volume: ",100,150,200,100,sf::Vector2f(300,10));



void Options::Accept(struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK)
{
	WSKLAST->Extension = Ext;
	WSKLAST->Volume = Volume;
	HWSK->SettingsOpened = false;
}

void Options::Cancel(struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK)
{
	VolumeSlider.setValues(WSKLAST->Volume, 100);
	WSKCH->Extension = WSKLAST->Extension;
	HWSK->SettingsOpened = false;
}

void Options::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Vector2f WinSize)
{
	ValuesTXT[1].setString(std::to_string(VolumeSlider.getValue()));
	VolumeSlider.Process(WSK, Mouse, WinSize);
	for (int i = 0; i < ValuesLen; i++) {
		ValuesTXT[i].setOrigin(ValuesTXT[i].getLocalBounds().width, 0);
		WSK->draw(ValuesTXT[i]);
	}
	
	
}



Options::Options(struct Settings set)
{
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	for (int i = 0; i < ValuesLen; i++) {
		ValuesTXT[i].setFont(czc);
		ValuesTXT[i].setOutlineColor(sf::Color(0,100,100));
		ValuesTXT[i].setOutlineThickness(1);
		ValuesTXT[i].setCharacterSize(12);
		ValuesTXT[i].setPosition(550, i * 100 + 100);
	}
	Ext = set.Extension;
	Volume = set.Volume;

}

