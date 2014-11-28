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
#include "TileFactory.h"

using namespace std;

int main() {
    
    string startGame;
    int num_Player;
    string name;
    string input;
    int rows;
    int cols;
    int row;
    int col;
    string playerOnMove;
    string yOrN;
    vector<Player> players;
    int currentRound = 0;
    bool checkWin;

    cout << "Welcome to the Board Game !\n" << endl;
    
    cout << "DO you want to reload game or create game? <type 'reload' or 'create' to continue > " << endl;
    cin >> startGame;
    if(startGame == "reload"){
        cout << "Game reloaded" << endl;
        //inGame(num_Player, players, currentRound, board, checkWin);
    }
    else if(startGame == "create"){
    
    cout << "Please input number of rows on board (row is integer): ";
    cin >> rows;
    cout << "\n" << endl;
    
    cout << "Please input number of columns on board (col is integer): ";
    cin >> cols;
    cout << "\n" << endl;
    
    cout << "Your board has " << rows << " rows, and " << cols << " columns" << endl;
    cout << "There are " << (rows)*(cols) << " tiles on the board. \n" << endl;
    
    
    cout << "Please select the number of players: ";
    cin >> num_Player;
    cout << "" << endl;
    
    //generate players
    void getPlayerName(int num_Player, vector<Player> &players);
    getPlayerName(num_Player, players);
    
    cout << "Generating Board, please wait...\n" << endl;
    
    //Generte Board
    GameBoard<Tile, Player> * board = new GameBoard<Tile, Player>(rows,cols,num_Player);
    try{
    TileFactory * tf = TileFactory::get(rows*cols);
    for (int i = 0; i< rows; i++) {
        for (int j = 0; j< cols; j++) {
            board->add(*tf->next(), i, j);
        }
    }
    
    }catch(const std::out_of_range& oor){
        std::cerr << "\n**** Failed to generate Board ****\n What to generate again? (yes / no) " << '\n';
        cin >> yOrN;
        if(yOrN == "yes"){
            return main();
        }else{
            return 0;
        }
    }
    
    for(int i = 0; i < num_Player-1; i++){
        board->setPlayer(players.at(i), rows, cols);
    }
    
    cout << "Board generated successfully !\n" << endl;
    
    for(int i = 0; i < num_Player-1; i++){
    board->getPlayerCoordinates(players.at(i).getName(), &row, &col);
    cout << "Initial Location of player " << players.at(i).getName()<< " : " << "[" << row << "][" << col << "]\n" << endl;
    }
    
    void inGame(int num_Player, vector<Player> &players,int currentRound,GameBoard<Tile, Player> * board, bool checkWin);
    inGame(num_Player, players, currentRound, board, checkWin);
        
    }else{
        cout << "Invalid aguement " << endl;
    }
    
    cout << "Game Terminated !" << endl;
    
    cout << "Want to start again? <type 'yes' to restart>" << endl;
    string restart;
    cin >> restart;
    if(restart == "yes"){
        return main();
    }else{
        return 0;
    }
    
    
    return 0;
}

void getPlayerName(int num_Player, vector<Player> &players){
    string name;
    
    //generate players
    for(int i = 1; i <= num_Player; i++){
        cout << "Please enter player's name for player No." << i << " : ";
        cin >>  name;
        cout << "Player's name is: " << name << endl;
        Player player = *new Player(name);
        players.emplace_back(player);
        cout << "\n" <<endl;
    }
}

Player getNextAvailablePlayer(int num_Player,vector<Player> &players,int currentRound){
    Player player;
    for(int i = 0; i <= num_Player-1; i++){
        if(players.at(i).getTurn() == currentRound){
            player = players.at(i);
        }
        else{
            player = players.at(0);
        }
    }
    return player;
}

Player getWinPlayer(int num_Player, vector<Player> &players){
    
    Player win = *new Player("Nobody");
    for(int i = 0; i <= num_Player-1; i++){
        if(players.at(i).getRuby() >= 5){
            return players.at(i);
        }
    }
    return win;
}

bool noPlayerWin(int num_Player, vector<Player> &players ){
    
    for (int i = 0; i <= num_Player-1; i++) {
        if(players.at(i).getRuby()>5){
            return false;
        }
    }
    return true;
}

bool needUpdateRound(int num_Player, vector<Player> &players, int currentRound){
    
    for (int i = 0; i <= num_Player-1; i++) {
        if(players.at(i).getTurn() == currentRound){
            return false;
        }
    }
    return true;
}

void inGame(int num_Player, vector<Player> &players,int currentRound,GameBoard<Tile, Player> * board, bool checkWin){
    int row;
    int col;
    
    checkWin = checkWin = noPlayerWin(num_Player, players);
    
    while(checkWin){
        Player player = getNextAvailablePlayer(num_Player, players, currentRound);
        board->getPlayerCoordinates(player.getName(), &row, &col);
        cout << "\n" << player.getName() << " is at " << "[" << row << "][" << col << "]" << endl;
        board->printNeighbours(row, col);
        std::cout<<"Where to move?"<<std::endl;
        
        string input;
        string playerOnMove;
        getline(std::cin,input);
        if(input != ""){
            if (input=="down") {
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
                playerOnMove = player.getName();
                board->move(move, playerOnMove);
            }else if (input=="up"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
                playerOnMove = player.getName();
                board->move(move, playerOnMove);
            }else if (input=="left"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
                playerOnMove = player.getName();
                board->move(move, playerOnMove);
            }else if (input=="right"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
                playerOnMove = player.getName();
                playerOnMove = player.getName();
                board->move(move, playerOnMove);
            }
            else{
                cout << "Unidentified Command." << endl;
            }
            
            if(input == "down" || input == "up" || input == "left" || input == "right"){
                board->getPlayerCoordinates(player.getName(), &row, &col);
                cout << "\n" << endl;
                player.printStats();
                string takeAction;
                cout << "Do you want to take action? (yes / no) " << endl;
                cin >> takeAction;
                if(takeAction == "yes"){
                    board->getTile(row, col).clone()->action(player);
                }
            }
        }
        
        bool needUpdate = needUpdateRound(num_Player, players, currentRound);
        if(needUpdate){
            currentRound++;
        }
        
        checkWin = checkWin = noPlayerWin(num_Player, players);
    }
    
    Player winPlayer = getWinPlayer(num_Player, players);
    cout << "Player : " << winPlayer.getName() << " has won the game !\n" << endl;
}


