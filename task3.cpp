#include <iostream>
using namespace std;

char gameBoard[10] ={'o','1','2','3','4','5','6','7','8','9'};

int checkWin();
void displayBoard();

int main()
{
    int currentPlayer=1,choice,result;

    char marker;
    do
    {
        displayBoard();
        currentPlayer=(currentPlayer % 2)?1:2;

        cout<<"Player "<<currentPlayer<<", enter a number: ";
        cin >> choice;

        marker=(currentPlayer==1)?'X':'O';

        if (choice >= 1 && choice <= 9 && gameBoard[choice] == '1' + choice - 1)
            gameBoard[choice]=marker;
        else
        {
            cout<<"Invalid move ";
            currentPlayer--;
            cin.ignore();
            cin.get();
        }

        result=checkWin();
        currentPlayer++;

    } while (result==-1);

    displayBoard();

    if (result==1)
        cout<<"\aPlayer "<<--currentPlayer<<" wins!";
    else
        cout<<"\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

int checkWin()
{
    if (gameBoard[1] == gameBoard[2] && gameBoard[2] == gameBoard[3])
        return 1;
    else if (gameBoard[4] == gameBoard[5] && gameBoard[5] == gameBoard[6])
        return 1;
    else if (gameBoard[7] == gameBoard[8] && gameBoard[8] == gameBoard[9])
        return 1;
    else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7])
        return 1;
    else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8])
        return 1;
    else if (gameBoard[3] == gameBoard[6] && gameBoard[6] == gameBoard[9])
        return 1;
    else if (gameBoard[1] == gameBoard[5] && gameBoard[5] == gameBoard[9])
        return 1;
    else if (gameBoard[3] == gameBoard[5] && gameBoard[5] == gameBoard[7])
        return 1;
    else if (gameBoard[1] != '1' && gameBoard[2] != '2' && gameBoard[3] != '3' &&
             gameBoard[4] != '4' && gameBoard[5] != '5' && gameBoard[6] != '6' &&
             gameBoard[7] != '7' && gameBoard[8] != '8' && gameBoard[9] != '9')
        return 0;
    else
        return -1;
}

void displayBoard()
{
    cout<<"\n\n\tTic Tac Toe\n\n";

    cout<< "Player 1 (X)  -  Player 2 (O)"<<endl<<endl;
    cout<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  " << gameBoard[1] << "  |  "<< gameBoard[2]<< "  |  "<< gameBoard[3]<<endl;

    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;

    cout<<"  " << gameBoard[4]<<"  |  "<<gameBoard[5]<<"  |  "<<gameBoard[6]<<endl;

    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;

    cout<<"  "<< gameBoard[7]<< "  |  "<<gameBoard[8]<<"  |  "<<gameBoard[9]<<endl;

    cout<<"     |     |     "<<endl<<endl;
}

