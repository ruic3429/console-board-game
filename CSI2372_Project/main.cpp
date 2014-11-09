//
//  main.cpp
//  CSI2372_Project
//
//  Created by Richard on 2014-11-07.
//  Copyright (c) 2014 Richard. All rights reserved.
//

#include <iostream>
#include "Player.h"

using namespace std;

int main() {
    
    int num_Player;
    string name;
    Player* player = new Player(name);
    string move;

    cout << "Welcome to the Board Game !\n" << endl;
    cout << "Please select the number of players: ";
    cin >> num_Player;
    cout << "" << endl;
    
    for(int i = 0; i < num_Player; i++){
    cout << "Please enter player's name: ";
    cin >>  name;
    cout << "Player's name is: " << name << endl;
    cout << "\n" <<endl;
    }
    
    cout << "Generating Board, please wait...\n" << endl;
    
    //Generte Board
    
    cout << "Board generated successfully !\n" << endl;
    
    while (player->ruby != 0) {
        cout << "Please make a move: ";
        cin >> move;
        cout << "\n" <<endl;
        
        cout << "You move to ( " << move << " )\n" <<endl;
        
    }
    
    cout << "Player : " << name << " has won the game !\n" << endl;
    cout << "Game Terminated" << endl;
    
    
    return 0;
}
