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

class Player{
private:
    std::string name;
    int gold;
    int ruby;
    int spice;
    int fabric;
    int jewel;
    int cart;
    int food;
    int gemBuyTime;//index that player buy ruby in Gem Merchant
    int inventory;//size of current inventory<=capacity
    int turn;//number of turns in the game
public:
    Player();
    Player(std::string playerName);
    std::string getName();
    int getGold();
    int getRuby();
    int getSpice();
    int getFabric();
    int getJewels();
    int getCart();
    int getFood();
    int getInventory();
    int getGemBuyTime();
    int getTurn();
    void setGold(int nGold);
    void setRuby(int nRuby);
    void setSpice(int nSpice);
    void setFabric(int nFabric);
    void setJewels(int nJewels);
    void setCart(int nCart);
    void setFood(int nFood);
    void setInventory(int nInv);
    void setGemBuyTime(int gemBuy);
    void setTurn(int turn);
    bool canAct() const;
    bool pay(Player& player);
    void eat();
    void printStats();
};

#endif /* defined(__CSI2372_Project__Player__) */
