#include <iostream>
#include <vector>
#include <math.h>

int moveCount = 0;

bool playerMove = true; // true for X
bool gameOn = true;
char tokens[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// char board[11][11] = {};
// char board[3][3] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};

bool checkValidMove(int x, int y)
{
    if (x > sqrt(sizeof(tokens)) - 1 or y > sqrt(sizeof(tokens)) - 1)
    {
        std::cout << "-- Invalid move: number out of bounds --\n";
        return false;
    }
    else if (tokens[x][y] == 'X' or tokens[x][y] == 'O')
    {
        std::cout << "-- Invalid move: square taken --\n";
        return false;
    }
    return true;
}

void drawBoard()
{
    // int drawsize = 20;
    // std::string str;
    // for (int i = 0; i < sqrt(sizeof(tokens)); i++)
    // {
    //     for (int j = 0; j < sqrt(sizeof(tokens)); j++)
    //     {
    //         // std::cout << "i: " << i << " j: " << j << "\n";
    //         str += board[i][j];
    //     }
    //     std::cout << str << "\n";
    //     str = "";
    // }

    // create string
    std::string str;
    // for each line & column of the board,
    for (int i = 0; i < sqrt(sizeof(tokens)); i++)
    {
        for (int j = 0; j < sqrt(sizeof(tokens)); j++)
        {
            // add the char to the string
            str += tokens[i][j];
        }
        // print the string
        std::cout << str << "\n";
        // clear the string
        str = "";
    }
}

bool playerWon()
{
    bool column = false, row = true;
    for (int i = 0; i < sqrt(sizeof(tokens)); i++)
    {
        // for each column, check each row, if they don't match, return false
        //
        char c = tokens[i][0];  // column
        char c2 = tokens[0][i]; // row

        for (int j = 0; j < sqrt(sizeof(tokens)); j++)
        {
            if (tokens[i][j] != c)
            {
                column = false;
            }
            if (tokens[j][i] != c2)
            {
                row = false;
            }
        }
    }
    return column or row;
}

void place(char token, int pos)
{
    /*

        0 = 0,0
        1 = 0,1
        2 = 0,2
        3 = 1,0
        4 = 1,1
        5 = 1,2
        6 = 2,0
        7 = 2,1
        8 = 2,2
        y = floor(int(pos)/3)
        x = int(pos) % 3
    */
    // convert one value to x,y coords
    int x = static_cast<int>(floor(pos / 3));
    int y = pos % 3;

    if (checkValidMove(x, y))
    {
        // set the char to the player's token
        tokens[x][y] = token;
        // other player's turn
        playerMove = !playerMove;
        moveCount++;
    }

    // if (token == 'X')
    // {
    //     board[]
    // }
}

void getMove()
{
    char playerName;
    if (playerMove)
    {
        playerName = 'X';
    }
    else
    {
        playerName = 'O';
    }
    std::cout << playerName << ", your turn to move: ";
    int pos;
    std::cin >> pos;
    place(playerName, pos - 1);
}

int main()
{

    std::cout << "-----Welcome to TicTacToe-----\n";
    std::cout << "Select 1 or 2 player mode: \n";
    int mode;
    std::cin >> mode;
    drawBoard();
    while (gameOn)
    {
        if (!playerWon())
        {
            if (moveCount >= sizeof(tokens))
            {
                std::cout << "-- TIE --\n";

                break;
            }
            getMove();
            drawBoard();
        }
    }
    if (playerWon())
    {
        char winner = 'O';
        if (playerMove)
        {
            winner = 'X';
        }
        std::cout << "-- " << winner << " won! --\n";
    }
}