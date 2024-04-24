#include "SoundBrushOpts.h"
#include <iostream>



Slider VolumeSL("Volume: ", 100, 120, 200, 100, sf::Vector2f(100, 10));
Slider AttackSL("Attack: ", 0.0, 120, 300, 100, sf::Vector2f(100, 10));
Slider DecaySL("Decay: ", 0.0, 120, 400, 100, sf::Vector2f(100, 10));
Slider LengthSL("Length: ", 0., 120, 500, 200, sf::Vector2f(100, 10));
Slider PitchSL("Pitch: ", 1, 120, 600, 100, sf::Vector2f(100, 10));

void BrushOPTS::Process(sf::Vector2f WinSize, sf::RenderWindow* WSK, sf::Event EV, sf::Vector2i Mouse)
{
	switch (type) {
	case true:
		if (!Sample.getLoop()) {
			
		}
		else {

		}
		break;
	case false:

		break;
	}
	SoundVision.setTexture(SoundVisionTexture);
	SoundVision.setPosition(2000/WinSize.x, 40000/WinSize.y);
	SoundVision.setScale(1000/WinSize.x, 1000 / WinSize.y);
	BG.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	BG.setSize(sf::Vector2f(size.x, 1000000/WinSize.y));
	BG.setPosition(X,0);
	WSK->draw(BG);
	WSK->draw(SoundVision);


	ValuesTXT[0].setString(std::to_string(Volume).substr(0,3));
	ValuesTXT[1].setString(std::to_string(Attack).substr(0, 2));
	ValuesTXT[2].setString(std::to_string(Decay).substr(0, 2));
	ValuesTXT[3].setString(std::to_string(soundLength).substr(0, 2));
	ValuesTXT[4].setString(std::to_string(Pitch).substr(0, 2));



	if (open) {
		VolumeSL.Process(WSK, Mouse, WinSize);
		AttackSL.Process(WSK, Mouse, WinSize);
		PitchSL.Process(WSK, Mouse, WinSize);
		DecaySL.Process(WSK, Mouse, WinSize);
		LengthSL.Process(WSK, Mouse, WinSize);
		Volume = VolumeSL.getValue();
		Attack = AttackSL.getValue();
		Pitch = PitchSL.getValue();
		soundLength = LengthSL.getValue();
	}

	for (int i = 0; i < 5; i++) {
		ValuesTXT[i].setPosition(250 * (1000 / WinSize.x), (i * 100 + 200) * (1000 / WinSize.x));
		
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
	Attack = 0.0;
	Decay = 0.0;
	Volume = 0.0;
	soundLength = 0.0;
	Left = 0.0;
	Pitch = 1.0;
	BG.setOutlineColor(sf::Color(200, 200, 200));
	BG.setOutlineThickness(1);
	BG.setFillColor(sf::Color(25,25,75));
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

void BrushOPTS::SavePreset(int id)
{

}

void BrushOPTS::GetPreset()
{

}

void BrushOPTS::OpenPreset(presets* startPreset)
{
	VolumeSL.setValues(startPreset->Volume, 100.0);
	AttackSL.setValues(startPreset->AttackTime, startPreset->Length/2);
	DecaySL.setValues(startPreset->DecayTime, startPreset->Length/2);
	PitchSL.setValues(startPreset->Pitch, 10);
	LengthSL.setValues(startPreset->Length, startPreset->Length);
	open = true;
}
