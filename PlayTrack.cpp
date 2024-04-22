#include "PlayTrack.h"
#include <cmath>
#include <iostream>

void PlayTrack::setBPM(int bpm)
{
	BPM = bpm;
}

bool clicked = false;

PlayTrack::PlayTrack(presets preset)
{
	x = 303;
	y = 140;
	CurrPreset = preset;
	size.x = 498;
	size.y = 760;
	LineTex.loadFromFile("Assets/LineStamp.png");
	CurrTimeLine.setTexture(LineTex);
	CurrTimeLine.setOrigin(26, 0);
	time = 0.0f;
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 20; j++) {
			Grid[i][j].setFillColor(sf::Color(30, 30, 30));
			Grid[i][j].setOutlineColor(sf::Color(100, 100, 130));
			Grid[i][j].setOutlineThickness(1);
			Grid[i][j].setSize(sf::Vector2f(10, 25));
			Grid[i][j].setPosition(10*i,25*j);
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

void PlayTrack::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse, sf::Time delta, sf::Vector2f WinSize)
{
	checkCol(Mouse);
	CurrTimeLine.setPosition((time+x) * (1000 / WinSize.x),(y-100) * (1000 / WinSize.y));
	if (playing) {
		time += BPM / 60 * delta.asSeconds();
	}
	
	checkSound();
	if (time == 0) {
		for (int i = 0; i < Sounds.size(); i++) {
			Sounds[i].played = false;
		}
	}

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 20; j++) {
			Grid[i][j].setPosition((10*i + x) * (1000 / WinSize.x),( 25 * j + y) * (1000 / WinSize.y));
			Grid[i][j].setScale(1000 / WinSize.x, 1000 / WinSize.y);
			WSK->draw(Grid[i][j]);
		}
	}
	CurrTimeLine.setScale(1000 / WinSize.x, 1000 / WinSize.y);

	for (int i = 0; i < Sounds.size(); i++) {
		Sounds[i].Vis.setPosition((Sounds[i].Pos + x) * (1000 / WinSize.x), (Sounds[i].OctavePos * 25) * (1000 / WinSize.y));
		WSK->draw(Sounds[i].Vis);
	}
	WSK->draw(CurrTimeLine);
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
				if (CurrPreset.type == true and !clicked) {
					sf::Vector2f snappedVec(std::floor((Mouse.x - x)/10)*10, std::round((Mouse.y - y) / 25));
					Sounds.push_back(SoundNode(snappedVec.x,snappedVec.y,CurrPreset.Path,CurrPreset.Volume, CurrPreset.AttackTime, CurrPreset.DecayTime, CurrPreset.Left, CurrPreset.Length, snappedVec.y));
					std::cout << "lol\n";
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
