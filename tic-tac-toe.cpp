// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define computer 'X'
#define human 'O'
#define COMPUTER 1
#define HUMAN 0
void initialize(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '*';
        }
    }
}
void print(char board[3][3])
{
    cout << endl;
    cout << "\t\t\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "\t\t\t---+---+---" << endl;
    cout << "\t\t\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "\t\t\t---+---+---" << endl;
    cout << "\t\t\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
void instruction()
{
    cout << "Choose a cell numbered from 1 to 9 as below and play" << endl;
    cout << "\t\t\t 1 | 2 | 3 " << endl;
    cout << "\t\t\t---+---+---" << endl;
    cout << "\t\t\t 4 | 5 | 6 " << endl;
    cout << "\t\t\t---+---+---" << endl;
    cout << "\t\t\t 7 | 8 | 9 " << endl;
    cout << endl;
}
bool rowCrossed(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != '*')
        {
            return true;
        }
    }
    return false;
}
bool columnCrossed(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != '*')
        {
            return true;
        }
    }
    return false;
}
bool diagonalCrossed(char board[3][3])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != '*')
    {
        return true;
    }
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[1][1] != '*')
    {
        return true;
    }
    return false;
}
bool gameOver(char board[3][3])
{
    return (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}
int play(char whoseTurn)
{
    char board[3][3];
    int cellCnt = 0;
    initialize(board);
    int k = 0;
    while (cellCnt != 9 && gameOver(board) == false)
    {
        if (whoseTurn == HUMAN)
        {
            cout << "play your turn" << endl;
            int n;
            cin >> n;
            n--;
            int i = n / 3;
            int j = n % 3;
            if (board[i][j] == '*')
            {
                board[i][j] = human;
                print(board);
                cellCnt++;
                whoseTurn = COMPUTER;
            }
            else
            {
                cout << "Invalid input" << endl;
                cout << "Re-try" << endl;
                whoseTurn = HUMAN;
            }
        }
        else if (whoseTurn == COMPUTER)
        {

            int i = k / 3;
            int j = k % 3;

            if (board[i][j] == '*')
            {
                board[i][j] = computer;
                print(board);
                cellCnt++;
                whoseTurn = HUMAN;
                k = k + 1;
            }
            else
            {
                cout << "Invalid input" << endl;
                cout << "Re-try" << endl;
                return 0;
                whoseTurn = COMPUTER;
            }
        }
    }
    if (cellCnt < 9 && whoseTurn == HUMAN)
    {
        cout << "COMPUTER wins" << endl;
    }
    else if (cellCnt < 9 && whoseTurn == COMPUTER)
    {
        cout << "HUMAN wins" << endl;
    }
    else
    {
        cout << "DRAW" << endl;
    }
    return 0;
}
int start()
{
    char choice;
    char board[3][3];
    cout << "Wanna start first ??" << endl;
    cout << "Enter y for yes " << endl;
    cout << "Enter n for no " << endl;
    cout << "Enter x to end game " << endl;
    cin >> choice;
    if (choice == 'y')
    {
        instruction();
        play(HUMAN);
    }
    else if (choice == 'n')
    {
        instruction();
        play(computer);
    }
    else if (choice == 'x')
    {
        return 0;
    }
    else
    {
        cout << "Invalid Input" << endl;
        cout << "Re-try" << endl;
        start();
    }
    return 0;
}
int main()
{
    // initialize(board);
    start();
    // printboard(board);
    return 0;
}
