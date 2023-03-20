#pragma once 
#include "SFML/Graphics.hpp" 
#include "settings.h" 
#include "player.h" 
#include "meteor.h" 
#include <vector> 
#include "laser1.h" 

class Game {
private:
	sf::RenderWindow window;
	std::vector<Meteor*> meteorSprites;
	Player player;

	void chackEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}


	void Update() {
		player.Update();
		for (auto meteor : meteorSprites) {
			meteor->update();
		}
	}

	void chackCollisions() {

	}

	void Draw() {
		window.clear();
		for (auto meteor : meteorSprites) {
			window.draw(meteor->getSprite());
		}
		player.Draw(window);
		window.display();
	}

public:
	Game() {
		sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
		window.create(videoMode, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(METEORS_QTY);
		for (int i = 0; i < METEORS_QTY; i++) {
			Meteor* m = new Meteor();
			meteorSprites.push_back(new Meteor());
		}
	}
	void play() {
		while (window.isOpen()) {
			chackEvents();
			Update();
			chackCollisions();
			Draw();
		}
	}
};