//
//  TicTacToe.h
//  tic-tac-toe
//
//  Created by Liam Lacey on 20/06/2018.
//  Copyright © 2018 Liam Lacey. All rights reserved.
//

#ifndef TicTacToe_h
#define TicTacToe_h

#include <iostream>
#include <vector>

class TicTacToe
{
public:
    
    TicTacToe (int gridSize_);
    ~TicTacToe();
    
    int getStateForGridPosition (int pos);
    int setGridPositionStateForCurrentPlayer (int pos);
    
    int getCurrentPlayer();
    void moveToNextPlayer();
    
    int checkGameStatus();
    
    void resetGame();
    
private:
    
    int gridSize;
    //0 = available, 1 = player 1 / x, 2 = player 2 / o
    std::vector<int> gridStates;
    
    int currentPlayer;
};

#endif /* TicTacToe_h */
