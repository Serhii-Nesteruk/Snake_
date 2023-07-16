#include "Program.h"

#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	try {
		srand(time(nullptr));
		Program program("Snake", sf::Vector2f(600, 600));
		program.start();
	}
	catch (const std::exception& error) {
		MessageBoxA(nullptr, error.what(), "Error", MB_OK);
	}
    catch (const std::runtime_error& error) {
        MessageBoxA(nullptr, error.what(), "Error", MB_OK);
    }
	return 0;
}