#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void main() {
	srand(time(NULL));
	bool game = 1;

	while (game) {
		int winningDoor = rand() % 3 + 1;
		int chabeloDoor = 0;
		int userChoice = 0;
		string userChoice2 = "";

		cout << "Chabelo: Welcome to Catafixia" << endl << endl;

		cout << "Chabelo: Which door do you want to pick? (1, 2, 3)" << endl << endl;

		cout << "Catafixiabot: I have a 33.333% chance of choosing the right door" << endl;

		userChoice = rand() % 3 + 1;
		cout << "Catafixia bot picks door " << userChoice << endl << endl;

		cout << "Chabelo: Great choice, now I'll open a door" << endl;
		cout << "Catafixiabot: Chabelo has a 33.333% chance of choosing the right door" << endl << endl;

		while (chabeloDoor == userChoice || chabeloDoor == 0) {
			chabeloDoor = rand() % 3 + 1;
		}

		cout << "*Chabelo opens door " << chabeloDoor << "*" << endl << endl;

		if (chabeloDoor == winningDoor) {
			cout << "There was a Ferrari behind the door!" << endl;
			cout << "Chabelo won!  Better luck next time!" << endl;
		}
		else {
			cout << "There was a tamales cart behind the door!" << endl;
			cout << "Chablelo: Do you want to change your choice? (y/n)" << endl << endl;
			cout << "Catafixiabot: I have a 50% chance of choosing the right door, better odds than I had for my last decision (33.333%)" << endl;
			
			userChoice2 = 'y';

			if (userChoice2[0] == 'y') {
				for (int i = 1; i < 4; i++) {
					if (i != userChoice && i != chabeloDoor) {
						cout << "Catafixiabot changes its choice to door " << i << endl << endl;
						userChoice = i;
						i = INT16_MAX;
					}
				}
			}
			else {
				cout << "You stick with door " << userChoice << endl;
			}

			cout << "Chabelo: Let's see if you won!" << endl;
			cout << "*Chabelo opens door " << userChoice << " for you*" << endl << endl;

			if (userChoice == winningDoor) {
				cout << "There was a Ferrari behind the door!  Congratulations, you won!" << endl;
			}
			else {
				cout << "There was a tamales cart behind the door!  Better luck next time!" << endl;
			}
			userChoice2 = "";
		}

		cout << endl << "Play again? (y/n)" << endl;

		while (userChoice2 != "y" && userChoice2 != "n") {
			getline(cin, userChoice2);
			if (userChoice2 != "y" && userChoice2 != "n") {
				cout << "Please input a valid character" << endl;
			}
		}

		cout << endl << endl;

		if (userChoice2[0] == 'n') {
			game = 0;
		}
		else {
			userChoice2 = "";
		}
	}
}