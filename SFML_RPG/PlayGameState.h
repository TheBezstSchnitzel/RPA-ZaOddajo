#pragma once

#include "GameState.h"
#include "EditorState.h"
#include "SettingsState.h"
#include "Gui.h"

class PlayGameState : public State{
private:
	//Lastnosti
	sf::Font font;

	std::map<std::string, sf::Texture>  textures;
	std::map<std::string, sf::RectangleShape> backgrounds;
	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, sf::Text> texts;

	//Zvok
	sf::SoundBuffer buffer;
	sf::Sound click;

	//Privatne funkcije
	void initFonts();
	void initKeybinds();
	void initTextures();
	void initBackgrounds(const sf::VideoMode& vm);
	void initTexts(const sf::VideoMode& vm);
	void initGui();
	void initKeyTime();
	void resetGui();

public:
	PlayGameState(StateData* state_data);
	virtual ~PlayGameState();

	//funkcije
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void renderBackgrounds(sf::RenderTarget& target);
	void renderTexts(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);

	void updateInput(const float& dt); //ker ce ne je abstract
};

