#pragma once 
#include "settings.h" 
class Laser {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speedy;
public:
	Laser(sf::Vector2f playerPos) {
		texture.loadFromFile(LASER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(playerPos);
	}
	void update() {
		sprite.move(0.f, SPEED_LASER);
	}
	sf::Sprite& getSprite() { return sprite; }
};