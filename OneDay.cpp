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
void exit();

int main()
{
	//store data from files in arrays
	const int size = 14;	//number of choices / paragraphs in narrative
	string narrative[size];	//store narrative
	string choices[size];	//store choices

	string fileName;
	int choice;

	fileName = "narrative.txt";	//name of file with narrative
	readFile(fileName, narrative, size);

	fileName = "choices.txt";	//name of file with choices
	readFile(fileName, choices, size);

	//display intro
	intro();

	//Prompt user to - startgame, see credits or exit
	cout << "Welcome to One Day! Type the following number to:" << endl;
	cout << "1. Start Game." << endl << "2. Credits. " << endl << "3. Exit." << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		startGame(choice, size, choices, narrative);
		break;
	}
	case 2:
	{
		credits();
		break;
	}
	case 3:
	{
		exit();
		break;
	}
	default:
	{
		cout << "Please, choose 1, 2 or 3.";
	}
	}
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
		cout << choices[i] << endl;
		cout << choices[i + 1] << endl;
	}
	else
	{
		cout << choices[i + 1].replace(0,1,"1") << endl;
		cout << choices[i].replace(0, 1, "2") << endl;
	}
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
		//https://stackoverflow.com/questions/24417198/proper-boolean-random-generator-bernoulli-distribution
		random_device rd;
		mt19937 gen(rd());
		bernoulli_distribution coin_flip(0.5);
		bool swapChoices = coin_flip(gen);

		//Print choices from array 
		printChoicesFromArray(choices, i, swapChoices);

		cin >> choice;
		cout << endl;
		bool badChoice = ((choice == 1 && !swapChoices) || (choice == 2 && swapChoices));

		//bad choice
		while (badChoice)
		{
			//Display the narrative of that choice
			cout << narrative[i] << endl;

			//Opportunity to choose 1 or 2 again
			printChoicesFromArray(choices, i, swapChoices);

			cin >> choice;
			cout << endl;
			badChoice = ((choice == 1 && !swapChoices) || (choice == 2 && swapChoices));
		}

		//good choice
		if ((choice == 2 && !swapChoices) || (choice == 1 && swapChoices))
		{
			//Display the narrative of that choice
			cout << narrative[i + 1] << endl;
		}
		else
		{
			cout << "Please, choose 1 or 2.";
		}
	}
}

void intro()
{
	cout << "You start to hear a faint sound among the darkness. \nThe sound does not go away and starts to grow louder. Unable to ignore it for another minute, you find yourself becoming more aware. \nThe same goes for your senses. You realize that the sound is coming from the alarm clock. \nIt is Friday and you have college classes at AU University. You go on with your daily morning routine where you get ready and you eat breakfast. Once done you begin to decide how you want to go about your day, after all, you are an adult.";
}

void credits()
{
	cout << "	   One Day" << endl;
	cout << "	  Amy Garcia" << endl;
	cout << "	  Rene Garcia" << endl;
	cout << "	  Will Morgan" << endl;
	cout << "	 Brandon Perez" << endl;
	cout << "	Franklyn Medina" << endl;
}

void exit()
{
	cout << "Thanks for playing!" << endl;
}
