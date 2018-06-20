//
//  TicTacToe.cpp
//  tic-tac-toe
//
//  Created by Liam Lacey on 20/06/2018.
//  Copyright © 2018 Liam Lacey. All rights reserved.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe (int gridSize_)
            :   gridSize(gridSize_)
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
