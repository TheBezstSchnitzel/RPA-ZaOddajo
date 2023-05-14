#include "stdafx.h"
#include "PlayGameState.h"

void PlayGameState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void PlayGameState::initKeybinds(){
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void PlayGameState::initTextures(){
	if (!this->textures["MAIN_BACKGROUND"].loadFromFile("Resources/Images/Backgrounds/bg.png")) {
		throw "ERROR::PLAY_GAME_STATE::FAILED_TO_LOAD_MAIN_BACKGROUND_TEXTURE";
	}
	if (!this->textures["SUB_BACKGROUND"].loadFromFile("Resources/Images/Backgrounds/bg16.png")) {
		throw "ERROR::PLAY_GAME_STATE::FAILED_TO_LOAD_SUB_BACKGROUND_TEXTURE";
	}
	//se font
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::PLAY_GAME_STATE::COULD NOT LOAD FONT");
	}
}

void PlayGameState::initBackgrounds(const sf::VideoMode& vm){
	//main background
	this->backgrounds["MAIN_BG"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);
	this->backgrounds["MAIN_BG"].setTexture(&this->textures["MAIN_BACKGROUND"]);
	//Ozadje za Gumbe
	this->backgrounds["BTN_BG"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 1.5f),
			static_cast<float>(vm.height)
		)
	);
	this->backgrounds["BTN_BG"].setPosition(gui::p2pX(17.5f, vm), 0.f);
	this->backgrounds["BTN_BG"].setFillColor(sf::Color(10, 10, 10, 220));
	//Ozadje za savee
	//1
	this->backgrounds["SAVE_BG_1"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_1"].setPosition(gui::p2pX(24.f, vm), gui::p2pX(3.5f, vm));
	this->backgrounds["SAVE_BG_1"].setTexture(&this->textures["SUB_BACKGROUND"]);
	//2
	this->backgrounds["SAVE_BG_2"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_2"].setPosition(gui::p2pX(24.f, vm), gui::p2pX(22.5f, vm));
	this->backgrounds["SAVE_BG_2"].setTexture(&this->textures["SUB_BACKGROUND"]);
	//3
	this->backgrounds["SAVE_BG_3"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_3"].setPosition(gui::p2pX(55.f, vm), gui::p2pX(22.5f, vm));
	this->backgrounds["SAVE_BG_3"].setTexture(&this->textures["SUB_BACKGROUND"]);
	//4
	this->backgrounds["SAVE_BG_4"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_4"].setPosition(gui::p2pX(55.f, vm), gui::p2pX(3.5f, vm));
	this->backgrounds["SAVE_BG_4"].setTexture(&this->textures["SUB_BACKGROUND"]);
}

void PlayGameState::initKeyTime() {
	this->keytimeMax = 0.75f;
}

void PlayGameState::initTexts(const sf::VideoMode& vm) {
	//Inicializacija teksta
	//1
	this->texts["SAVE_1"].setFont(this->font);
	this->texts["SAVE_1"].setPosition(sf::Vector2f(gui::p2pX(31.f, vm), gui::p2pY(20.f, vm)));
	this->texts["SAVE_1"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_1"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE_1"].setString("  Save #1: \n 0-0-0-0");
	//2
	this->texts["SAVE_2"].setFont(this->font);
	this->texts["SAVE_2"].setPosition(sf::Vector2f(gui::p2pX(62.f, vm), gui::p2pY(20.f, vm)));
	this->texts["SAVE_2"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_2"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE_2"].setString("  Save #2: \n 0-0-0-0");
	//3
	this->texts["SAVE_3"].setFont(this->font);
	this->texts["SAVE_3"].setPosition(sf::Vector2f(gui::p2pX(31.f, vm), gui::p2pY(54.f, vm)));
	this->texts["SAVE_3"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_3"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE_3"].setString("  Save #3: \n 0-0-0-0");
	//4
	this->texts["SAVE_4"].setFont(this->font);
	this->texts["SAVE_4"].setPosition(sf::Vector2f(gui::p2pX(62.f, vm), gui::p2pY(54.f, vm)));
	this->texts["SAVE_4"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_4"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE_4"].setString("  Save #4: \n 0-0-0-0");
}

void PlayGameState::initGui(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->initTextures();
	this->initTexts(vm);
	this->initBackgrounds(vm);

	if (!this->buffer.loadFromFile("Resources/Audio/click.wav")) {
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_CLICK_SOUND";
	}
	this->click.setBuffer(this->buffer);
	//Gumbi
	this->buttons["GAME_SAVE_1"] = new gui::Button(
		gui::p2pX(28.3f, vm), gui::p2pY(13.3f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["GAME_SAVE_2"] = new gui::Button(
		gui::p2pX(59.5f, vm), gui::p2pY(13.3f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["GAME_SAVE_3"] = new gui::Button(
		gui::p2pX(28.3f, vm), gui::p2pY(47.5f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["GAME_SAVE_4"] = new gui::Button(
		gui::p2pX(59.5f, vm), gui::p2pY(47.5f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EXIT"] = new gui::Button(
		gui::p2pX(43.5f, vm), gui::p2pY(80.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Back", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void PlayGameState::resetGui(){
	//Resetira GUI	
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
	this->buttons.clear();

	this->initGui();
}


PlayGameState::PlayGameState(StateData* state_data) : State(state_data){
	this->initFonts();
	this->initKeyTime();
	this->initKeybinds();
	this->initGui();
}

PlayGameState::~PlayGameState(){
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void PlayGameState::updateButtons() {
	//Updata gumbe
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosWindow);
	}

	//Nou game
	if (this->buttons["GAME_SAVE_1"]->isPressed()) {
		this->click.play();
		this->states->push(new GameState(this->stateData));
	}
	if (this->buttons["GAME_SAVE_2"]->isPressed()) {
		this->click.play();
		this->states->push(new GameState(this->stateData));
	}
	if (this->buttons["GAME_SAVE_3"]->isPressed()) {
		this->click.play();
		this->states->push(new GameState(this->stateData));
	}
	if (this->buttons["GAME_SAVE_4"]->isPressed()) {
		this->click.play();
		this->states->push(new GameState(this->stateData));
	}
	//Exit
	if (this->buttons["EXIT"]->isPressed()) {
		this->click.play();
		this->endState();
	}
}

void PlayGameState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void PlayGameState::renderButtons(sf::RenderTarget& target) {
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void PlayGameState::renderBackgrounds(sf::RenderTarget& target){
	target.draw(this->backgrounds["MAIN_BG"]);
	target.draw(this->backgrounds["BTN_BG"]);
	target.draw(this->backgrounds["SAVE_BG_1"]);
	target.draw(this->backgrounds["SAVE_BG_2"]);
	target.draw(this->backgrounds["SAVE_BG_3"]);
	target.draw(this->backgrounds["SAVE_BG_4"]);
}

void PlayGameState::renderTexts(sf::RenderTarget& target){
	for (auto i : texts) {
		target.draw(i.second);
	}
}

void PlayGameState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	
	this->renderBackgrounds(*target);
	this->renderTexts(*target);
	this->renderButtons(*target);

	//DEBUG
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/
}

void PlayGameState::updateInput(const float& dt) {
}