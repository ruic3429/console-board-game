//
//  Tile.cpp
//  CSI2372_Project
//
//  Created by Richard on 2014-11-23.
//  Copyright (c) 2014 Richard. All rights reserved.
//

#include "Tile.h"

Tile* Tile::clone()const{
    return new Tile(*this);
}

Tile::Tile(){}

bool Tile::action(Player &player)const{
    return true;
}

void Tile::print()const{
    std::cout<<"Desert: No action is possible on this tile."<<std::endl;
}

Restaurant::Restaurant(){}

bool Restaurant::action(Player &player)const{
    if (player.canAct()) {
        player.setFood(10);
        return true;
    }
    return false;
}

Tile * Restaurant::clone()const{
    return new Restaurant(*this);
}

void Restaurant::print()const{
    std::cout<<"Restaurant: Replenish player's food."<<std::endl;
}

SpiceMerchant::SpiceMerchant(){}

bool SpiceMerchant::action(Player &player)const{
    if (player.canAct()) {
        if (player.getGold()>1) {
            int numSacks;
            if ((player.getCart()-player.getInventory())>2) {
                numSacks=3;
            }else{
                numSacks = player.getCart() - player.getInventory();
                if (numSacks==0) {
                    return false; //not enough space on cart
                }
            }
            player.setSpice(player.getSpice()+numSacks);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numSacks);
            player.eat();
            return true; //successful trade
        }
        return false; //not enough gold
    }
    return false; //not enough food to act
}

Tile* SpiceMerchant::clone()const{
    return new SpiceMerchant(*this);
}

void SpiceMerchant::print()const{
    std::cout<<"Spice Merchant: For 2 pieces of gold, purchase 3 sacks of spices (less if player does not have capacity)."<<std::endl;
}

FabricManufacturer::FabricManufacturer(){}

void FabricManufacturer::print()const{
    std::cout<<"For 2 pieces of gold, player gets 3 rolls of fabrics tissues (less if player does not have capacity)"<<std::endl;
}

Tile* FabricManufacturer::clone()const{
    return new FabricManufacturer(*this);
}

bool FabricManufacturer::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            int numTissues;
            if((player.getCart()-player.getInventory())>2){
                numTissues = 3;
            }else{
                numTissues = player.getCart()-player.getInventory();
                if (numTissues==0) {
                    return false;//not enough space on cart
                }
            }
            player.setFabric(player.getFabric()+numTissues);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numTissues);
            player.eat();
            return true;
        }
        return false;// not enough gold
    }
    return false;//not enough food
}

Jewler::Jewler(){}

void Jewler::print()const{
    std::cout<<"For 2 pieces of gold, player gets 3 pieces of jewlry (less if player does not have capacity)"<<std::endl;
}

Tile* Jewler::clone()const{
    return new Jewler(*this);
}

bool Jewler::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            int numJewles;
            if((player.getCart()-player.getInventory())>2){
                numJewles = 3;
            }else{
                numJewles = player.getCart()-player.getInventory();
                if (numJewles==0) {
                    return false;//not enough space on cart
                }
            }
            player.setJewels(player.getJewels() + numJewles);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numJewles);
            player.eat();
            return true;
        }
        return false;// not enough gold
    }
    return false;//not enough food
}

CartManufacturer::CartManufacturer(){}

void CartManufacturer::print()const{
    std::cout<<"For 7 pieces of gold, the capacity of the cart is increased by 3"<<std::endl;
}

Tile* CartManufacturer::clone()const{
    return new CartManufacturer(*this);
}

bool CartManufacturer::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>7) {
            int cartCapacity = player.getCart();
            cartCapacity = cartCapacity + 3;
            player.setCart(cartCapacity);
            player.setGold(player.getGold()-7);
            player.setInventory(player.getInventory());
            player.eat();
            return true;
        }
        return false;// not enough gold
    }
    return false;//not enough food
}

SmallMarket::SmallMarket(){}

void SmallMarket::print()const{
    std::cout<<"A player can sell 1 roll of fabric, 1 jewel and 1 sack of spices for 8 pieces of gold"<<std::endl;
}

Tile* SmallMarket::clone()const{
    return new SmallMarket(*this);
}

bool SmallMarket::action(Player &player)const{
    if(player.canAct()){
        if (player.getFabric()>1) {
            if(player.getJewels()>1){
                if(player.getSpice()>1){
                    int gold;
                    if((player.getCart()-player.getInventory())>8){
                        gold = 8;
                    }else{
                        gold = player.getCart()-player.getInventory();
                        if (gold==0) {
                            return false;//not enough space on cart
                        }
                    }
                    player.setGold(player.getJewels() + gold);
                    player.setFabric(player.getFabric()-1);
                    player.setJewels(player.getJewels()-1);
                    player.setSpice(player.getSpice()-1);
                    player.setInventory(player.getInventory()+gold);
                    player.eat();
                    return true;
                }
                return false;//not enough spices
            }
            return false;//not enough jewel
        }
        return false;// not enough fabric
    }
    return false;//not enough food
}
