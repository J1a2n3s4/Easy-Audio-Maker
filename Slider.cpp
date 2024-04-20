#include "Slider.h"
#include <iostream>
#include <string>


void Slider::setValues(float val, float max)
{
    value = val;
    Max = max;
}


float Slider::getValue()
{
    return value;
}




Slider::Slider(std::string Name, float val,float xPos,float yPos, float max,sf::Vector2f size)
{
    Max = max;
    X = xPos;
    Y = yPos;
    name.setString(Name);
    czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
    name.setFont(czc);
    value = val;
    name.setCharacterSize(12);
    name.setOutlineThickness(1);
    name.setOutlineColor(sf::Color(0,100,100));
    PickTexture.loadFromFile("Assets/PointerSlider.png");
    Pick.setTexture(PickTexture);

    
    Track.setFillColor(sf::Color(10,10, 10));
    Track.setOutlineThickness(2.0);
    Track.setOutlineColor(sf::Color(220, 220, 220));
    Track.setSize(size);
    Track.setPosition(X,Y);
    Track.setOrigin(0,-2.5);
    name.setPosition(X - 100, Y);
}

void Slider::Process(sf::RenderWindow* WSK,sf::Vector2i MousePos, sf::Vector2f WinSize)
{
    Track.setPosition(X*(1000/WinSize.x), Y * (1000 / WinSize.y));
    Track.setOrigin(0, -2.5 * (1000 / WinSize.y));
    name.setPosition((X - 100) * (1000 / WinSize.x), Y * (1000 / WinSize.y));
    Pick.setPosition((X + value) * (1000 / WinSize.x),( Y + 5) * (1000 / WinSize.y));
    Pick.setOrigin(15, 15);

    name.setScale((1000 / WinSize.x), (1000 / WinSize.y));
    Track.setScale((1000 / WinSize.x), (1000 / WinSize.y));
    Pick.setScale((1000 / WinSize.x), (1000 / WinSize.y));
    WSK->draw(name);
    WSK->draw(Track);
    WSK->draw(Pick);
    bool xCol = false;
    bool yCol = false;
    //Sprawdzenie Kolizji
    if (MousePos.x >= X) {
        if (MousePos.x <= X + Track.getSize().x * 1.01) {
            xCol = true;
        }
    }
    if (MousePos.y > Y - 5) {
        if (MousePos.y < Y + 15) {
            yCol = true;
        }
    }
    if (xCol and yCol) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                value = ((MousePos.x - X) / Track.getSize().x * 1.01) * Max;
                if (value > Max) {
                    value = Max;
                }
                std::cout << value <<" changed!\n";
        }
    }
    else {
        
    }

}


