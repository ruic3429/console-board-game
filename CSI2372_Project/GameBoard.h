//
//  GameBoard.h
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//

#ifndef __CSI2372_Project__GameBoard__
#define __CSI2372_Project__GameBoard__

#include <stdio.h>
#include "Player.h"
#include <vector>

enum class Move{up, down, left, right};

template <typename J, typename T>
class GameBoard {
    
public:
    void add(const T& title, int row, int col);
    const T& getTile(int row, int col) const;
    void getCoordinate(const T &tile, int *row, int *col) const;
    void setPlayer(J player);
    J getPlayer(const string& playerName) const;
    const T& getTile(const string& playerName) const;
    vector<J> getPlayers(const T& tile) const;
    const T& move(enum Move move, const string& playerName);
};



#endif /* defined(__CSI2372_Project__GameBoard__) */
