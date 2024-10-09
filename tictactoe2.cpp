
/*Name: Aleena Shaik 
Date: 10/08/24
Project: Two player Tic Tac Toe
Citations: https://www.geeksforgeeks.org/tic-tac-toe-game-in-cpp/
 My sister
 Parth
 Previous Java tictactoe project
 
*/

#include <iostream>
#include <cstring>
using namespace std;

// I learned that in c++ you have to redeclare your parameter up here


void printBoard (char board[3][3]);
void switchTurn (char board[3][3], char X_MOVE);
bool checkWin(char board[3][3], char turn);
void clearBoard (char board[3][3]);
bool checkTie (char board[3][3]);
int main(){
    
// initializing variables (i do not use some of them)
  bool replay = true; 
  char board [3][3];
  bool stillPlaying = true;
  char X_MOVE = 'X';
  char O_MOVE = 'O';
  int X_TURN = 0;
  int O_TURN = 1;
  int countX = 0;
  int countO = 0;
  char turn = 'X';
  int turncount = 0;
  int row;
  int column;
  int roswitch;
  int inputyesno;
  while (replay){ // if player wants to play again
      
      //puts the dashes in the board

  for (int row = 0; row< 3; row++){
      for (int column= 0; column <3; column++){
        board[row][column] = '-';
        }
    }
     // if player is still playing the same game
    while (stillPlaying) {
       
        printBoard(board);
        switchTurn(board, turn);

        if (checkWin(board, turn)) { // first it checks if someone has won or not
            printBoard(board);
            cout << "Player " << turn << " wins!" << endl;
            if (turn == 'X'){// if someone did the program will display the wins and prompt play again
                countX++;
                cout<< "Player X has won " << countX << " times";
                cout<< "Do you want to play again? (1 for yes/2 for no)";
                cin>> inputyesno;
                if (inputyesno == 1){
                     turn = 'X';
		     replay == true; // if yes then reply if no do not replay
                  
                }else if (inputyesno==2){
                    replay == false; 
                }
            }else{
                countO++;
                cout<< "Player O has won " << countO << " times";
                cout<< "Do you want to play again? (1 for yes/2 for no)";
                cin>> inputyesno;
                if (inputyesno == 1){
                     turn = 'X';
                    replay = true;
                   
                }else if (inputyesno ==2) {
                    replay = false; 
                }
            }
            clearBoard(board);
        } else if (checkTie(board)) { //if nobody won check tie and prompt replay
            printBoard(board);
            cout << "It's a tie!" << endl;
            clearBoard(board);
            cout<< "Do you want to play again? (1 for yes/2 for no)";
            cin>> inputyesno;
                if (inputyesno == 1){
                    turn = 'X';
                    replay == true;
                    
                }else if (inputyesno==2){
                    replay == false; 
                }
            
        } else { //otherwise keep switching turns
            if (turn == 'X') {
                turn = 'O';
            } else {
                turn = 'X';
            }
        }
    }
  
    }
  return 0;
  
}

void printBoard(char board [3][3]){/// prints board
  
    for (int i = 0; i < 3; i++){
      cout<< " " << board[i][0] << "|" << board[i][1] << "|" << board [i][2] <<"\n";

    } 
   
  }
bool checkWin(char board[3][3], char turn){// goes through every point and checks if these points create to make a win for turn X or O
  if (board[0][0]== turn && board [0][1] == turn && board[0][2]==
turn) {
return true;
}
   if (board[0][0] == turn && board [1][1]== turn && board[2][2]==
turn){
return true;
}
   if (board[0][0] == turn && board [1][0]== turn && board[2][0]==
turn){
return true;
}
if (board[1][0] == turn && board [1][1]== turn && board[1][2]==
turn){
return true;
}
if (board[1][1] == turn && board [1][2]== turn && board[2][1]==
turn){
return true;
 }
if (board[0][2] == turn && board [1][2]== turn && board[2][2]== turn){
return true;
}
if (board[2][0] == turn && board [2][1]== turn && board[2][2]==
turn){
return true;
}
if (board[2][0] == turn && board [1][1]== turn && board[0][2]==
turn){
return true;
}
 return false; //returns false if no one wins
}
void switchTurn(char board[3][3], char turn) { // inputs from user to mark X or O and changes turns
    char ro; 
    int col;
    
    
    cout << "turn " << turn << ", (Enter your move for example: a1) ";
    cin >> ro >> col;


    // this certain section is to convert the input of the user from an alphabet to a number to align with array points
    int row;
    if (ro == 'a') {
        row = 0;
    } else if (ro == 'b') {
        row = 1;
    } else if (ro == 'c') {
        row = 2;
    } else {
      row = -1; // if its invalid
    }
    
    
    
    col--;  // minus one to align with array points

    // Validate input
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {// if the input is not between a - c and 1-3 it will prompt to try again
        board[row][col] = turn;
    } else  {
        cout << "Invalid move. Try again." << endl;
        switchTurn(board, turn); // Repeat turn if invalid
        
    }
}
bool checkTie(char board[3][3]){ // if no one wins then it is check tie
    for (int i = 0; i < 3; i++){
        for (int j = 0; j<3; j++){
            if (board[i][j] == '-'){
                return false;
            }
        }
    }
  return true;
}
void clearBoard(char board[3][3]){ ///clears board by assigning all boxes to '-' like how it starts
    for (int row = 0; row< 3; row++){
        for (int column = 0; column < 3; column++){
            board[row][column]= '-';
        }
    }
} 
