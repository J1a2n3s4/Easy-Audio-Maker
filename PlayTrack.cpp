#include "PlayTrack.h"

PlayTrack::PlayTrack()
{
	LineTex.loadFromFile("Assets/LineStamp.png");
	CurrTimeLine.setTexture(LineTex);
	CurrTimeLine.setOrigin(26, 0);
	time = 0.0f;
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 6; j++) {
			Grid[i][j].setFillColor(sf::Color(30, 30, 30));
			Grid[i][j].setOutlineColor(sf::Color(200, 200, 200));
			Grid[i][j].setOutlineThickness(1);
			Grid[i][j].setSize(sf::Vector2f(50, 50));
			Grid[i][j].setPosition(50*i,50*j);
		}
	}
}

void PlayTrack::Start()
{
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

void PlayTrack::Process(sf::RenderWindow* WSK, sf::Vector2i Mouse)
{
}

bool PlayTrack::checkCol(sf::Vector2i Mouse)
{
	return false;
}

void PlayTrack::checkSound()
{
	for (int i = 0; i < Sounds.size(); i++) {
		if (Sounds[i].Pos == time) {
			Sounds[i].Playable.play();

		}
		if (Sounds[i].Pos < time and Sounds[i].Pos+ Sounds[i].Length > time) {
			Sounds[i].Playable.setVolume((Sounds[i].Pos - time) / Sounds[i].Decay);
			Sounds[i].Playable.setVolume((time - (Sounds[i].Pos + (Sounds[i].Length/2))) / Sounds[i].Attack);
		}
	}

}
