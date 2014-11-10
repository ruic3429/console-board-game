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

using namespace std;

int main() {
    
    int num_Player;
    vector<string> name;
    vector<Player*> player;
    string move;
    int row;
    int col;
    int rRow;
    int rCol;

    cout << "Welcome to the Board Game !\n" << endl;
    
    cout << "Please input number of rows on board: ";
    cin >> row;
    cout << endl;
    
    cout << "Please input number of columns on board: ";
    cin >> col;
    cout << "\n" << endl;
    
    cout << "Your board has " << row << " rows, and " << col << " columns" << endl;
    cout << "There are " << row*col << " tiles on the board. \n" << endl;
    
    
    cout << "Please select the number of players: ";
    cin >> num_Player;
    cout << "" << endl;
    
    for(int i = 0; i < num_Player; i++){
    cout << "Please enter player's name: ";
    cin >>  name[i];
    cout << "Player's name is: " << name[i] << endl;
    //Player* player = new Player(name[i]);
    player[i] = new Player(name[i]);
    cout << "\n" <<endl;
    }
    
    
    cout << "Generating Board, please wait...\n" << endl;
    
    //Generte Board
    
    cout << "Board generated successfully !\n" << endl;
    
    
    rRow = rand() % row + 1;
    rCol = rand() % col + 1;

    
    cout << "You are at " << "[" << rRow << "][" << rCol << "]" << endl;
    
    for (int i = 0; i < num_Player; i++) {
        if(player[i]->ruby != 0){
            
            cout << "Please make a move: ";
            cin >> move;
            cout << "\n" <<endl;
            
            cout << "You move from ( " << move << " ) to ( " << move << " )\n" <<endl;
        }
        else{
        
            cout << "Player : " << name[i] << " has won the game !\n" << endl;
            
            cout << "Game Terminated !" << endl;
        }
    }
//    while (player[i]->ruby != 0) {
//        
//        cout << "Please make a move: ";
//        cin >> move;
//        cout << "\n" <<endl;
//        
//        cout << "You move from ( " << move << " ) to ( " << move << " )\n" <<endl;
//        
//    }
    
//    cout << "Player : " << name << " has won the game !\n" << endl;
//    
//    cout << "Game Terminated !" << endl;
    
    
    
    return 0;
}

