#include "EditHeader.h"


void editHeader::Process(sf::Vector2i Mouse, sf::Vector2f WinSize, sf::RenderWindow* WSK, float time)
{
	timeTXT.setString(std::to_string(time));
	timeTXT.setPosition(320*(1000/WinSize.x), 45 * (1000 / WinSize.y));
	timeTXT.setScale(1000 / WinSize.x, 1000 / WinSize.y);
	WSK->draw(timeTXT);
	Checks.Process(Mouse, WinSize, WSK);
}

int editHeader::get()
{
	return Checks.chosenBoxID;
}

editHeader::editHeader()
{
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	timeTXT.setFont(czc);
	timeTXT.setCharacterSize(40);
}
