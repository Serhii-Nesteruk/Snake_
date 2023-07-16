#include "Program.h"

Program::Program(const std::string& windowName, const sf::Vector2f& windowSize) //TODO: magic numbers
	: snake(sf::Vector2f(windowSize.x / 2, windowSize.y / 2), sf::Color::Blue, 20),
    apple(sf::Vector2f(rand() % 600, rand() % 600), sf::Color::Red, 20),
	snakeControl(window, snake, apple, soundManager) {

	window.create(sf::VideoMode(windowSize.x, windowSize.y), windowName);
}

void Program::start() {
	while (window.isOpen()) {
		eventHandling();
		display();
	}

	// TODO:
	// GetWindow() -> RenderWindow&
	// GetWorld() -> Scene&
	// std::vector<Apple> data = GetWorld().GetSceneObjects<Apple>()
}

void Program::eventHandling() {
	sf::Event event;
	while (window.pollEvent(event))
		if (event.type == sf::Event::Closed)
			window.close();
}

void Program::display() {
	window.clear(backgroundColor::White);

	deltaTime = clock.restart().asSeconds();

	snakeControl.handleInput();
	snakeControl.update(deltaTime);
	snakeControl.checkWall();
	snakeControl.draw();

	window.display();
}