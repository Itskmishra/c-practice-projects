#include <stdio.h>

void area_of_circle();
void area_of_square();
void area_of_rectangle();
void area_of_triangle();

int main(){
  int user_input;
  do {
    puts("This is a simple utility to find area of different shapes.\n"
       "1. Circle\n"
       "2. Rectangle\n"
       "3. Square\n"
       "4. Traiangle\n"
       "5. To exit \n"
       "Enter the corosponding number to find the area.\n");
  
    scanf("%d", &user_input);

    //user_input[len(user_input) -1] = '\0';
    switch (user_input){
      case 1:
        area_of_circle();
        break;
      case 2:
        area_of_rectangle();
        break;
      case 3:
        area_of_square();
        break;
      case 4:
        area_of_triangle();
        break;
      case 5:
        printf("Closing program....\n");
        return 0;
      default:
        printf("You have entered something wrong.\n");
        return 1;
    }
  } while(user_input != 5);
  return 0;
};

void area_of_circle(){
  const double PI = 3.14159;
  float radius;
  float area;
  // take input of radius
  printf("Enter the radius of circle: ");
  scanf("%f", &radius);
  // calculate the area
  area = PI * radius * radius;
  printf("Area = %.4f\n", area);
};

void area_of_rectangle(){
  float length;
  float width;
  float area;
  // take length and width
  printf("Enter the length: ");
  scanf("%f", &length);
  printf("Enter the width: ");
  scanf("%f", &width);

  area = length * width;
  printf("Area = %.2f\n", area);
};

void area_of_triangle(){
  float base;
  float height;
  float area;
  printf("Enter base: ");
  scanf("%f", &base);
  printf("Enter height: ");
  scanf("%f", &height);
  area =  height * base * 1 / 2;
  printf("Area = %.2f\n", area);
};

void area_of_square(){
  float side;
  float area;
  printf("Enter side: ");
  scanf("%f", &side);

  area = side * side;
  printf("Area = %.2f\n", area);
};
