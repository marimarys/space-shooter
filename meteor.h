#pragma once 
#include "SFML/Graphics.hpp" 
#include "settings.h" 
class Meteor {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string textureFileNames[];
	float speedx, speedy;
	void spown() {
		float meteorWidth = sprite.getLocalBounds().width;
		float x = rand() % (int)(WINDOW_WIDTH - meteorWidth);
		float y = rand() % (int)(WINDOW_HEIGHT / 2) - WINDOW_HEIGHT / 2;
		sprite.setPosition(x, y);
		speedx = rand() % 5 - 2;
		speedy = rand() % 4 + 2;
	}
public:
	Meteor() {
		int index = rand() % 10;
		texture.loadFromFile(textureFileNames[index]);
		sprite.setTexture(texture);
		spown();
	}
	void update() {
		sprite.move(speedx, speedy);
		sf::Vector2f pos = sprite.getPosition();
		float meteorWidth = sprite.getLocalBounds().width;
		if (pos.x < -meteorWidth  pos.y > WINDOW_HEIGHT  pos.x > WINDOW_WIDTH) {
			spown();
		}
	}
	sf::Sprite& getSprite() { return sprite; }


};

std::string Meteor::textureFileNames[] = { 
	"images\\meteorBrown_big1.png","images\\meteorBrown_big2.png",
	"images\\meteorBrown_big3.png","images\\meteorBrown_big4.png",
	"images\\meteorBrown_med1.png","images\\meteorBrown_med3.png", 
"images\\meteorBrown_small1.png","images\\meteorBrown_small2.png",
"images\\meteorBrown_tiny1.png","images\\meteorBrown_tiny2.png"
};