#include "PlayTrack.h"
#include <cmath>
#include <iostream>
#include <sound_engine.h>

void PlayTrack::setBPM(int bpm)
{
	BPM = bpm;
}

bool spacePress = false;

bool clicked = false;
bool clickedOnLine = false;

PlayTrack::PlayTrack(presets preset)
{
	x = 303;
	y = 140;
	CurrPreset = preset;
	size.x = 498;
	size.y = 500;
	LineTex.loadFromFile("Assets/LineStamp.png");
	CurrTimeLine.setTexture(LineTex);
	CurrTimeLine.setOrigin(26, 0);
	time = 0.0f;
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 14; j++) {
			Grid[i][j].setFillColor(sf::Color(30, 30, 30));
			Grid[i][j].setOutlineColor(sf::Color(100, 100, 130));
			Grid[i][j].setOutlineThickness(1);
			Grid[i][j].setSize(sf::Vector2f(30, 25));
			Grid[i][j].setPosition(30*i,25*j);
		}
	}
}

void PlayTrack::Start()
{
	for (int i = 0; i < Sounds.size(); i++) {
		Sounds[i].played = false;
	}
	time = 0;
}

void PlayTrack::Toggle()
{
	playing = !playing;
}



void PlayTrack::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Time delta, sf::Vector2f WinSize)
{
	size.x = WinSize.x - 300 - x;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (!spacePress) {
			Toggle();
		}
		spacePress = true;
	}
	else {
		spacePress = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		Start();
	}
	checkCol(Mouse,WinSize);
	CurrTimeLine.setPosition((time*30+x) * (1000 / WinSize.x),(y-100) * (1000 / WinSize.y));
	if (playing) {
		time += delta.asSeconds()*(BPM/60);
	}

	if (time == 0) {
		for (int i = 0; i < Sounds.size(); i++) {
			Sounds[i].played = false;
		}
	}

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 14; j++) {
			Grid[i][j].setPosition((30*i + x) * (1000 / WinSize.x),( 25 * j + y) * (1000 / WinSize.y));
			Grid[i][j].setScale(1000 / WinSize.x, 1000 / WinSize.y);
			WSK->draw(Grid[i][j]);
		}
	}
	CurrTimeLine.setScale(1000 / WinSize.x, 1000 / WinSize.y);

	for (int i = 0; i < Sounds.size(); i++) {
		Sounds[i].Vis.setPosition((std::floor((Sounds[i].Pos + x) / 30) * 30 + 2) * (1000 / WinSize.x), (Sounds[i].OctavePos * 25 + y) * (1000 / WinSize.y));
		Sounds[i].Vis.setScale(1000/WinSize.x,1000/WinSize.y);
		WSK->draw(Sounds[i].Vis);
	}
	WSK->draw(CurrTimeLine);
}

void PlayTrack::checkCol(sf::Vector2i Mouse,sf::Vector2f Win)
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
	for (int i = 0; i < Sounds.size(); i++) {
		if (Sounds[i].checkCol(Mouse,Win)) {
			Sounds[i].Vis.setFillColor(sf::Color(60,60,180));
		}
		else {
			Sounds[i].Vis.setFillColor(sf::Color(30, 30, 90));
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (winCol) {
			if (lineCol or clickedOnLine) {
				time = Mouse.x - x;
				clickedOnLine = true;
			}
			else {
				if (!clicked) {
					sf::Vector2f snappedVec(std::floor((Mouse.x - x) / (30)) * (30), std::round((Mouse.y - y) / 25));
					switch (EditMode) {
					case 0:
						Sounds.push_back(SoundNode(snappedVec.x, snappedVec.y, CurrPreset.Volume, CurrPreset.AttackTime, CurrPreset.DecayTime, CurrPreset.Length, snappedVec.y));
						break;
					case 2:
						for (int i = 0; i < Sounds.size(); i++) {
							if (Sounds[i].checkCol(Mouse,Win)) {
								Sounds.erase(Sounds.begin() + i);
							}
						}
						break;
					}
					
					

					clicked = true;
				}
			}
		}
	}
	else {
		clickedOnLine = false;
		clicked = false;
	}


}

std::vector<SoundNode> PlayTrack::checkSound()
{
	std::vector<SoundNode> active;
	for (int i = 0; i < Sounds.size(); i++) {
		if (Sounds[i].Pos / 30 < time and time < Sounds[i].Pos / 30 + Sounds[i].Length) {
			active.push_back(Sounds[i]);
		}

	}
	return active;
}
