#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <Windows.h>
#include <fstream>

using namespace std;
using namespace std::this_thread;
string openCase();
bool checkDuplicate(string hand[], string aCard);
void dealCase(string hand[]);


int main()
{
	// Generate new random numbers each time the program is run
	srand(time(NULL));

	// Creates an option menu
	int option = 0;
	bool stop = false;

	while (stop != true)
	{
		cout << "*********" << endl;
		cout << "CSGO Crate Simulator" << endl;
		cout << "*********" << endl << endl;
		cout << "1. Play" << endl;
		cout << "2. Exit" << endl << endl;
		cout << "Choose your option: ";
		cin >> option;
		ofstream myfile;
		myfile.open("example.txt");
		
		if (option != 2) {
			int caseOption;
			// Deal 1 case to the player

			cout << "What case would you like to open?. " << endl;
			cout << "1. Prisma case\n2. Chroma 2\n";
			cin >> caseOption;
			if (caseOption == 1)
			{
				
			}
			int barl = 70;
		
			cout << "\nWait Patiently as we unlock your crate!\n" << endl;
			cout << "[";
			for (int i = 0; i < barl; i++) {
				Sleep(100);
				cout << ":";
			}
			cout << "]";

			cout << "\nCongratulations You have just unlocked" << endl;
			sleep_for(1s);
			string hand[1] = { ""};
			dealCase(hand);
			for (int i = 0; i < 1; i++)
			{
				cout << endl << hand[i];
				myfile << "Inventory\n" << hand[i];
				
			}
				




			// Pause program
			cin.ignore(256, '\n');
			cout << endl << "Hit return to continue...";
			cin.get();
			system("CLS");
		}
		else {
			stop = true;
		}
		
	}

	return 0;
}

// Returns a card from the deck
string openCase()
{
	string card;

	
	int prismaCase = (rand() % 17 +1);

	

	

	string value;

	switch (prismaCase)
	{
	
	case 1: value = "MP7 | Mischief"; break;
	case 2: value = "MAC-10 | Whitefish"; break;
	case 3: value = "Galil | Akoben"; break;
	case 4: value = "P90 | Off World"; break;
	case 5: value = "P250 | Verdigris"; break;
	case 6: value = "FAMAS | Cryspis"; break;
	case 7: value = "AK-47 | Uncharted"; break;
	case 8: value = "TEC-9 | Bamboozle"; break;
	case 9: value = "UMP-45 | Moonrise"; break;
	case 10: value = "MP5-SD | Gauss"; break;
	case 11: value = "Desert Eagle | Light Rail"; break;
	case 12: value = "AWP | Atheris"; break;
	case 13: value = "R8 Revolver | Skull Crusher"; break;
	case 14: value = "XM1014 | Incinegator"; break;
	case 15: value = "AUG | Momentum"; break;
	case 16: value = "Five SeveN | Angry Mob"; break;
	case 17: value = "M4A4 | The Emporer"; break;
	
	}

	card = value;

	return card;
}








// Returns true when a given cards already exists within the hand
bool checkDuplicate(string hand[], string aCard)
{
	bool duplicate = false;

	for (int i = 0; i < 5; i++) {
		if (hand[i] == aCard)
			duplicate = true;
	}

	return duplicate;
}




// Opens one case, random skin to player
void dealCase(string hand[])
{
	for (int i = 0; i < 1; i++) {
		string j = openCase();
		if (checkDuplicate(hand, j) == true)
			i--;
		else
			hand[i] = j;
	}
}

