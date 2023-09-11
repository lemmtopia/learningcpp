// Rock paper scissors game

#include <iostream>
#include <random>
#include <time.h>

int main() {
	std::srand(std::time(NULL)); // "random" seeding
	char again = 'y';
	
	while (std::tolower(again) == 'y') {
		std::cout << "Rock paper scissors!!" << std::endl;
		std::cout << "Type your move(r, p, s): ";

		char input;
		std::cin >> input;

		while (std::tolower(input) != 'r' && std::tolower(input) != 'p' && std::tolower(input) != 's') {
			std::cout << "Type your move(r, p, s): ";
			std::cin >> input; //ask again
		}

		/* actual game logic */
		int choice = -1;
		int myChoice = std::rand() % 3;

		if (std::tolower(input) == 'r') choice = 0;
		if (std::tolower(input) == 'p') choice = 1;
		if (std::tolower(input) == 's') choice = 2;

		int winner = -1; // display the object, not the player
		int counters[3] = { 1, 2, 0 }; // array of winners 

		if (myChoice == counters[choice]) { // okay this is kinda clever and cool
			winner = myChoice;
		}
		else {
			if (myChoice == choice) winner = -1;
			else winner = choice;
		}

		std::string words[3] = { "Rock", "Paper", "Scissors" };

		std::cout << "You've chosen " << words[choice] << " and I've chosen " << words[myChoice] << std::endl;

		if (winner != -1) {
			std::cout << words[winner] << " won!" << std::endl;
		}
		else {
			std::cout << "It's a draw!!" << std::endl;
		}

		std::cout << "Would you like to play again(y, any other key)? ";
		std::cin >> again;
	}

	return 0;
}