#include <iostream>
#include "controls.h"
#include <string>
#include <vector>

using namespace std;

void doPlayerMove(string input, Player player, vector<vector<string>>& playerBoard, int& p, int& numTurns){ 
    
    for (int i = 0; i < (int)input.length(); i++){
        
        if (input[i] == 'w' && player.row > 1){
            //cout << "W" << endl;
            player.row -= 3;
        }
        else if (input[i] == 'a' && player.column > 1){
            //cout << "A" << endl;
            player.column -= 4;
        }
        else if (input[i] == 's' && player.row < 7){
            //cout << "S" << endl;
            player.row += 3;
        }
        else if (input[i] == 'd' && player.column < 9){
            //cout << "D" << endl;
            player.column += 4;
        }
        else if (input == "middle"){
            player.row = 4;
            player.column = 5;
        }
    }
    if (playerBoard[player.row][player.column] != " "){cout << "A player has already played here." << endl; p -=2; numTurns--; return;}
    //cout << "MOving player" << endl;
    playerBoard[player.row][player.column] = player.symbol;

    //cout << "Player Moved " << endl;

}