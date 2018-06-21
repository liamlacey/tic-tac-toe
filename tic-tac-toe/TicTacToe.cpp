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
    if (gridStates[pos] == 0)
        gridStates[pos] = currentPlayer + 1;
    //if the slot isn't available, flag to return an error
    else
        result = -1;
    
    return result;
}
