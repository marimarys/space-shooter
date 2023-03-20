#pragma once 
#include "SFML/Graphics.hpp" 
#include "settings.h" 
#include "laser1.h" 
#include <list> 
class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx;
	std::list<Laser*> laserSprites;
public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(PLAYER_START_POS);
		speedx = 0.f;
	}
	void Update() {
		speedx = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			speedx = -PLAYER_SPEEDX;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speedx = PLAYER_SPEEDX;
		}
		sf::Vector2f playerPosition = sprite.getPosition();
		sprite.move(speedx, 0.f);
		if (sprite.getPosition().x < 0) {
			sprite.setPosition(0.f, playerPosition.y);
		}
		if (sprite.getPosition().x > WINDOW_WIDTH - PLAYER_WIDTH) {
			sprite.setPosition(WINDOW_WIDTH - PLAYER_WIDTH, playerPosition.y);
		}
		fire();
		for (auto laser : laserSprites) {
			laser->update();
		}
	}
	void Draw(sf::RenderWindow& window) {
		window.draw(sprite);
		for (auto laser : laserSprites) {
			window.draw(laser->getSprite());
		}
	}
	void fire() {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			sf::Vector2f pos = sprite.getPosition();
			sf::FloatRect bounds = sprite.getLocalBounds();
			sf::Vector2f posCenter = sf::Vector2f{ pos.x + bounds.width / 2,pos.y + bounds.height / 2 };
			auto laser = new Laser(posCenter);
			laserSprites.push_back(laser);
		}

	}
};