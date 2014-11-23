//
//  Tile.h
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//
#ifndef __boardGameCode__Tile__
#define __boardGameCode__Tile__

#include <stdio.h>
#include "Player.h"

class Tile{
private:
    std::string name;
public:
    Tile();
    bool operator==(const Tile &t);
    virtual bool action(Player& player)const;
    virtual Tile* clone()const;
    virtual void print()const;
    //std::ostream& operator<<;
};

class Restaurant: public Tile{
public:
    Restaurant();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class SpiceMerchant: public Tile{
public:
    SpiceMerchant();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class FabricManufacturer: public Tile{
public:
    FabricManufacturer();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class Jewler: public Tile{
public:
    Jewler();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class CartManufacturer: public Tile{
public:
    CartManufacturer();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class SmallMarket: public Tile{
public:
    SmallMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class SpiceMarket: public Tile{
public:
    SpiceMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class JewlryMarket: public Tile{
public:
    JewlryMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class FabricMarket: public Tile{
public:
    FabricMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class BlackMarket: public Tile{
public:
    BlackMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};




#endif /* defined(__boardGameCode__Tile__) */
