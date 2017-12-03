// OneDay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <random>


using namespace std;

//function prototype
void readFile(string, string[], const int);
void intro();
void startGame(int, const int, string[], string[]);
void credits();
void finish();

int main()
{
	//store data from files in arrays
	const int size = 14;	//number of choices / paragraphs in narrative
	string narrative[size];	//store narrative
	string choices[size];	//store choices

	string fileName;
	int mainOption;

	fileName = "narrative.txt";	//name of file with narrative
	readFile(fileName, narrative, size);

	fileName = "choices.txt";	//name of file with choices
	readFile(fileName, choices, size);

	//display intro
	intro();

	//Prompt user to - startgame, see credits or exit
	cout << endl;
	cout << endl << "Welcome to One Day! Type the following number to:" << endl;

	bool exitOption = false;
	while (!exitOption)
	{
		cout << endl << "1. Play Game." << endl << "2. Credits. " << endl << "3. Exit (available during the game too)." << endl;
		cin >> mainOption;

		switch (mainOption)
		{
		case 1:
		{
			startGame(mainOption, size, choices, narrative);
			break;
		}
		case 2:
		{
			credits();
			break;
		}
		case 3:
		{
			exitOption = true;
			break;
		}
		default:
		{
			cout << "Please, choose 1, 2 or 3.";
		}
		}
	}
	finish();
	exit(0);
}

//Read from file
void readFile(string fileName, string foo[], int size)
{
	string line;
	int i = 0;

	ifstream myfile;

	myfile.open(fileName);

	//store lines in the same element
	//when character '*' is found move to the next element
	for (int i = 0; i < size; i++)
	{
		while (getline(myfile, line))
		{
			if (line == "*")	//ignore line with *
			{
				break;
			}
			else
			{
				foo[i] += line;

			}
		}
	}
	myfile.close();
}

void printChoicesFromArray(string choices[], int i, bool swapChoices)
{
	//Print choices from array
	if (!swapChoices)
	{
		cout << endl << choices[i] << endl;
		cout << choices[i + 1] << endl;
	}
	else
	{
		cout << endl << choices[i + 1].replace(0, 1, "1") << endl;
		cout << choices[i].replace(0, 1, "2") << endl;
	}
}

//Test if player wants to exit the game
bool isExitChoice(int choice)
{
	bool result;
	result = false;
	if (choice == 3)
	{
		cout << "Exit this Game (Y/N)?";
		char exitYN;
		cin >> exitYN;
		if (exitYN == 'Y' || exitYN == 'y')
		{
			result = true;
		}
	}
	return result;
}

void startGame(int choice, int size, string choices[], string narrative[])
{
	//Display scenario
	cout << "Go to school and attend classes.";

	//Display narrative 1
	cout << "You decide to go to school after all. Might as well act like an adult. \nAs you go from class to class the day seems to get shorter. It is 2:00 pm and you have one final class. \nAs you make your way to your last class you see a small group in the distance. The group turns out to be four boys. Three are kicking the life out of one of them. \nWhat do you do? " << endl;

	//Loop through all the story/decisions
	for (int i = 0; i < size; i += 2)
	{
		//Generate random bool to swap choices
		random_device rd;
		mt19937 gen(rd());
		bernoulli_distribution coin_flip(0.5);
		bool swapChoices = coin_flip(gen);

		//Print choices from array
		printChoicesFromArray(choices, i, swapChoices);
		cin >> choice;
		cout << endl;

		//Test if player wants to exit the game (choice is 3)
		bool exitChoice = isExitChoice(choice);

		bool badChoice = ((choice == 1 && !swapChoices) || (choice == 2 && swapChoices));

		//Bad choice or a choice not available (bigger than 3 or equal) - keep asking to choose
		while (badChoice || choice>=3)
		{
			//Display the narrative of that choice
			if (badChoice)
			{
				cout << endl << narrative[i] << endl;
			}

			//Choice == 3 and wants to exit - Exit
			if (exitChoice)
			{
				break;
			}

			//Opportunity to choose 1 or 2 again
			printChoicesFromArray(choices, i, swapChoices);
			cin >> choice;
			cout << endl;

			//Test again if player wants to exit the game
			exitChoice = isExitChoice(choice);
			if (exitChoice)
			{
				break;	//Exit game
			}

			//Test if it's a bad choice 
			badChoice = ((choice == 1 && !swapChoices) || (choice == 2 && swapChoices));
		}

		//Exit choice
		if (exitChoice)
		{
			break;
		}

		//Good choice
		bool goodChoice = ((choice == 2 && !swapChoices) || (choice == 1 && swapChoices));
		if (goodChoice)
		{
			//Display the narrative of that choice
			cout << narrative[i + 1] << endl;
		}
	}
}

void intro()
{
	cout << "You start to hear a faint sound among the darkness. \nThe sound does not go away and starts to grow louder. Unable to ignore it for another minute, you find yourself becoming more aware. \nThe same goes for your senses. You realize that the sound is coming from the alarm clock. \nIt is Friday and you have college classes at AU University. You go on with your daily morning routine where you get ready and you eat breakfast. \nOnce done you begin to decide how you want to go about your day, after all, you are an adult.";
}

void credits()
{
	cout << "	   CREDITS" << endl;
	cout << "	   One Day" << endl << endl;
	cout << "	  Amy Garcia" << endl;
	cout << "	  Rene Garcia" << endl;
	cout << "	  Will Morgan" << endl;
	cout << "	 Brandon Perez" << endl;
	cout << "	Franklyn Medina" << endl;
	cout << endl;
}

void finish()
{
	cout << "Thanks for playing!" << endl;
}

