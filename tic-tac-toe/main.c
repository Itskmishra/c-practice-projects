#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
// defing board size, array player symbols
char board[3][3];
const int board_size = sizeof(board) / sizeof(board[0]);
const char PLAYER = 'O';
const char COMPUTER = 'X';

// function declaration
void game();
void reset_board();
void print_board();
int check_free_spaces();
void player_move();
void computer_move();
char check_winner();
void print_winner(char);

int main(){
  char user_input;
  // creating a loop to stay inside function util user quits.
  printf("Do you want to play (y/n): ");
  scanf("%c",&user_input);
  while( user_input == 'y' || user_input == 'Y'){
    reset_board();
    game();
    scanf("%c");
    printf("Do you want to play (y/n): ");
    scanf("%c",&user_input);
  }
  return 0;
}
// function to store all the logic related the game like printing board updating score and more.
void game(){
  char winner = ' ';
  do{
    print_board();
    player_move();
    winner = check_winner();
    if(winner != ' ' || check_free_spaces() == 0){
      break;
    }
    computer_move();
    winner = check_winner();
    if(winner != ' ' || check_free_spaces() == 0){
      break;
    }
  } while(winner != ' ' || check_free_spaces() != 0);
  print_board();
  print_winner(winner);
};

// take user input for ther move
void player_move(){
  int row;
  int col;
  do{
    printf("Enter row #(1-3): ");
    scanf("%d", &row);
    printf("Enter column #(1-3): ");
    scanf("%d", &col);

    if (board[row - 1][col - 1] != ' '){
      printf("Invalid move!\n");
    } else {
      board[row - 1][col - 1] = PLAYER;
      break;
    }
  }while(1);
}
// simple computer move function pic's random row between 1 to 3 and col. then put the computer sign on the board.
void computer_move(){
  srand(time(0));
  if(check_free_spaces() > 0){
    do{
      int row = rand() % 3;
      int col = rand() % 3;
      if(board[row][col] == ' '){
        board[row][col] = COMPUTER;
        break;
      }
    }while(1);
  }
}
// clear all the data inside board array
void reset_board(){
  for (int i = 0; i < board_size; i++){
    for (int j = 0; j < board_size; j++){
      board[i][j] = ' ';
    }
  };
}
// function to print the board (mostly depend's on nested for loop)
void print_board(){
  for (int i = 0; i < board_size; i++){
    for (int j = 0; j < board_size; j++){
      if(j == 2){
        printf(" %c \n", board[i][j]);
      } else {
        printf(" %c |", board[i][j]);
      } 
    }
    if(i != 2){
      printf("---|---|---\n");
    }
  };
}
// simple funtion to check for free spaces on the board to decide for tie and move validation
int check_free_spaces(){
  int freeSpaces = 0;
  for (int i = 0; i < board_size; i++){
    for (int j = 0; j < board_size; j++){
      if(board[i][j] == ' '){
        freeSpaces++;
      };
    }
  };
  return freeSpaces;
}
// checks the horizontal,vertical and digonal for winner 
char check_winner(){
  // rows
  for (int i=0; i < 3; i++){
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
      return board[i][0];
    }
  }
  // columns
  for (int i =0; i < 3; i++){
    if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
      return board[0][i];
    }
  }
  // diagonals
  if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
    return board[0][0];
  }
  // 
  if(board[2][0] == board[1][1] && board[2][0] == board[0][2]){
    return board[2][0];
  }
  return ' ';
}
// printing the outcome based on the above values.
void print_winner(char winner){
  if(winner == 'X'){
    puts("**************\n"
         "**You loose!**\n"
         "**************");
  }else if(winner == 'O'){
    puts("**************\n"
         "** You Win! **\n"
         "**************");
  }else{
    puts("**************\n"
         "**It's a Tie**\n"
         "**************");
  }
}
