#pragma once

#include "Entity.h"
#include "EnemySpawnerTile.h"
#include "AIFollow.h"

class Enemy : public Entity{
protected:
	//Metode
	EnemySpawnerTile& enemySpawnerTile;
	unsigned gainExp;
	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;
	sf::Clock despawnTimer;
	sf::Int32 despawnTimerMax;

	//Inicializacija
	virtual void initVariables() = 0;
	virtual void initAnimations() = 0;

public:
	Enemy(EnemySpawnerTile& enemy_spawner_tile);
	virtual ~Enemy();

	//Dostop
	const unsigned& getGainExp() const;
	EnemySpawnerTile& getEnemySpawnerTile();
	const bool getDamageTimerDone() const;
	const bool getDespawnTimerDone() const;

	void resetDamageTimer();

	//Funkcije
	virtual void generateAttributes(const unsigned level);

	virtual void loseHP(const int hp);
	virtual const bool isDead() const;

	virtual const AttributeComponent* getAttributeComp() const;

	virtual void updateAnimation(const float & dt) = 0;

	virtual void update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
	virtual void render(sf::RenderTarget & target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f(), const bool show_hitbox = false) = 0;
};