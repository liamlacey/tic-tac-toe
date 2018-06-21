//
//  main.cpp
//  tic-tac-toe
//
//  Created by Liam Lacey on 20/06/2018.
//  Copyright © 2018 Liam Lacey. All rights reserved.
//

#include <iostream>
#include "TicTacToe.h"

void displayGrid (int gridSize, TicTacToe ticTacToe);

//==============================================================
int main(int argc, const char * argv[])
{
    const int gridSize = 3;
    
    TicTacToe tickTacToe(gridSize);
    
    //Display welcome message and instructions
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Player 1 is 'o', Player 2 is 'x'.\n";
    
    displayGrid (gridSize, tickTacToe);
    
    std::cout << "Player " << tickTacToe.getCurrentPlayer() + 1 << ", select a grid position...\n";
    
    return 0;
}

//==============================================================
void displayGrid (int gridSize, TicTacToe ticTacToe)
{
    const int gridPosHeight = 3;
    int gridPosCounter = 1;
    
    std::cout << "\n";
    
    for (int row = 0; row < gridSize; row++)
    {
        for (int rowSub = 0; rowSub < gridPosHeight; rowSub++)
        {
            for (int col = 0; col < gridSize; col++)
            {
                std::cout << "\t";
                if (rowSub == gridPosHeight / 2)
                {
                    if (ticTacToe.getStateForGridPosition(gridPosCounter - 1) == 0)
                        std::cout << gridPosCounter;
                    else if (ticTacToe.getStateForGridPosition(gridPosCounter - 1) == 1)
                        std::cout << "o";
                    else
                        std::cout << "x";
                    
                    
                    gridPosCounter++;
                }
                std::cout << "\t";
                
                if (col != gridSize - 1)
                    std::cout << "|";
            }
            
            std::cout << "\n";
        }
        
        if ( row != gridSize - 1)
        {
            
            for (int col = 0; col < gridSize; col++)
            {
                if( col == 0)
                    std::cout << "-";
                    
                std::cout << "\t\t";
                
                if (col == gridSize-1)
                    std::cout << "-";
                
                if (col != gridSize - 1)
                    std::cout << "+";
            }
        }
        
        std::cout << "\n";
    }
    
    std::cout << "\n";
}



