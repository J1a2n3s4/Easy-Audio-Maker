#include "SoundBrushOpts.h"


Slider VolumeSL("Volume: ", 100, 150, 200, 100, sf::Vector2f(100, 10));
Slider AttackSL("Attack: ", 0.0, 150, 300, 100, sf::Vector2f(100, 10));
Slider DecaySL("Decay: ", 0.0, 150, 400, 100, sf::Vector2f(100, 10));
Slider LengthSL("Length: ", 0., 150, 500, 200, sf::Vector2f(100, 10));
Slider PitchSL("Pitch: ", 1, 150, 600, 100, sf::Vector2f(100, 10));
Slider LeftSL("Left: ", 50, 150, 700, 100, sf::Vector2f(100, 10));

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

	if (open) {
		VolumeSL.Process(WSK, Mouse, WinSize);
		AttackSL.Process(WSK, Mouse, WinSize);
		PitchSL.Process(WSK, Mouse, WinSize);
		DecaySL.Process(WSK, Mouse, WinSize);
		LengthSL.Process(WSK, Mouse, WinSize);
		LeftSL.Process(WSK, Mouse, WinSize);
		Volume = VolumeSL.getValue();
		Attack = AttackSL.getValue();
		Pitch = PitchSL.getValue();
		Left = LeftSL.getValue();
		soundLength = LengthSL.getValue();
	}
}

BrushOPTS::BrushOPTS()
{
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
	LeftSL.setValues(startPreset->Left, 100);
	LengthSL.setValues(startPreset->Length, startPreset->Length);
	open = true;
}
