//
//  Player.cpp
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//

#include "Player.h"


#include "Player.h"

Player::Player(std::string playerName){
    name = playerName;
    gold = 5;
    ruby = 0;
    spice = 1;
    fabric = 1;
    jewel = 1;
    food = 10;
    cart = 9;
    gemBuyTime = 0;
    inventory = 3;
    turn = 0;
}

Player::Player(){
}

std::string Player::getName(){
    return name;
}

bool Player::canAct()const{
    if (food>0) {
        return true;
    }else{
        return false;
    }
}

bool Player::pay(Player &player){
    if(this->getGold()>0){
        player.setGold(player.getGold()+1);
        this->setGold(this->getGold()-1);
        return true;
    }
    return false;
}

void Player::eat(){
    if (food>0) {
        food--;
    }
}

void Player::setCart(int nCart){
    cart = nCart;
}

void Player::setFabric(int nFabric){
    fabric = nFabric;
}

void Player::setFood(int nFood){
    food = nFood;
}

void Player::setGold(int nGold){
    gold = nGold;
}

void Player::setJewels(int nJewels){
    jewel = nJewels;
}

void Player::setRuby(int nRuby){
    ruby = nRuby;
}

void Player::setSpice(int nSpice){
    spice = nSpice;
}

void Player::setGemBuyTime(int gemBuy){
    gemBuyTime = gemBuy;
}

void Player::setTurn(int round){
    turn = round;
}

int Player::getCart(){
    return cart;
}

int Player::getFabric(){
    return fabric;
}

int Player::getFood(){
    return food;
}

int Player::getGold(){
    return gold;
}

int Player::getJewels(){
    return jewel;
}

int Player::getRuby(){
    return ruby;
}

int Player::getSpice(){
    return spice;
}

int Player::getGemBuyTime(){
    return gemBuyTime;
}

int Player::getTurn(){
    return turn;
}

void Player::setInventory(int nInv){
    inventory = nInv;
}

int Player::getInventory(){
    return inventory;
}

void Player::printStats(){
    std::cout<<name<<" Stats:"<<std::endl;
    std::cout<<"--Inventory Size = "<<inventory<<std::endl;
    std::cout<<"--Cart = "<<cart<<std::endl;
    std::cout<<"--Gold = "<<gold<<std::endl;
    std::cout<<"--Ruby = "<<ruby<<std::endl;
    std::cout<<"--Food = "<<food<<std::endl;
    std::cout<<"--Jewel = "<<jewel<<std::endl;
    std::cout<<"--Fabric = "<<fabric<<std::endl;
    std::cout<<"--Spice = "<<spice<<std::endl;
}


