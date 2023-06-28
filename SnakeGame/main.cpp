#include "Program.h"

#include <iostream>

using namespace std;

int main() {
	try {
		srand(time(nullptr));
		Program program("Snake");
		program.start();
	}
	catch (const exception& error) {
		cout << "---------------------" << endl;
		cout << error.what() << endl;
		cout << "---------------------" << endl;
	}

	return 0;
}