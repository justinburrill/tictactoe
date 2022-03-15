#include <iostream>
#include <vector>
#include <math.h>

bool playerMove = true; // true for X
bool gameOn = true;
char tokens[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// char board[11][11] = {};
// char board[3][3] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};

bool checkValidMove(int x, int y)
{
    if (x > sqrt(sizeof(tokens)) or y > sqrt(sizeof(tokens)))
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

    std::string str;
    for (int i = 0; i < sqrt(sizeof(tokens)); i++)
    {
        for (int j = 0; j < sqrt(sizeof(tokens)); j++)
        {
            str += tokens[i][j];
        }
        std::cout << str << "\n";
        str = "";
    }
}

bool checkGameOver()
{
    for (int i = 0; i < sqrt(sizeof(tokens)); i++)
    {
        
    }
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
    int x = static_cast<int>(floor(pos / 3));
    int y = pos % 3;
    if (checkValidMove(x, y))
    {
        tokens[x][y] = token;
        playerMove = !playerMove;
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
        getMove();
        drawBoard();
    }
}