#include <iostream>
#include <string>
using namespace std;

//prototype functions
void startGame(string, int);
void credits(); 
void exit(); 

int main()
{
	int choice;
	string intro = "You hear a faint sound amongst the darkness. The sound doesn't go away and starts to grow even louder. \nUnable to ignore it for another minute, you find yourself becoming more aware. You realize that the sound is coming from your alarm clock. \nIt's Friday and you must go to school you go on with your daily morning routine where you get ready and you eat breakfast. \nOnce done you begin to decide how you want to go about your day after all you can't just sit around your room all day.";

	//Before game starts
	cout << "Welcome to One Day! Type the following number to:" << endl;
	cout << "1. Start Game." << endl << "2. Credits. " << endl << "3. Exit." << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		startGame(intro, choice);
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
	}
}

void startGame(string intro, int choice)
{
	//Introduction
	cout << intro << endl;
	cout << endl << "Scenario: Go to school and attend classes." << endl;
	cout << endl << "You decide to go to school after all. Might as well doing nothing gets you nowhere. \nAs you go from class to class the day seems to get shorter. \nIt is 2:00 pm and you have one final class. As you make your way to your last class you see a small group in the distance. \nThe group turns out to be four boys. Three are kicking the life out of one of them. What do you do?" << endl;
	cout << endl << "1. Ignore them and head straight for class." << endl
		 << "2. Intervene and stop them." << endl;

	cin >> choice;

	switch (choice)
	{
	case 1: //bad choice
	{
		while (choice == 1)
		{
			//explain scenario
			cout << endl << "You walk past them and head for class. You hear him screaming \"I will kill you all!\" from far away."
				 << "Paying no mind, you go on to your last class. \nJust minutes before class ends, gunshots are heard, and people are screaming." 
				 << "You go and check outside. Panic and confusion embrace you. \nWhile in shock you see the boy from earlier holding a gun. He points and you and fires a shot. \nYour death is evident. " 
				 << "You regret ignoring the incident now?" << endl;
			//Player has the opportunity to choose again
			cout << endl << "1. Ignore them again and head straight for class." << endl
				 << "2. Intervene and stop them." << endl;
			cin >> choice;
		}
	}
	case 2: //good choice
	{
		//continue good choice dialogue
		cout << endl << "You successfully stop the bullying by resorting to blackmailing. You and the boy get acquainted. His name is Lars. \nYou invite Lars to come by your place around late noon and solidify your new friendship. He agrees and you go to your final class.";
		cout << "School eventually ends and you start heading home. Time passes and late noon arrives. \nLars could knock at any second and rightfully so you hear what seems to be knocks. Do you?" << endl;

	}
	
}
}
void credits()
{

}
void exit()
{

}


