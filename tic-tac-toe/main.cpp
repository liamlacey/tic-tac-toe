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
    const auto gridSize = 3;
    const auto numOfGridSlots = gridSize * gridSize;
    TicTacToe tickTacToe(gridSize);
    
    auto shouldExit = false;

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Player 1 is 'o', Player 2 is 'x'.\n";
    
    //main loop that will only exit user requests to
    do
    {
        displayGrid (gridSize, tickTacToe);
        
        std::cout << "Player " << tickTacToe.getCurrentPlayer() + 1 << ", select a grid position...\n";
        
        auto input = 0;
        auto result = 0;
        
        //loop to set the grid position state, exit once successfully done this
        do
        {
            //loop to get a valid number input, exit once got a valid input
            do
            {
                std::cin >> input;
                
                //if not got a valid number input
                if (!(input >= 1 && input <= numOfGridSlots))
                {
                    std::cout << "Invalid input - please try again." << std::endl;
                    //clear error flag on cin, and ignore anything else on same line
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                }
                
            } while (!(input >= 1 && input <= numOfGridSlots));
            
            result = tickTacToe.setGridPositionStateForCurrentPlayer(input - 1);
            
            //if got an error attempting to set grid position stat
            if (result == -1)
            {
                std::cout << "The grid position is already being used - please try again." << std::endl;
            }
            
        } while (result == -1);

        tickTacToe.moveToNextPlayer();
        
    } while (!shouldExit);
    
    return 0;
}

//==============================================================
void displayGrid (int gridSize, TicTacToe ticTacToe)
{
    const auto gridPosHeight = 3;
    auto gridPosCounter = 1;
    
    std::cout << "\n";
    
    for (auto row = 0; row < gridSize; row++)
    {
        for (auto rowSub = 0; rowSub < gridPosHeight; rowSub++)
        {
            for (auto col = 0; col < gridSize; col++)
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
        
        if (row != gridSize - 1)
        {
            for (auto col = 0; col < gridSize; col++)
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



