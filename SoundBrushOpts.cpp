#include "SoundBrushOpts.h"
#include <Presets.h>
#include <iostream>

presets * CurrPreset;

Slider VolumeSL("Volume: ", 100, 120, 200, 100, sf::Vector2f(100, 10));
Slider AttackSL("Attack: ", 0.0, 120, 300, 100, sf::Vector2f(100, 10));
Slider DecaySL("Decay: ", 0.0, 120, 400, 100, sf::Vector2f(100, 10));
Slider LengthSL("Length: ", 0., 120, 500, 200, sf::Vector2f(100, 10));
Slider PitchSL("Pitch: ", 1, 120, 600, 100, sf::Vector2f(100, 10));

void BrushOPTS::Process(sf::Vector2f WinSize, sf::RenderWindow* WSK, sf::Event EV, sf::Vector2i Mouse)
{
	IDText.setString("PRESET "+std::to_string(chosenID));

	BG.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	BG.setSize(sf::Vector2f(size.x, 1000000/WinSize.y));
	BG.setPosition(X,0);
	WSK->draw(BG);

	IDText.setPosition(10,80);

	WSK->draw(IDText);




	ValuesTXT[0].setString(std::to_string(Volume).substr(0,5));
	ValuesTXT[1].setString(std::to_string(Attack).substr(0, 5));
	ValuesTXT[2].setString(std::to_string(Decay).substr(0, 5));
	ValuesTXT[3].setString(std::to_string(soundLength).substr(0, 5));
	ValuesTXT[4].setString(std::to_string(Pitch).substr(0, 5));

	if (open) {
		VolumeSL.Process(WSK, Mouse, WinSize);
		AttackSL.Process(WSK, Mouse, WinSize);
		PitchSL.Process(WSK, Mouse, WinSize);
		DecaySL.Process(WSK, Mouse, WinSize);
		LengthSL.Process(WSK, Mouse, WinSize);
		CurrPreset->Volume = VolumeSL.getValue();
		CurrPreset->AttackTime = AttackSL.getValue();
		CurrPreset->Pitch = PitchSL.getValue();
		CurrPreset->Length = LengthSL.getValue();
		CurrPreset->DecayTime = DecaySL.getValue();
	}

	for (int i = 0; i < 5; i++) {
		ValuesTXT[i].setPosition(250 * (1000 / WinSize.x), (i * 100 + 200) * (1000 / WinSize.y));
		ValuesTXT[i].setScale(1000 / WinSize.x, 1000 / WinSize.y);
		WSK->draw(ValuesTXT[i]);
	}
}

BrushOPTS::BrushOPTS()
{
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	for (int i = 0; i < 5; i++) {
		ValuesTXT[i].setCharacterSize(12);
		ValuesTXT[i].setFont(czc);
		ValuesTXT[i].setOrigin(0,6);
	}
	IDText.setCharacterSize(48);
	IDText.setFont(czc);
	IDText.setOrigin(0, 24);
	Attack = 0.0;
	Decay = 0.0;
	Volume = 0.0;
	soundLength = 0.0;
	Left = 0.0;
	Pitch = 1.0;
	BG.setOutlineColor(sf::Color(200, 200, 200));
	BG.setOutlineThickness(1);
	BG.setFillColor(sf::Color(30,30,90));
	Sample.setLoop(true);
	type = true;
	Volume = 0;
	soundLength = 0;
	SoundVisionTexture.loadFromFile("Assets/NoSoundPresetTexture.png");
	X = 1;
	Y = 40;
	size.x = 302;
	size.y = 860;
	BG.setSize(size);
	type = true;

}

void BrushOPTS::OpenPreset(presets* startPreset, int id)
{
	chosenID = id;
	VolumeSL.setValues(startPreset->Volume, 100.0);
	AttackSL.setValues(startPreset->AttackTime, startPreset->Length/2);
	DecaySL.setValues(startPreset->DecayTime, startPreset->Length/2);
	PitchSL.setValues(startPreset->Pitch, 10);
	LengthSL.setValues(startPreset->Length, startPreset->Length);
	CurrPreset = startPreset;
	open = true;
}
