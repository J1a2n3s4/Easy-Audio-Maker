#include "PlayTrack.h"

PlayTrack::PlayTrack()
{
	LineTex.loadFromFile("Assets/LineStamp.png");
	CurrTimeLine.setTexture(LineTex);

}

void PlayTrack::Start()
{
}

void PlayTrack::Continue()
{
}

void PlayTrack::Stop()
{
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
}
