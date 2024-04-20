#include "Options.h"

const int ValuesLen = 2;

Slider BPMSlider("BPM: ",60,150,100,300, sf::Vector2f(300, 10));
Slider VolumeSlider("Volume: ",100,150,200,100,sf::Vector2f(300,10));



void Options::Accept(struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK)
{
	WSKLAST->BPM = BPMSlider.getValue();
	WSKLAST->Extension = Ext;
	WSKLAST->Volume = Volume;
	HWSK->SettingsOpened = false;
}

void Options::Cancel(struct Settings* WSKCH, struct Settings* WSKLAST, Header* HWSK)
{
	BPMSlider.setValues(WSKLAST->BPM, 300);
	VolumeSlider.setValues(WSKLAST->Volume, 100);
	WSKCH->Extension = WSKLAST->Extension;
	HWSK->SettingsOpened = false;
}

void Options::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Vector2f WinSize)
{
	ValuesTXT[0].setString(std::to_string(BPMSlider.getValue()));
	ValuesTXT[1].setString(std::to_string(VolumeSlider.getValue()));
	BPMSlider.Process(WSK, Mouse, WinSize);
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
	BPM = set.BPM;
	Ext = set.Extension;
	Volume = set.Volume;

}

