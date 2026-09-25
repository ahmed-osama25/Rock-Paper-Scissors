#include<iostream>
#include<ctime>

using namespace std;

class RockPaperScissors
{
private:

    int playerchoice;

    int computerchoice;

    int playerscore = 0;

    int computerscore = 0;

public:

    void showmenu()
    {
        cout << "==============================\n";
        cout << "    ROCK PAPER SCISSORS\n";
        cout << "==============================\n";
        cout << "1. Play\n";
        cout << "2. Show Score\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> playerchoice;
    }

    void playerinput()
    {

        do
        {
            cout << "1. Rock\n";
            cout << "2. Paper\n";
            cout << "3. Scissors\n";
            
        }while(playerchoice < 1 || playerchoice >3);

    }

    void computerinput()
    {
        computerchoice = rand() % 3 + 1;
    }

    string getchoicename(int choice)
    {
        if(choice == 1)
        {
            return "Rock";
        }

        else if(choice == 2)
        {
            return "Paper";
        }

        else
        {
            return "Scissors";
        }

    }

    void determinewinner()
    {

        cout << "\nYou chose: " << getchoicename(playerchoice);
        cout << "\nComputer chose: " << getchoicename(computerchoice) << "\n";

        if(playerchoice == computerchoice)
        {
            cout << "Draw!\n";
        }

        else if(
            (playerchoice == 1 && computerchoice == 3) ||
            (playerchoice == 2 && computerchoice == 1) ||
            (playerchoice == 3 && computerchoice == 2)
        )
        {

            cout << "You Win!\n";

            playerscore++;
        }

        else
        {

            cout << "Computer Wins!\n";

            computerscore++;
        }

    }

    void displayscore()
    {
        cout << "\n===== SCORE =====\n";
        cout << "Player: " << playerscore << "\n";
        cout << "Computer: " << computerscore << "\n";
    }

    bool playagain()
    {
        char choice;

        cout << "\nPlay Again ?(y/n)";
        cin >> choice;

        return choice == 'y' || choice == 'Y';
    }

    void clearscreen()
    {
        system("cls");
    }

    void pausescreen()
    {
        system("pause");
    }
 
};

int main()
{
    srand(time(0));

    RockPaperScissors game;

    int choice;

    do
    {

        game.clearscreen();

        game.showmenu();

        cin >> choice;

        switch(choice)
        {
        case 1:
            game.clearscreen();
 
            game.playerinput();

            game.computerinput();

            game.determinewinner();

            game.displayscore();

            game.pausescreen();

            break;
        case 2:
            game.clearscreen();
            
            game.displayscore();

            game.pausescreen();

            break;

        case 3:
            cout << "\nThanks for playing!\n";

            break;

        default:
            cout << "Invalid Choice!\n";

            game.pausescreen();
        }

    }while(choice != 3);

    return 0;
}