#pragma once
#include <Button.h>
#include <Slider.h>
#include <SFML/Audio.hpp>
#include <Presets.h>

class BrushOPTS {
public:
	struct presets* preset;
	void Process(sf::Vector2f WinSize, sf::RenderWindow * WSK, sf::Event EV, sf::Vector2i Mouse);
	BrushOPTS();
	void SavePreset(int id);
	void GetPreset(); // zwracany typ do zmiany, czyli ¿e na brusha.
	void OpenPreset(presets* startPreset);
private:
	bool open = false;
	
	sf::RectangleShape BG;
	sf::Image SoundVisionEditor;
	sf::Sprite SoundVision;
	sf::Texture SoundVisionTexture;
	float soundLength;
	float Volume;
	sf::Vector2f size;
	int X;
	int Y;
	bool type; // 0 to synth, 1 to sample
	sf::Sound Sample;
};