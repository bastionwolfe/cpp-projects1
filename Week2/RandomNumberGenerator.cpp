#include <iostream>
#include <random>

// Function to generate a random number between a min and a max value
int generateRandomNumber(int min, int max) {
	int randNum = rand() % (max - min + 1) + min;
	return randNum;
}

//Function to grab input from user for a min number and confirm that it is a valid integer
int usermin() {
	int min;
	std::cout << "Enter a minimum number, no alphabetic characters: ";
	while (true) {
		std::cin >> min;
		if (std::cin.fail()) {
			std::cout << "invalid integer, please try again!\n";
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			return min;
		}
	}
}

//Function to grab input from user for a max number and confirm that it is a valid integer
int usermax() {
	int max;
	std::cout << "Enter a maximum number, no alphabetic characters: ";
	while (true) {
		std::cin >> max;
		if (std::cin.fail()) {
			std::cout << "invalid integer, please try again!\n";
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			return max;
		}
	}
}