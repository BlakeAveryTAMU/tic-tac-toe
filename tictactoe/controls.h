#ifndef CONTROLS_H
#define CONTROLS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Player {

    string symbol = "X";
    int row = 4;
    int column = 5;
};

const int BOARD_WIDTH = 11;
const int BOARD_HEIGHT = 9;


//uses the input string to place the symbol in the array
void doPlayerMove(string input, Player player, vector<vector<string>>& playerBoard, int& p, int& numTurns);


#endif