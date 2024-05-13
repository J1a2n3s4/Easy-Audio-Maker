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
#include <sound_engine.h>
#include <vector>

preset_sound oscillator1;

double masterVolume;

Keys Klawiatura[20];

note Notes[20];

envelope_adsr env;

PresetsContainer FooterPresets;

sf::Vector2f WinSize(1000, 1000);

SynthTab Oscs;

preset_sound test;



vector<wstring> urzadzenia = olcNoiseMaker<short>::Enumerate();

olcNoiseMaker<short> dzwiek(urzadzenia[0], 44100, 1, 8, 512);

//sa 3 oscillatory i kazdemu mozna ustawic te 2 wartosci

vector<QueInfo> kolejka;
synth synt;

atomic<double> dFrequencyOutput1 = 0.0;
atomic<double> dFrequencyOutput2 = 0.0;
atomic<double> dFrequencyOutput3 = 0.0;
double dOctaveBaseFrequency = 110.0;
double d12thRootOf2 = pow(2.0, 1.0 / 12.0);

editHeader HeaderEdit;

sf::Clock Clock;

sf::RenderWindow OPTSWIN(sf::VideoMode(600, 800, 32), "AudioMaker Options", sf::Style::Default);
sf::RenderWindow Window(sf::VideoMode(1000, 1000, 32), "AudioMaker", sf::Style::Default);

struct Settings Settings = { 100,60,".wav" };
struct Settings LastSettings = { 100,60,".wav" };

struct presets Presety[11];

PlayTrack TimeLine(Presety[0]);

Footer Stopka;

Header Nagl;

Options Opts(Settings);

BrushOPTS brushWin;

MoveSlider TimelineSlider("", 0, 305, 650, 100);

ButtonHeader OPT1 = ButtonHeader(sf::Vector2f(60, 20), 15, 50, "Save", &Nagl);
ButtonHeader OPT2 = ButtonHeader(sf::Vector2f(60, 20), 15, 80, "Open", &Nagl);
ButtonHeader OPT3 = ButtonHeader(sf::Vector2f(60, 20), 15, 110, "Export", &Nagl);
ButtonHeader OPT4 = ButtonHeader(sf::Vector2f(60, 20), 15, 140, "Sound In", &Nagl);

ButtonOptions Accept(sf::Vector2f(80, 30), 310, 670, "Accept", &Opts);
ButtonOptions Cancel(sf::Vector2f(80, 30), 210, 670, "Cancel", &Opts);

ButtonHeader OptionsButton = ButtonHeader(sf::Vector2f(60, 20), 85, 10, "Options", &Nagl);
ButtonHeader File = ButtonHeader(sf::Vector2f(60, 20), 15, 10, "File", &Nagl);


double synth::scale(const int nNote)
{
    return 256 * pow(1.0594630943592952645618252949463, nNote);
}


double synth::translate_fq(const double dHertz)
{
    return dHertz * 2.0 * synth::PI;
}

double synth::osc(const double dTime, const double dHertz, int nType) {

    double dFreq = synth::translate_fq(dHertz) * dTime;

    switch (nType)
    {
    case 0:
        return sin(dFreq);
    case 1:
        return sin(dFreq) > 0 ? 1.0 : -1.0;
    case 2:
        return asin(sin(dFreq)) * (2.0 / PI);
    default:
        return 0.0;
    }
}
vector<SoundNode> currSounds;
vector<SoundNode> last_currSounds = TimeLine.checkSound();;

double MakeNoise(double dTime) {

    double dOutput = 0.0;
    last_currSounds = currSounds;
    currSounds = TimeLine.checkSound();
    vector<SoundNode> endedSounds;



    for (int g = 0; g < last_currSounds.size(); g++) {
        bool found = false;
        for (int h = 0; h < currSounds.size(); h++) {
            if (currSounds[h].OctavePos == last_currSounds[g].OctavePos) found = true;
        }
        if (!found) {
            endedSounds.push_back(last_currSounds[g]);
            cout << g << endl;
        }
    }



    for (int v = 0; v < endedSounds.size(); v++) {
        int q = 14 - endedSounds[v].OctavePos;
        if (Notes[q].active) {
            cout << q << endl;
            Notes[q].active = false;
            Notes[q].off = dTime;

            QueInfo temp;
            temp.q = q;
            temp.on = Notes[q].on;
            temp.off = Notes[q].off;

            kolejka.insert(kolejka.begin(), temp);

        }
    };



    if (!currSounds.empty()) {
        for (int i = 0; i < currSounds.size(); i++) {
            int q = 14 - currSounds[i].OctavePos;
            if (!Notes[q].active) {
                Notes[q].active = true;
                Notes[q].last_on = Notes[q].on;
                Notes[q].on = dTime;
                cout << q << endl;

            };

            dFrequencyOutput1 = dOctaveBaseFrequency * pow(d12thRootOf2, q + oscillator1.osc1.pitch);
            dFrequencyOutput2 = dOctaveBaseFrequency * pow(d12thRootOf2, q + oscillator1.osc2.pitch);
            dFrequencyOutput3 = dOctaveBaseFrequency * pow(d12thRootOf2, q + oscillator1.osc3.pitch);
            if (env.amplitude(dTime, Notes[q].on, Notes[q].off) != 0) {
                dOutput += env.amplitude(dTime, Notes[q].on, Notes[q].off) *
                    (
                        +oscillator1.osc1.loudness * synt.osc(dTime, dFrequencyOutput1, oscillator1.osc1.waveShape)
                        + oscillator1.osc2.loudness * synt.osc(dTime, dFrequencyOutput2, oscillator1.osc2.waveShape)
                        + oscillator1.osc3.loudness * synt.osc(dTime, dFrequencyOutput3, oscillator1.osc3.waveShape)
                        );
            }
        }

    }






    for (int i = kolejka.size() - 1; i >= 0; i--) {

        if (dTime - kolejka[i].off >= env.dReleaseTime) {

            kolejka.erase(kolejka.begin() + i);

        }
        else {
            dFrequencyOutput1 = dOctaveBaseFrequency * pow(d12thRootOf2, kolejka[i].q + oscillator1.osc1.pitch);
            dFrequencyOutput2 = dOctaveBaseFrequency * pow(d12thRootOf2, kolejka[i].q + oscillator1.osc2.pitch);
            dFrequencyOutput3 = dOctaveBaseFrequency * pow(d12thRootOf2, kolejka[i].q + oscillator1.osc3.pitch);



            if (env.amplitude(dTime, kolejka[i].on, kolejka[i].off) != 0) {

                dOutput += env.amplitude(dTime, kolejka[i].on, kolejka[i].off) *

                    (
                        +oscillator1.osc1.loudness * synt.osc(dTime, dFrequencyOutput1, oscillator1.osc1.waveShape)
                        + oscillator1.osc2.loudness * synt.osc(dTime, dFrequencyOutput2, oscillator1.osc2.waveShape)
                        + oscillator1.osc3.loudness * synt.osc(dTime, dFrequencyOutput3, oscillator1.osc3.waveShape)
                        );
            }
        }
    }
    return dOutput * masterVolume;
};


void process(sf::Event Ev) {
    masterVolume =  LastSettings.Volume/100.0/5.0;
    TimeLine.setBPM(LastSettings.BPM);
    oscillator1.osc1.loudness = Oscs.volumes[0];
    oscillator1.osc2.loudness = Oscs.volumes[1];
    oscillator1.osc3.loudness = Oscs.volumes[2];

    oscillator1.osc1.waveShape = Oscs.chosenOscs[0];
    oscillator1.osc2.waveShape = Oscs.chosenOscs[1];
    oscillator1.osc3.waveShape = Oscs.chosenOscs[2];
    TimeLine.EditMode = HeaderEdit.get();
    TimeLine.CurrPreset = Presety[FooterPresets.chosenPresetID];
    brushWin.OpenPreset(&Presety[FooterPresets.chosenPresetID], FooterPresets.chosenPresetID);
    TimeLine.x = 303 - TimelineSlider.getValue() * 50;
    sf::Time delta = Clock.restart();
    TimelineSlider.Process(&Window, sf::Mouse::getPosition(Window), WinSize);
    TimeLine.Process(&Window, sf::Mouse::getPosition(Window), delta, WinSize);
    Oscs.process(&Window, WinSize, sf::Mouse::getPosition(Window));
    
    brushWin.Process(WinSize, &Window, Ev, sf::Mouse::getPosition(Window));
    Stopka.Process(&Window, sf::Mouse::getPosition(Window), WinSize);
    Nagl.Process(WinSize, &Window, sf::Mouse::getPosition(Window), Ev);
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
        OPTSWIN.setPosition(sf::Vector2i(1000, 100));
        sf::RenderWindow* WINWSK = &OPTSWIN;
        struct Settings* WSKSetLast = &LastSettings;
        struct Settings* WSKSetChanging = &Settings;

        Accept.Process(sf::Mouse::getPosition(OPTSWIN), sf::Vector2f(1000, 1000), WINWSK, Ev, WSKSetChanging, WSKSetLast, &Nagl);
        Cancel.Process(sf::Mouse::getPosition(OPTSWIN), sf::Vector2f(1000, 1000), WINWSK, Ev, WSKSetChanging, WSKSetLast, &Nagl);

        Opts.Process(WINWSK, sf::Mouse::getPosition(OPTSWIN), WinSize);
    }
    else {
        OPTSWIN.setVisible(false);
        OPTSWIN.setActive(false);
    }

    HeaderEdit.Process(sf::Mouse::getPosition(Window), WinSize, &Window, TimeLine.time);

    FooterPresets.Process(sf::Mouse::getPosition(Window), WinSize, &Window);
}

int main() {
    sf::Image icon;
    icon.loadFromFile("Assets/EasyAudioBot.png");
    OPTSWIN.setIcon(100, 100, icon.getPixelsPtr());
    Window.setIcon(100, 100, icon.getPixelsPtr());


    test.osc1.loudness = 5;

    oscillator1.osc1.loudness = 1;
    oscillator1.osc1.waveShape = 1;
    oscillator1.osc1.pitch = 24;

    oscillator1.osc2.loudness = 0;
    oscillator1.osc2.waveShape = 1;
    oscillator1.osc2.pitch = 24;

    oscillator1.osc3.loudness = 0;
    oscillator1.osc3.waveShape = 2;
    oscillator1.osc3.pitch = 24;



    dzwiek.SetUserFunction(MakeNoise);

    Window.setPosition(sf::Vector2i(540, 0));
    Clock.restart();
    for (int i = 0; i < 11; i++) {
        Presety[i] = { 100.0,1.0,2.0,0.0,0.0 };
    }

    while (true) {
        Window.clear(sf::Color(40, 40, 40));
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