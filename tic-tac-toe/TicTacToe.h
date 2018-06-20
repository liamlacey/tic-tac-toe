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
    
private:
    
    int gridSize;
    std::vector<int> gridStates;
    
};

#endif /* TicTacToe_h */
