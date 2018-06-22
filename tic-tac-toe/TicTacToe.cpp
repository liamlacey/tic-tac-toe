//
//  TicTacToe.cpp
//  tic-tac-toe
//
//  Created by Liam Lacey on 20/06/2018.
//  Copyright © 2018 Liam Lacey. All rights reserved.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe (int gridSize_)
            :   gridSize(gridSize_),
                currentPlayer(0)
{
    gridStates.resize (gridSize * gridSize);
}

TicTacToe::~TicTacToe()
{
    
}

int TicTacToe::getStateForGridPosition (int pos)
{
    return gridStates[pos];
}

int TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}

void TicTacToe::moveToNextPlayer()
{
    currentPlayer = !currentPlayer;
}

int TicTacToe::setGridPositionStateForCurrentPlayer (int pos)
{
    auto result = 0;
    
    //if the slot is available, set the new state based on current player
    if (gridStates[pos] == GRID_STATE_UNUSED)
        gridStates[pos] = currentPlayer + 1;
    //if the slot isn't available, flag to return an error
    else
        result = -1;
    
    return result;
}

int TicTacToe::checkGameStatus()
{
    int stateToCheckFor = GRID_STATE_UNUSED;
    
    for (auto row = 0; row < gridSize; row++)
    {
        for (auto col = 0; col < gridSize; col++)
        {
            if (col == 0)
                stateToCheckFor = gridStates[(row * gridSize) + col];

            if (stateToCheckFor == GRID_STATE_UNUSED || gridStates[(row * gridSize) + col] != stateToCheckFor)
                break;
            
            if (col == gridSize - 1)
                return stateToCheckFor;
        }
    }
    
    for (auto col = 0; col < gridSize; col++)
    {
        for (auto row = 0; row < gridSize; row++)
        {
            if (row == 0)
                stateToCheckFor = gridStates[(row * gridSize) + col];
            
            if (stateToCheckFor == GRID_STATE_UNUSED || gridStates[(row * gridSize) + col] != stateToCheckFor)
                break;
            
            if (row == gridSize - 1)
                return stateToCheckFor;
        }
    }
    
    
    stateToCheckFor = gridStates[0];
    
    if (stateToCheckFor != GRID_STATE_UNUSED)
        
    for (auto i = 1; i < gridSize; i++)
    {
        if (gridStates[(i * gridSize) + i] != stateToCheckFor)
            break;
        
        if (i == gridSize - 1)
            return stateToCheckFor;
    }
    
    
    stateToCheckFor = gridStates[gridSize - 1];
    
    if (stateToCheckFor != GRID_STATE_UNUSED)
        
        for (auto row = gridSize - 1, col = 0; col < gridSize - 1; col++, row--)
        {
            if (gridStates[(row * gridSize) + col] != stateToCheckFor)
                break;
            
            if (col == gridSize - 2)
                return stateToCheckFor;
        }
    
    
    for (auto i = 0; i < gridStates.size(); i++)
    {
        if (gridStates[i] == GRID_STATE_UNUSED)
            break;
        
        if (i == gridStates.size() - 1)
            return GAME_STATUS_OVER;
    }
    
    return GAME_STATUS_CONTINUE;
}

void TicTacToe::resetGame()
{
    for (auto i = 0; i < gridStates.size(); i++)
        gridStates[i] = GRID_STATE_UNUSED;
    
    currentPlayer = 0;
}
