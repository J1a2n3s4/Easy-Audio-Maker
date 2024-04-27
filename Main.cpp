#include <SFML/Graphics.hpp>
#include <Button.h>
#include <string>
#include <Header.h>
#include <map>
#include <Options.h>
#include <iostream>
#include <Footer.h> 
#include <Presets.h>
#include <SoundBrushOpts.h>
#include <PlayTrack.h>
#include <EditHeader.h>
#include <Synth.h>

PresetsContainer FooterPresets;

sf::Vector2f WinSize(1000, 1000);

SynthTab Oscs;

editHeader HeaderEdit;

sf::Clock Clock;

sf::RenderWindow OPTSWIN(sf::VideoMode(600, 800, 32), "AudioMaker Options", sf::Style::Default);
sf::RenderWindow Window(sf::VideoMode(1000,1000,32),"AudioMaker", sf::Style::Default);

struct Settings Settings = { 100,60,".wav" };
struct Settings LastSettings = { 100,60,".wav" };

struct presets Presety[11];

PlayTrack TimeLine(Presety[0]);

Footer Stopka;

Header Nagl;

Options Opts(Settings);

BrushOPTS brushWin;

MoveSlider TimelineSlider("",0,305,650,100);

ButtonHeader OPT1 = ButtonHeader(sf::Vector2f(60, 20), 15, 50, "Save", &Nagl);
ButtonHeader OPT2 = ButtonHeader(sf::Vector2f(60, 20), 15, 80, "Open", &Nagl);
ButtonHeader OPT3 = ButtonHeader(sf::Vector2f(60, 20), 15, 110, "Export", &Nagl);
ButtonHeader OPT4 = ButtonHeader(sf::Vector2f(60, 20), 15, 140, "Sound In", &Nagl);

ButtonOptions Accept(sf::Vector2f(80,30),310,670,"Accept",&Opts);
ButtonOptions Cancel(sf::Vector2f(80,30),210,670,"Cancel",&Opts);

ButtonHeader OptionsButton = ButtonHeader(sf::Vector2f(60, 20), 85, 10, "Options", &Nagl);
ButtonHeader File = ButtonHeader(sf::Vector2f(60, 20), 15, 10, "File", &Nagl);

void process(sf::Event Ev) {
    TimeLine.CurrPreset = Presety[FooterPresets.chosenPresetID];
    brushWin.OpenPreset(&Presety[FooterPresets.chosenPresetID], FooterPresets.chosenPresetID);
    TimeLine.x = 303 - TimelineSlider.getValue()*50;
    sf::Time delta = Clock.restart();
    TimelineSlider.Process(&Window, sf::Mouse::getPosition(Window), WinSize);
    TimeLine.Process(&Window, sf::Mouse::getPosition(Window), delta, WinSize);
    Oscs.process(&Window, WinSize, sf::Mouse::getPosition(Window));
    
    brushWin.Process(WinSize,&Window, Ev, sf::Mouse::getPosition(Window));
    Stopka.Process(&Window, sf::Mouse::getPosition(Window),WinSize);
    Nagl.Process(WinSize, &Window, sf::Mouse::getPosition(Window),Ev);
    if (Nagl.OptsVisible) {
        OPT1.Process(sf::Mouse::getPosition(Window), WinSize, &Window, Ev);
        OPT2.Process(sf::Mouse::getPosition(Window), WinSize, &Window, Ev);
        OPT3.Process(sf::Mouse::getPosition(Window), WinSize, &Window, Ev);
        OPT4.Process(sf::Mouse::getPosition(Window), WinSize, &Window, Ev);

    }
    OptionsButton.Process(sf::Mouse::getPosition(Window), WinSize, &Window, Ev);
    File.Process(sf::Mouse::getPosition(Window), WinSize, &Window, Ev);
    if (Nagl.SettingsOpened) {
        OPTSWIN.setVisible(true);
        OPTSWIN.setActive(true);
        OPTSWIN.setPosition(sf::Vector2i(1000,100));
        sf::RenderWindow* WINWSK = &OPTSWIN;
        struct Settings* WSKSetLast = &LastSettings;
        struct Settings* WSKSetChanging = &Settings;

        Accept.Process(sf::Mouse::getPosition(OPTSWIN), WinSize, WINWSK, Ev,WSKSetChanging,WSKSetLast,&Nagl);
        Cancel.Process(sf::Mouse::getPosition(OPTSWIN), WinSize, WINWSK, Ev,WSKSetChanging,WSKSetLast,&Nagl);

        Opts.Process(WINWSK, sf::Mouse::getPosition(OPTSWIN), WinSize);
    }
    else {
        OPTSWIN.setVisible(false);
        OPTSWIN.setActive(false);
    }

    HeaderEdit.Process(sf::Mouse::getPosition(Window), WinSize, &Window, TimeLine.time);

    FooterPresets.Process(sf::Mouse::getPosition(Window),WinSize,&Window);
}

int main() {
    Window.setPosition(sf::Vector2i(540,0));
    Clock.restart();
    for (int i = 0; i < 11; i++) {
        Presety[i] = { 100.0,1.0,50.0,2.0,0.0,0.0};
    }

	while (true) {
        Window.clear(sf::Color(40,40,40));
        OPTSWIN.clear(sf::Color(40, 40, 40));
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Window.close();
            if (event.type == sf::Event::Resized) {
                if (event.size.width < 1000) {
                    Window.setSize(sf::Vector2u(1000, Window.getSize().y));
                if (event.size.height < 1000) {
                        Window.setSize(sf::Vector2u(Window.getSize().x, 1000));
                    }
                }

                WinSize.x = event.size.width;
                WinSize.y = event.size.height;
            }
        }

        while (OPTSWIN.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Nagl.OpenWin("Options");
            }


            if (event.type == sf::Event::Resized) {
                if (event.size.width != 600) {
                    OPTSWIN.setSize(sf::Vector2u(600, OPTSWIN.getSize().y));
                }
                if (event.size.height != 800) {
                    OPTSWIN.setSize(sf::Vector2u(OPTSWIN.getSize().x, 800));
                }
            }
        }
        process(event);
        Window.display();
        OPTSWIN.display();
	}

	return 0;
}