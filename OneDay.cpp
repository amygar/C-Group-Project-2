// OneDay.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

//function prototype
void readFile(string, string[], const int);
void intro(int, string[]);
void startGame(int, const int, int[], string[], string[], string[], string[], string[], string[]);
void credits();
void finish();

int main()
{
    //Arrays to store choices and narratives
    const int size = 14;	    //number of choices / paragraphs in narrative
    string introNarrative[1];            //intro to game
    string choices[size];	    //choices
    string narrative[size];	    //choices narrative
    string loopsNarrative[size]; //narrative in loops
    string mainNarrative[5];    //main narratives
    string dependentNarrative[2]; //narrative that depends on previous choices

    //Store data from files to arrays
    string fileName;
    int mainOption;

    fileName = "introToGame.txt";	//name of file with intro
    readFile(fileName, introNarrative, size);

    fileName = "choices.txt";	//name of file with choices
    readFile(fileName, choices, size);

    fileName = "narrative.txt";	//name of file with narrative
    readFile(fileName, narrative, size);

    fileName = "loopsNarrative.txt";	//name of file with narrative inside the loops
    readFile(fileName, loopsNarrative, size);

    fileName = "mainNarrative.txt";	//name of file with main narrative
    readFile(fileName, mainNarrative, size);

    fileName = "dependentNarrative.txt";	//name of file with dependent narrative- depends on first decision
    readFile(fileName, dependentNarrative, size);

    //Arrays to keep track of player choices
    int playerChoices[3];

    //Arrays to store the choices that lead to different endings
    int worstEnding[3] = {1, 2, 1}; //1,4,5
    int imperfectEnding[3] = {2, 2, 1}; //2,4,5
    int bestEnding[3] = {2, 2, 2};  //2,4,6

    //Prompt user to - start game, see credits or exit
    cout << "Welcome to One Day! Type the following number to:" << endl;

    bool exitOption = false;
    while (!exitOption)
    {
        cout << endl << "1. Play Game." << endl << "2. Credits. " << endl << "3. Exit(available during the game too)." << endl;
        cin >> mainOption;

        switch (mainOption)
        {
        case 1:
        {
            //display intro
            intro(1, introNarrative);
            startGame(mainOption, size, playerChoices, introNarrative, choices, narrative, loopsNarrative, mainNarrative, dependentNarrative);
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
                foo[i] += line + "\n";

            }
        }
    }
    myfile.close();
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

//Test if input is valid
int inputValid(int choice)
{
    while (!choice)
    {
        cin.clear();
        cin.ignore(80, '\n');
        cout << "Please, enter an integer" << endl;
        cin >> choice;
    }
    return choice;
}

void startGame(int choice, int size, int playerChoices[], string intro[], string choices[], string narrative[], string loopsNarrative[], string mainNarrative[], string dependentNarrative[])
{
    string playerName;

    //Decision #1
    //Print choices from array
    cout << endl << choices[0] ; //ignore
    cout << choices[1] << endl;  //intervene
    cin >> choice;

    //Test if input is valid
    choice = inputValid(choice);
    cout << endl;
    playerChoices[0] = choice; //store player choice in array

    //Print narrative according to the value of choice
    //Exit if choice is 3
    if (choice == 1)
    {
        cout << endl << narrative[0] << endl;
    }
    else if (choice == 3)
    {
        //exit
        isExitChoice(choice);
    }
    else if(choice ==2) //good choice
    {
        cout << endl << narrative[1] << endl;
    }
    else
    {
        cout << "Please, choose 1 or 2.";
    }

    //MAIN NARRATIVE
    cout << mainNarrative[0];

    //Decision #2
    cout << endl << choices[2]; //ignore
    cout << choices[3] << endl;  //follow
    cin >> choice;

    //Test if input is valid
    choice = inputValid(choice);
    cout << endl;
    playerChoices[1] = choice; //store player choice in array

    //Print narrative according to the value of choice
    //Exit if choice is 3
    switch (choice)
    {
    case 1:
    {
        //show narrative for that choice
        cout << narrative[2] << endl;

        //Loop #1
        while (choice == 1) //player decided to ignore
        {
            //show narrative for that loop 1 //create array for loops*
            cout << endl << loopsNarrative[0] << endl;

            //show choices again
            cout << endl << choices[2]; //ignore
            cout << choices[3]; //follow
            cin >> choice;

            //Test if input is valid
            choice = inputValid(choice);
            cout << endl;
            playerChoices[1] = choice; //store player choice in array
        }
    }
    case 2:
    {
        cout << endl << narrative[3] << endl;   //decided to follow
        break;
    }
    case 3:
    {
        //exit
        isExitChoice(choice);
        break;
    }
    default:
    {
        cout << "Please, choose 1 or 2.";
    }
    }

    //Decision #3
    //Print choices from array
    cout << endl << choices[4]; //inform
    cout << choices[5]; //convince
    cin >> choice;

    //Test if input is valid
    choice = inputValid(choice);
    cout << endl;
    playerChoices[2] = choice; //store player choice in array

    //Print narrative according to the value of choice
    //Exit if choice is 3
    switch (choice )
    {
    case 2:
    {
        cout << endl << narrative[5] << endl;

        //Following path depends on decision 1

        //Player chose 1 (ignore)on first decision
        if (playerChoices[0] == 1)
        {
            cout << "The boy asks for your name: " << endl;
            cin >> playerName;
            cout << "Okay" << playerName << " …" << " Why are you here?" << endl;
            cout << "I am here to convince you that what you are about to do is wrong." << endl;

            //Show rest of dependent narrative
            cout << dependentNarrative[0] << endl;

            //Loop #2
            while(choice == 2)  //keeps deciding to convince (choice 5)
            {
                //Show narrative for that loop 2
                cout << endl << loopsNarrative[1] << endl;

                //Give the player the opportunity to inform or convince again
                //Print choices from array
                cout << endl << choices[4]; //inform
                cout << choices[5]; //convince
                cin >> choice;

                //Test if input is valid
                choice = inputValid(choice);
                cout << endl;
                playerChoices[2] = choice; //store player choice in array
            }
        }   //don't break to continue with case 1

        //Player chose 2 (intervene)on first decision
        else if(playerChoices[0] == 2)
        {
            cout << dependentNarrative[0] << endl;
            cout << "He tells you that his name is Lars and you introduce yourself to him as: ";
            cin >> playerName;
            cout << "Before going on your separate ways you invite him over to your house around late afternoon. He, of course, agrees." << endl;
            cout << mainNarrative[3];
            cout << mainNarrative[4];
            break;
        }
    }
    case 1:
    {
        cout << endl << narrative[4] << endl;
        //Show main narrative 2 //worst imperfect ending
        cout << mainNarrative[1];

        //Show main narrative 3 ////worst imperfect ending
        cout << mainNarrative[2];
        break;
    }
    case 3:
    {
        //exit
        isExitChoice(choice);
        break;
    }
    default:
    {
        cout << "Please, choose 1 or 2.";
    }
    }
}

void intro(int size, string introNarrative[] )
{
    cout << endl << introNarrative[0] << endl;
}

void credits()
{
    cout << "	   CREDITS" << endl;
    cout << "	   One Day" << endl << endl;
    cout << "	  Amy Garcia" << endl;
    cout << "	  Rene Garcia" << endl;
    cout << "	 William Morgan" << endl;
    cout << "	 Brandon Perez" << endl;
    cout << "	Franklyn Medina" << endl;
    cout << endl;
}

void finish()
{
    cout << "Thanks for playing!" << endl;
}
