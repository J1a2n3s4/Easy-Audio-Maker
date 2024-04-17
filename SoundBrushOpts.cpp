#include "SoundBrushOpts.h"

Slider VolumeSL;
Slider AttackSL;
Slider DecaySL;
Slider LengthSL;
Slider PitchSL;
Slider LeftSL;


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
	SoundVision.setPosition(1000/WinSize.x, 40000/WinSize.y);
	SoundVision.setScale(1000/WinSize.x, 1000 / WinSize.y);
	BG.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	BG.setPosition(X, Y * (1000 / WinSize.y));
	WSK->draw(BG);
	WSK->draw(SoundVision);

	if (open) {
		VolumeSL.Process(WSK, Mouse);
		AttackSL.Process(WSK, Mouse);
		PitchSL.Process(WSK, Mouse);
		DecaySL.Process(WSK, Mouse);
		LengthSL.Process(WSK, Mouse);
		LeftSL.Process(WSK, Mouse);
	}
}

BrushOPTS::BrushOPTS()
{
	
	BG.setSize(size);
	BG.setOutlineColor(sf::Color(200, 200, 200));
	BG.setOutlineThickness(1);
	BG.setFillColor(sf::Color(25,25,75));
	Sample.setLoop(true);
	type = true;
	Volume = 0;
	soundLength = 0;
	SoundVisionTexture.loadFromFile("Assets/NoSoundPresetTexture.png");
	X = 0;
	Y = 125;
	size.x = 302;
	size.y = 775;
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
	VolumeSL = Slider("Volume",100,0,50,100);
	AttackSL = Slider("Volume",0.0,0,50,startPreset->Length);
	DecaySL = Slider("Volume",0.0,0,50, startPreset->Length);
	LengthSL = Slider("Volume",100,0,50, startPreset->Length);
	PitchSL = Slider("Volume",1,0,50,10);
	LeftSL = Slider("Volume",50,0,50,100);
	preset = startPreset;
	open = true;
}
