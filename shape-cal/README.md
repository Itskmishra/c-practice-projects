# Shape Area Calculator

This C program provides a simple utility to calculate the area of various shapes.

## Features

- Calculates areas of:
  - Circle
  - Rectangle
  - Square
  - Triangle
- User-friendly menu interface
- Continuous operation until user chooses to exit

## How to Use

1. Compile the program:
```
gcc main.c -o shape_area_calculator
```
2. Run the compiled program:
```
./shape_area_calculator
```
3. Follow the on-screen prompts:
- Enter the number corresponding to the desired shape
- Input the required dimensions when prompted
- View the calculated area

4. To exit, select option 5 from the main menu

## Notes

- All calculations use single-precision floating-point numbers
- Circle area uses PI approximated to 3.14159
- Triangle area is calculated using the formula: 1/2 * base * height
