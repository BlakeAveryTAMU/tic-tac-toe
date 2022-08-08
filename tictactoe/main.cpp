#include <iostream>
#include "controls.h"
#include <string>
#include <vector>
#include <cctype>
using namespace std;

/* Known Issues
*
* 

*
*/

void displayBoard(vector<vector<string>> board){

    cout << endl;
    for (int i = 0; i < (int)board.size(); i++){
        for (int j = 0; j < (int)board[i].size(); j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidInput(string input){

    if (input == "middle"){return true;}
    //loop through input string to check for valid input
    for (size_t i = 0; i < input.size(); i++){
        if (input[i] != 'w' && input[i] != 'a' && input[i] != 's' && input[i] != 'd'){cout << "Invalid input\n" << endl; return false;}
    } 
    return true;
}

bool endGame(int numTurns, vector<vector<string>> playerBoard){
    //cout << "Checking for endGame" << endl;
    //6 turns before a player can win
    if (numTurns >= 5){
        //rows       
        for (int i = 1; i < BOARD_HEIGHT; i+=3){
            //cout << "Entering the loop for the: " << i - 2 << " time" << endl;
            if (playerBoard[i][1] == playerBoard[i][5] && playerBoard[i][1] == playerBoard[i][9] && playerBoard[i][1] != " "){
                cout << "GAME OVER!" << endl;
                return true;
            }
        }

        //Columns
        for (int i = 1; i < BOARD_WIDTH; i+=4){
            
            if (playerBoard[1][i] == playerBoard[4][i] && playerBoard[1][i] == playerBoard[7][i] && playerBoard[1][i] != " "){
                
                cout << "GAME OVER!" << endl;
                return true;
            }
        }

        //diagonals
            //left to right

            if (playerBoard[1][1] == playerBoard[4][5] && playerBoard[1][1] == playerBoard[7][9] && playerBoard[1][1] != " "){
                cout << "GAME OVER!" << endl;
                return true;
            }
            //right to left
            if (playerBoard[1][9] == playerBoard[4][5] && playerBoard[1][9] == playerBoard[7][1] && playerBoard[1][9] != " "){
                cout << "GAMER OVER!" << endl;
                return true;
            }
            
    }

    return false;
}



int main(){

        //initialize 9 row, 11 column 2d vector
        vector<vector<string>> playerBoard
    {
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "},
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "},
        {"_", "_", "_", "|", "_", "_", "_", "|", "_", "_", "_"},
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "},     
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "},
        {"_", "_", "_", "|", "_", "_", "_", "|", "_", "_", "_"},
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "},
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "},
        {" ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " "} 
        
        //locations for player moves: Middle = row 5, column 6; top middle = row 2, column 6; bottom middle = row 8, column 6; 
        //top left = row 2, column 2; middle left = row 5, column 2; bottom left = row 8, column 2;
        //top right = row 2, column 10; middle right = row 5, column 10; bottom right = row 8, column 10;
    };

    //Create Players
    Player player1;
    Player player2;
    player2.symbol = 'O';

    //Start Game

    cout << endl << "Let's play tic-tac-toe!" << endl;
    cout << endl;
    displayBoard(playerBoard);

    int p1 = 1;
    int p2 = 2;
    string input = "";
    int numTurns = 0;

    while (true){

        if (p1 < p2){
            //player 1's turn
            cout << "Player 1: ";
            getline(cin, input);
            tolower(input[0]);
            if (input.length() == 0){input = "middle";}
            if (!isValidInput(input)){continue;}
            doPlayerMove(input, player1, playerBoard, p1, numTurns);
            displayBoard(playerBoard);
            
            p1 += 2;
        }
        else if (p2 < p1){
            //player 2's turn
            cout << "Player 2: ";
            getline(cin, input);
            tolower(input[0]);
            if (!isValidInput(input)){continue;}
            doPlayerMove(input, player2, playerBoard, p2, numTurns);
            displayBoard(playerBoard);

            p2 += 2;
        }

        numTurns++;
        
        if (endGame(numTurns, playerBoard)){
            return 0;
        }
        else if (numTurns == 9 && !endGame(numTurns, playerBoard)){
            cout << "   Tie!\n" << endl;
            return 0;
        }
        else {
            continue;
        }
    }

    return 0;

}