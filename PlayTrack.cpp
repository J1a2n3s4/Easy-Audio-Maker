#include "PlayTrack.h"
#include <cmath>

void PlayTrack::setBPM(int bpm)
{
	BPM = bpm;
}

bool clicked = false;

PlayTrack::PlayTrack(presets preset)
{
	x = 303;
	y = 200;
	CurrPreset = preset;
	size.x = 498;
	size.y = 600;
	LineTex.loadFromFile("Assets/LineStamp.png");
	CurrTimeLine.setTexture(LineTex);
	CurrTimeLine.setOrigin(26, 0);
	time = 0.0f;
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 6; j++) {
			Grid[i][j].setFillColor(sf::Color(30, 30, 30));
			Grid[i][j].setOutlineColor(sf::Color(200, 200, 200));
			Grid[i][j].setOutlineThickness(1);
			Grid[i][j].setSize(sf::Vector2f(2, 100));
			Grid[i][j].setPosition(2*i,100*j);
		}
	}
}

void PlayTrack::Start()
{
	for (int i = 0; i < Sounds.size(); i++) {
		Sounds[i].played = false;

	}
	playing = true;
	time = 0;
}

void PlayTrack::Continue()
{
	playing = true;
}

void PlayTrack::Stop()
{
	playing = false;
}

void PlayTrack::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Time delta)
{
	CurrTimeLine.setPosition(time,0);
	time += 60/BPM*delta.asSeconds();
	checkSound();
	if (time == 0) {
		for (int i = 0; i < Sounds.size(); i++) {
			Sounds[i].played = false;
		}
	}
	for (int i = 0; i < Sounds.size(); i++) {
		Sounds[i].Vis.setPosition(Sounds[i].Pos + x,600 - Sounds[i].OctavePos * 100);
	}
}

void PlayTrack::checkCol(sf::Vector2i Mouse)
{
	bool xCol = false;
	bool yCol = false;
	if (Mouse.x > x) {
		if (Mouse.x < x + size.x) {
			xCol = true;
		}
	}
	if (Mouse.y > y) {
		if (Mouse.y < y + size.y) {
			yCol = true;
		}
	}
	bool xLineCol = false;
	bool yLineCol = false;
	if (Mouse.x > x + time - 25) {
		if (Mouse.x < x + time + 25) {
			xLineCol = true;
		}
	}
	if (Mouse.y > y) {
		if (Mouse.y < y + size.y) {
			yLineCol = true;
		}
	}
	bool winCol = false;
	bool lineCol = false;
	if (xCol and yCol) {
		winCol = true;
	}
	if (xLineCol and yLineCol) {
		lineCol = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (winCol) {
			if (lineCol) {
				time = Mouse.x - x;
			}
			else {
				if (CurrPreset.type == 1 and !clicked) {
					sf::Vector2f snappedVec(std::floor((Mouse.x - x)/2)*2, std::round((Mouse.y - y) / 100) * 100);
					Sounds.push_back(SoundNode(snappedVec.x,snappedVec.y,CurrPreset.Path,CurrPreset.Volume, CurrPreset.AttackTime, CurrPreset.DecayTime, CurrPreset.Left, CurrPreset.Length, CurrPreset.Pitch));


					clicked = true;
				}
			}
		}
	}
	else {
		clicked = false;
	}


}

void PlayTrack::checkSound()
{
	for (int i = 0; i < Sounds.size(); i++) {
		if (Sounds[i].Pos < time and Sounds[i].played == false) {
			Sounds[i].Playable.play();
			Sounds[i].played = true;
		}
		if (Sounds[i].Pos < time and Sounds[i].Pos+ Sounds[i].Length > time) {


		}

	}

}
