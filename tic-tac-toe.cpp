#include <bits/stdc++.h>
using namespace std;
#define computer 'X'
#define human 'O'
#define COMPUTER 1
#define HUMAN 0
#define EASY 'e'
#define HARD 'h'
char difficulty;
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
int minimax(char board[3][3], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true)
    {
        if (isAI == true)
        {
            return -10;
        }
        if (isAI == false)
        {
            return +10;
        }
    }
    else
    {
        if (depth < 9)
        {
            if (isAI == true)
            {
                // COMPUTER
                if (difficulty == EASY)
                {
                    bestScore = 999;
                }
                else
                {
                    bestScore = -999;
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == '*')
                        {
                            board[i][j] = computer;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = '*';
                            if (score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                // HUMAN
                if (difficulty == EASY)
                {
                    bestScore = 0;
                }
                else
                {
                    bestScore = 999;
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == '*')
                        {
                            board[i][j] = human;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = '*';
                            if (score < bestScore)
                            {

                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
    }
    return 0;
}
int bestMove(char board[3][3], int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = computer;
                score = minimax(board, moveIndex + 1, false);
                board[i][j] = '*';
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}
int play(char whoseTurn)
{
    char board[3][3];
    int cellCnt = 0;
    initialize(board);
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
            int k = bestMove(board, cellCnt);
            int i = k / 3;
            int j = k % 3;
            board[i][j] = computer;
            print(board);
            cellCnt++;
            whoseTurn = HUMAN;
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
    cout << "\t\t\t\t"
         << "      Choose Level Difficulty " << endl;
    cout << "Enter e for EASY \t\t\t Enter h for HARD \t\t\t x to Exit game" << endl;
    cin >> difficulty;

    if (difficulty == 'x')
    {
        return 0;
    }
    if (difficulty != EASY && difficulty != HARD)
    {
        cout << "Invalid Input" << endl;
        cout << "Re-try" << endl;
        start();
    }
    cout << "Wanna start first ??" << endl;
    cout << "Enter y for yes \t\t\t n for no \t\t\t x to Exit game" << endl;
    cin >> choice;
    if (choice == 'y')
    {
        instruction();
        play(HUMAN);
    }
    else if (choice == 'n')
    {
        instruction();
        play(COMPUTER);
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
void intro()
{
    cout << "================================================================================" << endl;
    cout << endl;
    cout << "**************          **************             **************         " << endl;
    cout << "**************          **************             **************         " << endl;
    cout << "     **                       **                         **               " << endl;
    cout << "     **   **     ****         **   ****      ****        **   ***   ******" << endl;
    cout << "     **        ***            **  *    *   ***           **  *   *  **    " << endl;
    cout << "     **   **  ***     ***     **  ******  ***     ***    **  *   *  ****  " << endl;
    cout << "     **   **   ***            **  *    *   ***           **  *   *  **    " << endl;
    cout << "     **   **     ****         **  *    *     ****        **   ***   ******" << endl;
    cout << endl;
    cout << "================================================================================" << endl;
}
int main()
{
    intro();
    start();
    main();
    return 0;
}
