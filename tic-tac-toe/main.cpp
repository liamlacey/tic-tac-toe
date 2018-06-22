//
//  main.cpp
//  tic-tac-toe
//
//  Created by Liam Lacey on 20/06/2018.
//  Copyright © 2018 Liam Lacey. All rights reserved.
//

#include <iostream>
#include "TicTacToe.h"

void displayGrid (const int gridSize, TicTacToe &ticTacToe);
void choosePosition (const int numOfGridSlots, TicTacToe &ticTacToe);
bool checkGameStatus (const int gridSize, TicTacToe &ticTacToe);
void clearAndIgnoreCin();

//==============================================================
int main(int argc, const char * argv[])
{
    const auto gridSize = 3;
    TicTacToe ticTacToe(gridSize);
    const auto numOfGridSlots = gridSize * gridSize;
    auto shouldExit = false;
    
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Player 1 is 'x', Player 2 is 'o'.\n";
    
    //main loop that will only exit if user requests to
    do
    {
        displayGrid (gridSize, ticTacToe);
        
        choosePosition (numOfGridSlots, ticTacToe);
        
        shouldExit = checkGameStatus (gridSize, ticTacToe);
        
    } while (!shouldExit);
    
    std::cout << "Goodbye!" << std::endl;
    
    return 0;
}

//==============================================================
void displayGrid (const int gridSize, TicTacToe &ticTacToe)
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
                        std::cout << "x";
                    else
                        std::cout << "o";
                    
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

//==============================================================
void choosePosition (const int numOfGridSlots, TicTacToe &ticTacToe)
{
    std::cout << "Player " << ticTacToe.getCurrentPlayer() + 1 << ", select a grid position...\n";
    
    auto input = 0;
    auto setGridResult = 0;
    
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
                clearAndIgnoreCin();
            }
            
        } while (!(input >= 1 && input <= numOfGridSlots));
        
        setGridResult = ticTacToe.setGridPositionStateForCurrentPlayer(input - 1);
        
        //if got an error attempting to set grid position stat
        if (setGridResult == -1)
        {
            std::cout << "The grid position is already being used - please try again." << std::endl;
        }
        
    } while (setGridResult == -1);
}

//==============================================================
bool checkGameStatus (const int gridSize, TicTacToe &ticTacToe)
{
    int gameResult = ticTacToe.checkGameStatus();
    
    //If the game is still in play
    if (gameResult == 0)
    {
        ticTacToe.moveToNextPlayer();
    }
    else
    {
        displayGrid (gridSize, ticTacToe);
        
        //if there is now a winner
        if (gameResult == 1 || gameResult == 2)
            std::cout << "Player " << gameResult << " has won! Play again? (y/n)" << std::endl;
        
        //else all grid positions were used but no winner
        else
            std::cout << "Game over! Play again? (y/n)" << std::endl;
        
        
        char userSelection;
        
        //loop to get a valid keyboard response, exit once got a valid response
        do
        {
            std::cin >> userSelection;
            
            //if not got a valid number input
            if (!(userSelection == 'y' || userSelection == 'n'))
            {
                std::cout << "Invalid input - please try again." << std::endl;
                clearAndIgnoreCin();
            }
            
        } while (!(userSelection == 'y' || userSelection == 'n'));
        
        if (userSelection == 'y')
            ticTacToe.resetGame();
        else
            return true;
    }
    
    return false;
}

//==============================================================
void clearAndIgnoreCin()
{
    //clear error flag on cin, and ignore anything else on same line
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}



