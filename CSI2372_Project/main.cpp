//
//  main.cpp
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include <vector>
#include "GameBoard.h"
#include "Tile.h"

using namespace std;

int main() {
    
    int num_Player;
    vector<string> nameCollection;
    string name;
    //vector<Player*> player;
    string input;
    int rows;
    int cols;
    int row;
    int col;
    string playerOnMove;

    cout << "Welcome to the Board Game !\n" << endl;
    
    cout << "Please input number of rows on board (rows is integer): ";
    cin >> rows;
    cout << "\n" << endl;
    
    cout << "Please input number of columns on board (cols is integer): ";
    cin >> cols;
    cout << "\n" << endl;
    
    cout << "Your board has " << rows << " rows, and " << cols << " columns" << endl;
    cout << "There are " << (rows)*(cols) << " tiles on the board. \n" << endl;
    
    
    cout << "Please select the number of players: ";
    cin >> num_Player;
    cout << "" << endl;
    
    //generate players
    //for(int i = 0; i < num_Player; i++){
    cout << "Please enter player's name: ";
    //cin >>  name[i];
    //cout << "Player's name is: " << name[i] << endl;
    //Player* player = new Player(name[i]);
    //player[i] = new Player(name[i]);
    cin >> name;
    nameCollection.push_back(name);
    cout << "Player's name is: " << name[0] << endl;
    Player* player = new Player(name);
    cout << "\n" <<endl;
    //}
    
    
    cout << "Generating Board, please wait...\n" << endl;
    
    //Generte Board
    GameBoard<Tile, Player> * board = new GameBoard<Tile, Player>(rows,cols,num_Player);
    for (int i = 0; i< rows; i++) {
        for (int j = 0; j< cols; j++) {
            Tile * t = new Tile();
            board->add(*t, i, j);
            delete t;
        }
    }
    
    board->setPlayer(*player, rows, cols);
    
    cout << "Board generated successfully !\n" << endl;
    
    board->getPlayerCoordinates(player->getName(), &row, &col);
    cout << "Initial Location: " << "[" << row << "][" << col << "]\n" << endl;
    
    while(player->getRuby() != 5){
        board->getPlayerCoordinates(player->getName(), &row, &col);
        cout << "\nYou are at " << "[" << row << "][" << col << "]" << endl;
        board->printNeighbours(row, col);
        std::cout<<"Where do you want to move?"<<std::endl;
        //getline(std::cin,input);
        cin >> input;
        if (input=="down") {
            GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
            playerOnMove = player->getName();
            board->move(move, playerOnMove);
        }else if (input=="up"){
            GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
            playerOnMove = player->getName();
            board->move(move, playerOnMove);
        }else if (input=="left"){
            GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
            playerOnMove = player->getName();
            board->move(move, playerOnMove);
        }else if (input=="right"){
            GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
            playerOnMove = player->getName();
            board->move(move, playerOnMove);
        }else{
            cout << "Unidentified Command." << endl;
        }

    }
    
    
    cout << "Player : " << player->getName() << " has won the game !\n" << endl;
    
    cout << "Game Terminated !" << endl;
    
    
    return 0;
}

