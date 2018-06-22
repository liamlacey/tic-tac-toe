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
    
    enum GridStateValues
    {
        GRID_STATE_UNUSED = 0,
        GRID_STATE_PLAYER_1,
        GRID_STATE_PLAYER_2
    };
    
    enum GameStatusValues
    {
        GAME_STATUS_OVER = -1,
        GAME_STATUS_CONTINUE,
        GAME_STATUS_1_WON,
        GAME_STATUS_2_WON
    };
    
private:
    
    int gridSize;
    
    //uses GridStateValues
    std::vector<int> gridStates;
    
    int currentPlayer;
};

#endif /* TicTacToe_h */
