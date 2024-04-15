#include "Slider.h"
#include <iostream>
#include <string>

int Slider::getValue()
{
    return value;
}

bool click2 = false;

Slider::Slider(std::string Name, float Procent,float xPos,float yPos, float Max)
{
    X = xPos;
    Y = yPos;
    name.setString(Name);
    czc.loadFromFile("Assets/NunitoSans_10pt_SemiExpanded-Regular.ttf");
    name.setFont(czc);
    value = Max*Procent/300;
    name.setCharacterSize(12);
    name.setOutlineThickness(1);
    name.setOutlineColor(sf::Color(0,100,100));
    PickTexture.loadFromFile("Assets/PointerSlider.png");
    Pick.setTexture(PickTexture);
    Pick.setOrigin(15,15);
    Track.setFillColor(sf::Color(10,10, 10));
    Track.setOutlineThickness(2.0);
    Track.setOutlineColor(sf::Color(220, 220, 220));
    Track.setSize(sf::Vector2f(300,10));
    Track.setPosition(X,Y);
    Track.setOrigin(0,-2.5);
    name.setPosition(X - 100, Y);
}

void Slider::Process(sf::RenderWindow* WSK,sf::Vector2i MousePos)
{
    Pick.setPosition(X + value * 3, Y + 5);
    WSK->draw(name);
    
    WSK->draw(Track);
    WSK->draw(Pick);
    bool xCol = false;
    bool yCol = false;
    //Sprawdzenie Kolizji
    if (MousePos.x > X) {
        if (MousePos.x < X + 300) {
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
            if (!click2) {
                value = (MousePos.x - X) / 3.0f;
                click2 = true;
                std::cout << Pick.getPosition().x <<" changed!\n";
            }
        }
        else {
            click2 = false;
        }
    }
    else {
        
    }
}
