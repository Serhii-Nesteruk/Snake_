#include "Program.h"

#include <iostream>

using namespace std;

int main() {
	try {
		srand(time(nullptr));
		Program program("Snake", sf::Vector2f(600, 600));
		program.start();
	}
	catch (const std::exception& error) {
		cout << "---------------------" << endl;
		cout << error.what() << endl;
		cout << "---------------------" << endl;
	}
	return 0;
}