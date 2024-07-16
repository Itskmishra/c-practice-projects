#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// len of the string user can input
#define MAX_LENGTH 100

// function declaration
void count_letters();
void reverse_string();
void count_words();
void program_help();
void clear_input_buffer();

// a simple function to get string input from cli using fgets
void get_user_input(char *buffer,size_t buffer_size){
  printf("Enter you string: ");
  if(fgets(buffer, buffer_size, stdin) != NULL){
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n'){
      buffer[len - 1] = '\0';
    }else{
      buffer[0] = '\0';
    }
  }
}
// defining array and it's size
char buffer[MAX_LENGTH];
size_t buffer_len = sizeof(buffer);

int main(){
  int input;
  // creating a loop to stay in function until user quit's
  do{
    program_help();
    printf("Select an option: ");
    scanf("%d", &input);
    switch(input){
      case 1:
        reverse_string();
        break;
      case 2:
        count_letters();
        break;
      case 3:
        count_words();
        break;
      case 5:
        puts("Exiting....");
        break;
      default:
        printf("Something went wrong re run the program\n");
        break;
    }
  } while(input != 5);

  return 0;
};
// rather than counting words I am counting white spaces between words which is simpler
void count_words(){
  clear_input_buffer();
  get_user_input(buffer, buffer_len);
  puts("--------------------------------------------------------");
  printf("%s \n", buffer);

  int len = strlen(buffer);
  int words = 1;
  for (int i = 0; i < len; i++){
    if(buffer[i] == ' '){
      words++;
    }
  }

  printf("Total Words: %d \n", words);
  puts("-------------------------------------------------------");
}
// counts every letter in a string except space, new line and default whitespace.
void count_letters(){
  clear_input_buffer();
  get_user_input(buffer, buffer_len);
  puts("--------------------------------------------------------");
  printf("%s \n", buffer);

  int len = strlen(buffer);
  int words = 0;
  for (int i = 0; i < len; i++){
    if(buffer[i] != ' ' && buffer[i] != '\n' && buffer[0] != ' '){
      words++;
    }
  }
  printf("Total letters: %d \n", words);
  puts("-------------------------------------------------------");
}
// simple string rev function which changes the char index from both ends of the array
void reverse_string(){
  clear_input_buffer();
  get_user_input(buffer, buffer_len);
  puts("--------------------------------------------------------");
  printf("%s \n", buffer);
  int len = strlen(buffer);
  int i,j;
  char temp;
  for (i = 0, j = len - 1; i < j; i++, j--){
    temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
  }
  printf("Reversed string: %s \n", buffer);
  puts("-------------------------------------------------------");
}
// menu function
void program_help(){
  puts("Simple cli tool for string manipulation.\n"
       "1: reverse\n"
       "2: count letters\n"
       "3: count words\n"
       "5: quit\n");
};
// function to clear input buffer like new line char and other things
void clear_input_buffer(){
  int c;
  while ((c= getchar()) != '\n' && c != EOF);
}
