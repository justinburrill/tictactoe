#include <iostream>
#include <vector>
#include <math.h> 

char tokens[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
// char board[11][11] = {};
// char board[3][3] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};

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
    
}

void place(char token, int pos)
{

    tokens[pos - pos%3][pos%3] = token;
    // if (token == 'X')
    // {
    //     board[]
    // }
}

int main()
{
    
    std::cout << "-----Welcome to TicTacToe-----\n";
    std::cout << "Select 1 or 2 player mode: \n";
    int mode;
    std::cin >> mode;
    drawBoard();
}