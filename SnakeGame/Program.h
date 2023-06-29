#pragma once

#include "Snake.h"
#include "Apple.h"
#include "SnakeControl.h"

#include <string>
#include <memory>

class Program final {
private:
	using backgroundColor = sf::Color;
public:
	Program(const std::string& windowName = "Window",
		const sf::Vector2f& windowSize = sf::Vector2f(1280, 720));
	Program(const Program& other) = delete;
	Program& operator=(const Program& other) = delete;
	Program& operator=(const Program&& other) = delete;
	Program(const Program&& other) = delete;
	~Program() = default;

	void start();
private:
	void eventHandling();
	void display();
private:
	sf::RenderWindow window;
	Snake snake;
	Apple apple;
	SnakeControl snakeControl;
	sf::Clock clock;
	float deltaTime = 0.f;
};

