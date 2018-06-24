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
    
    //Returns a grid state (see GridStateValues) for a given grid position
    int getStateForGridPosition (const int pos) const;
    
    //Sets a grid state (see GridStateValues) to a given grid position
    //Returns -1 if it can't the grid position to to it already being used, else returns 0.
    int setGridPositionStateForCurrentPlayer (const int pos);
    
    //Returns the current player nuumber in the range 0-1
    int getCurrentPlayer() const;
    //Moves to the next player number
    void moveToNextPlayer();
    
    //Returns the current game status (see GameStatusValues)
    int checkGameStatus() const;
    
    //Sets the grid size
    void setGridSize (const int gridSize_);
    
    //Resets all needed variables to restart the game
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
