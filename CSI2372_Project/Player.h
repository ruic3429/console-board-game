//
//  Player.h
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//

#ifndef __CSI2372_Project__Player__
#define __CSI2372_Project__Player__

#include <stdio.h>
#include <iostream>

using namespace std;

class Player{

//private:
public:
    string name;
    int gold;
    int ruby;
    int spice;
    int fabric;
    int jewel;
    const int cart = 10;
    int food;
    
//public:
    Player(string name){
        gold = 5;
        ruby = 0;
        spice = 1;
        fabric = 0;
        jewel = 1;
        food = 10;
    }
    bool canAct() const;
    bool pay( Player& player);
    void eat();
    
    
};

#endif /* defined(__CSI2372_Project__Player__) */
