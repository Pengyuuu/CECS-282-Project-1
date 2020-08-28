#include <iostream>
#include <array>
#include "OthelloGame.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int currentPlayer = 1, gamePass = 0, row, col;
    bool gameCount = 1;
    
    array<array<char, 8>, 8> board = {0};
    
    board[3][3] = -1;
    board[4][4] = -1;
    board[4][3] = 1;
    board[3][4] = 1;
    
    cout << "Welcome to Othello!" << endl;
    
    while (gameCount || gamePass != 2){
        
        PrintBoard(board);
        
        if (currentPlayer == 1){
            
            cout << "Black's turn. Please choose a move: " << endl;            
            GetMove(row, col);
        }
        else {
            
            cout << "White's turn. Please choose a move: " << endl;
            GetMove(row, col);
        }
        
        while(!IsValidMove(board, row, col)){
            
            cout << "Invalid move. Please choose a move: " << endl;
            GetMove(row, col);
        }
        
        if (row == -1 && col == -1 && gamePass == 1){
            
            gamePass += 1;
            gameCount = 0;
        }
            
        else if (row == -1 && col == -1) {
                
            gamePass += 1;
        }
        
        else {
            
            gamePass = 0;
        }
                
        if (row != -1 && col != -1){
            
            ApplyMove(board, row, col, currentPlayer);
        }
              
        if (currentPlayer == 1){
            
            currentPlayer -= 2;
        }
        else{
            
            currentPlayer = 1;
        }
        
        if (gamePass != 2){
            for (int i = 0; i < BOARD_SIZE; i++){
                for (int j = 0; j < BOARD_SIZE; j++){
                    
                    gameCount = board[i][j] == 0;
                }
            }
        }
    }
        
    if (GetValue(board) > 0){
        
        cout << "Black wins!" << endl;
    }
    else if (GetValue(board) < 0){
        
        cout << "White wins!" << endl;
    }
    else{
        
        cout << "It's a tie!" << endl;
    }
    return 0;
}
