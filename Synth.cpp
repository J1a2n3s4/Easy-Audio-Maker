#include "Synth.h"
#include <iostream>

Slider OscSLider0("Volume 0", 100, 820, 500, 100, sf::Vector2f(100, 15));
Slider OscSLider1("Volume 1", 0, 820, 550, 100, sf::Vector2f(100, 15));
Slider OscSLider2("Volume 2", 0, 820, 600, 100, sf::Vector2f(100, 15));

Checkbox Sine0("Assets/SineIcon.png","Sine", 710, 60);
Checkbox Sine1("Assets/SineIcon.png", "Sine", 710, 160+22);
Checkbox Sine2("Assets/SineIcon.png", "Sine", 710, 270+34);


Checkbox Triangle0("Assets/TriangleIcon.png", "Triangle", 710, 93);
Checkbox Triangle1("Assets/TriangleIcon.png", "Triangle", 710, 193 + 22);
Checkbox Triangle2("Assets/TriangleIcon.png", "Triangle", 710, 303 + 34);


Checkbox Square0("Assets/SquareIcon.png", "Square", 710, 126);
Checkbox Square1("Assets/SquareIcon.png", "Square", 710, 226+22);
Checkbox Square2("Assets/SquareIcon.png", "Square", 710, 336+34);

Checkbox Boxes[9] = {
	Sine0,Sine1,Sine2,Triangle0,Triangle1,Triangle2,Square0,Square1,Square2
};

void SynthTab::process(sf::RenderWindow * WSK, sf::Vector2f WinSize,sf::Vector2i Mouse)
{
	
	WSK->draw(BG);
	BG.setPosition((WinSize.x-301)*(1000/WinSize.x), 0);
	OscShapes[0].setPosition((WinSize.x - 210) * (1000 / WinSize.x), 60 * (1000/WinSize.y));
	OscShapes[1].setPosition((WinSize.x - 210) * (1000 / WinSize.x), 182 * (1000 / WinSize.y));
	OscShapes[2].setPosition((WinSize.x - 210) * (1000 / WinSize.x), 304 * (1000 / WinSize.y));
	OscTexts[0].setPosition((WinSize.x - 205) * (1000 / WinSize.x), 63 * (1000 / WinSize.y));
	OscTexts[1].setPosition((WinSize.x - 205) * (1000 / WinSize.x), 185 * (1000 / WinSize.y));
	OscTexts[2].setPosition((WinSize.x - 205) * (1000 / WinSize.x), 307 * (1000 / WinSize.y));

	volumes[0] = OscSLider0.getValue()/100;
	volumes[1] = OscSLider1.getValue()/100;
	volumes[2] = OscSLider2.getValue()/100;

	OscSLider0.setPos(WinSize.x - 150,500);
	OscSLider1.setPos(WinSize.x - 150,550);
	OscSLider2.setPos(WinSize.x - 150,600);

	OscSLider0.Process(WSK, Mouse, WinSize);
	OscSLider1.Process(WSK, Mouse, WinSize);
	OscSLider2.Process(WSK, Mouse, WinSize);

	for (int i = 0; i < 3; i++) {
		OscShapes[i].setScale(1000 / WinSize.x, 1000 / WinSize.y);
		OscTexts[i].setScale(1000 / WinSize.x, 1000 / WinSize.y);
		OscShapes[i].setTexture(*ShapeChose[i]);
		WSK->draw(OscShapes[i]);
		WSK->draw(OscTexts[i]);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int i = 0; i < 9; i++) {
			if (Boxes[i].checkCol(Mouse)) {
				switch (i) {
				case 0:
					ShapeChose[0] = &Sine;
					chosenOscs[0] = 0;
					break;
				case 1:
					ShapeChose[1] = &Sine;
					chosenOscs[1] = 0;
					break;
				case 2:
					ShapeChose[2] = &Sine;
					chosenOscs[2] = 0;
					break;
				case 3:
					ShapeChose[0] = &Triangle;
					chosenOscs[0] = 2;
					break;
				case 4:
					ShapeChose[1] = &Triangle;
					chosenOscs[1] = 2;
					break;
				case 5:
					ShapeChose[2] = &Triangle;
					chosenOscs[2] = 2;
					break;
				case 6:
					ShapeChose[0] = &Square;
					chosenOscs[0] = 1;
					break;
				case 7:
					ShapeChose[1] = &Square;
					chosenOscs[1] = 1;
					break;
				case 8:
					ShapeChose[2] = &Square;
					chosenOscs[2] = 1;
					break;
				}
			}

		}
	}
	for (int i = 0; i < 9; i++) {
		Boxes[i].Process(WinSize, WSK); 
		Boxes[i].setPosition(WinSize.x-290, Boxes[i].y);
	}



}

SynthTab::SynthTab()
{
	BG.setFillColor(sf::Color(30,30,90));
	BG.setOutlineColor(sf::Color(200,200,200));
	BG.setOutlineThickness(1);
	BG.setSize(sf::Vector2f(300,2000));
	czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
	for (int i = 0; i < 3; i++) {
		OscTexts[i].setFont(czc);
		OscTexts[i].setCharacterSize(12);
		OscTexts[i].setString("OSCILLATOR " + std::to_string(i));
	}
	

	Square.loadFromFile("Assets/SquareImage.png");
	Sine.loadFromFile("Assets/SineImage.png");
	Triangle.loadFromFile("Assets/TriangleImage.png");
}

void SynthTab::CheckBoxes(sf::Vector2i Mouse)
{

}
