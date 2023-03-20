#pragma once 
#include <string> 
#include "SFML/Graphics.hpp" 
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 800.f };
const std::string WINDOW_TITLE{ "SFML Space_shooter" };
const unsigned int FPS{ 60 };

const std::string PLAYER_FILE_NAME = "images\\playerShip2_orange.png";
const float PLAYER_WIDTH = 99.f;
const float PLAYER_HEIGHT = 75.f;
sf::Vector2f PLAYER_START_POS{ (WINDOW_WIDTH - PLAYER_WIDTH) / 2.f,WINDOW_HEIGHT - PLAYER_HEIGHT };

float PLAYER_SPEEDX = 5.f;

const int METEORS_QTY = 10;

const std::string LASER_FILE_NAME = "images\\laser.png";
const float SPEED_LASER = -15.f;