#include "stdafx.h"
#include "Tile.h"

Tile::Tile(){
	this->collision = false;
	this->type = 0;
}

Tile::Tile(short type, int grid_x, int grid_y, float gridSizeF,
	const sf::Texture& texture, const sf::IntRect& texture_rect,
	const bool collision){
	this->shape.setPosition(static_cast<float>(grid_x) * gridSizeF, static_cast<float>(grid_y) * gridSizeF);
	this->shape.setTexture(texture);
	this->shape.setTextureRect(texture_rect);

	this->collision = collision;
	this->type = type;
}

Tile::~Tile(){

}

//Dostop
const short & Tile::getType() const{
	return this->type;
}

const bool & Tile::getCollision() const{
	return this->collision;
}

const sf::Vector2f & Tile::getPosition() const{
	return this->shape.getPosition();
}

const sf::FloatRect Tile::getGlobalBounds() const{
	return this->shape.getGlobalBounds();
}

//Funkcije
const bool Tile::intersects(const sf::FloatRect bounds) const{
	return this->shape.getGlobalBounds().intersects(bounds);
}
