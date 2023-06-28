#include "Program.h"

Program::Program(const std::string& windowName, const sf::Vector2f& windowSize) { //TODO: magic numbers
	window.create(sf::VideoMode(windowSize.x, windowSize.y), windowName);

	snake = std::make_unique<Snake>(sf::Vector2f(windowSize.x/2, windowSize.y/2), sf::Color::Blue, 20);
	apple = std::make_unique<Apple>(sf::Vector2f(rand() % 1200, rand() % 550),
		sf::Color::Red, 20);

	snakeControl = std::make_unique<SnakeControl>(window, *snake.get(), *apple.get());
}

void Program::start() {
	while (window.isOpen()) {
		eventHandling();
		display();
	}
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

	snakeControl->handleInput();
	snakeControl->update(deltaTime);
	snakeControl->draw();

	window.display();
}
