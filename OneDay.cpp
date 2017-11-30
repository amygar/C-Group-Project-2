#include <iostream>
#include <string>
using namespace std;

//prototype functions
void choice1 ();    //function to develop choice1

int main()
{
    int choice;
    
    //Before game starts
    cout << "Welcome to One Day! Type the following number to:" << endl;
    cout << "1. Start Game." << endl << "2. Credits. " << endl "3. Exit.";

    //Introduction
    cout << "You hear a faint sound amongst the darkness. The sound doesn’t go away and starts to grow even louder. Unable to ignore it for another minute, you find yourself becoming more aware." << endl
    << "You realize that the sound is coming from your alarm clock. It’s Friday and you must go to school   you go on with your daily morning routine where you get ready and you eat breakfast." << endl
    << "Once done you begin to decide how you want to go about your day after all you can’t just sit around your room all day. "

    <<"1. Go to school and attend classes." <<endl;

    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            cout <<"You decide to go to school after all. Might as well act responsibly like an adult." << endl
                << "As you go from class to class the day seems to get shorter. It is 2:00 pm and you have one final class." << endl
                << "As you make your way to your last class you see a small group in the distance. The groups turns out to be four boys.\n Three are kicking the life out of one of them.\n\n What do you do?\n";
                break;
            
                choice1 ();     //goes to subchoices         
        }
      
    }

}
