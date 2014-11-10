//
//  Player.cpp
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//

#include "Player.h"

bool Player::canAct() const{
    
    if(food <= 0){
        return false;
    }
    return true;

}

//bool Player::pay(<#Player &player#>){
//
//    return true;
//}

void Player::eat(){

    if(food > 0){
        food--;
    }
    
}


