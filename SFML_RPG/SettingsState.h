#pragma once

#include "State.h"
#include "Gui.h"

class SettingsState : public State{
private:
	//Lastnosti
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::RectangleShape btnBackground;
	sf::Font font;

	//Zvok
	sf::SoundBuffer buffer;
	sf::Sound click;

	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, gui::DropDownList*> dropDownLists;

	sf::Text optionsText;

	std::vector<sf::VideoMode> modes;

	//Privatne funkcije
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	SettingsState(StateData* state_data);
	virtual ~SettingsState();
	//Funkcije
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};