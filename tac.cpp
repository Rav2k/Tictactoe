#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
int xWins;
int oWins;
char letter = 'x';
bool tie  = false;

void drawingBoard(){//drawing the board

  cout<<"    a    b    c \n";
  cout<<"a";
  cout<<"   "<<board[0][0]<<"    "<<board[0][1]<<"    "<< board[0][2]<<"  \n";
  cout<<"b";
  cout<<"   "<<board[1][0]<<"    "<<board[1][1]<<"    "<< board[1][2]<<"  \n";
  cout<<"c";
  cout<<"   "<<board[2][0]<<"    "<<board[2][1]<<"    "<< board[2][2]<<"  \n";

}

void gamePlay(){
  int num;

  if(letter == 'x'){//if it's x's turn then ask them to enter a number to place the x on the board.
    cout<<"Please enter a number: ";
    cin>>num;
  }

  if(letter == 'o'){//if it's o's turn then ask them to enter a number to place the o on the board.
    cout<<"Please enter a number: ";
    cin>>num;
  }
  //correlating the number value with a row and column.
  if(num == 1){
    row = 0;
    column = 0;
   }
  if(num == 2){
    row = 0;
    column = 1;
   }
  if(num == 3){
    row = 0;
    column = 2;
   }
  if(num == 4){
    row = 1;
    column = 0;
   }
  if(num == 5){
    row = 1;
    column = 1;
   }
   if(num == 6){
    row = 1;
    column = 2;
   }
  if(num == 7){
    row = 2;
    column = 0;
   }
  if(num == 8){
    row = 2;
    column = 1;
   }
  if(num == 9){
    row = 2;
    column = 2;
   }
  if(num<1){
    cout<< "Invalid number entered!"<<endl;
    gamePlay();
  }
  if(num>9){
    cout<< "Invalid number entered!"<<endl;
    gamePlay();
  }

  //replacing the numbers on the board with the appropriate letter  
if(letter == 'x' && board[row][column] != 'x' && board[row][column] != 'o')
    {
      board[row][column] = 'x';
      letter ='o'; 
    }
  else if(letter== 'o' && board[row][column] != 'x' && board[row][column] != 'o')
    {
      board[row][column] = 'o';
      letter= 'x';
    }
  else{
    cout<<"There is no empty space there!"<<endl;
    gamePlay();
  }
}

bool winStatment(){
  for(int i=0; i<3; i++)
    {//checking the columns and rows for win.
      if(board[i][0]==board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] &&
         board[0][i] == board[2][i]){
         return true;
      }
    }//checking diagonals
if(board[0][0] == board[1][1] && board[1][1]==board[2][2] || board[0][2] == board[1][1] &&
     board[1][1] == board[2][0]){
     return true;
  }

  for(int i=0;i<3;i++)
    {

      for(int j=0;j<3;j++)
        {//keep playing if the board is not completly filled.
          if(board[i][j] != 'x' && board[i][j] != 'o')
            {

              return false;
            }
        }
    }
  tie = true;
  return false;
}

void resetBoard(){//goes through the board and sets the board back to normal.
  letter= 'x';

  if(board[0][0] == 'x' || board[0][0] == 'o'){
    board[0][0] = '1';
  }
  if(board[0][1] == 'x' || board[0][1] == 'o'){
    board[0][1] = '2';
  }
if(board[0][2] == 'x' || board[0][2] == 'o'){
    board[0][2] = '3';
  }
  if(board[1][0] == 'x' || board[1][0] == 'o'){
    board[1][0] = '4';
  }
  if(board[1][1] == 'x' || board[1][1] == 'o'){
    board[1][1] = '5';
  }
  if(board[1][2] == 'x' || board[1][2] == 'o'){
    board[1][2] = '6';
  }
  if(board[2][0] == 'x' || board[2][0] == 'o'){
    board[2][0] = '7';
  }
  if(board[2][1] == 'x' || board[2][1] == 'o'){
    board[2][1] = '8';
  }
  if(board[2][2] == 'x' || board[2][2] == 'o'){
    board[2][2] = '9';
  }
}
int main(){
  int rematch;
  //runs the three functions till someone has won.
  while(!winStatment()){
    drawingBoard();
    gamePlay();
    winStatment();
  }
  drawingBoard();
  if(letter== 'x' && tie == false)
    {//what to do when o wins
      cout<<"O Wins!"<<endl;
      oWins++;
      cout<<"X total wins: "<<xWins<<endl;
      cout<<"O total wins: "<<oWins<<endl;
      cout<<endl;
      cout<<"Do you want to play again?(Type 1 for Yes or 2 for No)"<<endl;
      cin>>rematch;
      if(rematch == 1){
        resetBoard();//call resetboard function, and at the end of the reset board function call main
        main();
      }
      else{
        return 0;
      }
    }
else if(letter== 'o' && tie == false)
    {//what to do when X wins the game
      cout<<"X Wins!"<<endl;
      xWins++;
      cout<<"X total wins: "<<xWins<<endl;
      cout<<"O total wins: "<<oWins<<endl;
      cout<<endl;
      cout<<"Do you want to play again?(Type 1 for Yes or 2 for No)"<<endl;
      cin>>rematch;
      if(rematch == 1){
        resetBoard();//call resetboard function, and at the end of the reset board function call main
        main();
      }
      else{
        return 0;
      }
    }
  else
    { //if neither x or o won and the board is filled then it's a draw.
      cout<<"It's a draw!"<<endl;
      cout<<"X total wins: "<<xWins<<endl;
      cout<<"O total wins: "<<oWins<<endl;
      cout<<endl;
      //asking if the user wants to play if call resetboard which resets the board and calls the main function to start the game over.
      cout<<"Do you want to play again?(Type 1 for Yes or 2 for No)"<<endl;
      cin>>rematch;
      if(rematch == 1){
        resetBoard();//call resetboard function, and at the end of the reset board function call main
        main();
      }
      else{
        return 0;
      }
    }
}
