#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "OthelloGame.h"

using namespace std;

void PrintBoard(const OthelloMatrix &board){
    
    for (int i = 0; i < board.size() + 1; i++){
        
        for (int j = 0; j < board.size() + 1; j++){
            
            if (i == 0 && j == 0){
                
                cout << "- ";
            }
            
            else if (i == 0){
                
                cout << j - 1 << " ";
            }
            
            else if (j == 0){
                
                cout << i - 1 << " ";
            }
            
            else if (board[i - 1][j - 1] == 0){
                
                cout << ". ";
            }
            
            else if (board[i - 1][j - 1] == 1){
                
                cout << "B ";
            }
            
            else if (board[i - 1][j - 1] == -1){
                
                cout << "W ";
            }
        }
        
        cout << endl;
    }
}

bool InBounds(int row, int col){
    
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool IsValidMove(const OthelloMatrix &board, int row, int col){
    
    if (((InBounds(row, col) != 0) && (board[row][col] == 0)) || (row == -1 && col == -1)){
        
        return true;
    }
    
    return false;
}

void GetMove(int &row, int &col){
    
    char parenOne, comma, parenTwo;
    
    cin >> parenOne >> row >> comma >> col >> parenTwo;
}

void ApplyMove(OthelloMatrix &board, int row, int col, char currentPlayer){
            
    for (int i = -1; i < 2; i++){
        
        for (int j = -1; j < 2; j++){
            
            int counter = 0, iCopy = i, jCopy = j;
                                    
            while (board[row + iCopy][col + jCopy] == currentPlayer * -1){
                
                counter++;
                iCopy += i;
                jCopy += j;
            }
          
            if (board[row + iCopy][col + jCopy] == currentPlayer && counter != 0){
                
                board[row][col] = currentPlayer;
                                
                while (counter > 0){
                    
                    iCopy += i * -1;
                    jCopy += j * -1;

                    board[row + iCopy][col + jCopy] = currentPlayer;
                                        
                    counter--;
                }
            }
        }
    }
}

int GetValue(const OthelloMatrix &board){
    
    int sum = 0;
    
    for (int i = 0; i < board.size(); i++){
        
        for (int j = 0; j < board.size(); j++){
            
            sum += board[i][j] + 0;
        }
    }
    
    return sum;
}
