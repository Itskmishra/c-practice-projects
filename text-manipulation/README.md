# String Manipulation Tool

This C program provides a simple command-line interface for performing various string manipulation tasks.

## Features

- Reverse a string
- Count letters in a string
- Count words in a string
- User-friendly menu interface
- Continuous operation until user chooses to exit

## How to Use

1. Compile the program:
```
gcc main.c -o string_tool
```
2. Run the compiled program:
```
./string_tool
```
3. Follow the on-screen menu prompts:
- Enter the number corresponding to the desired operation
- Input the string when prompted
- View the result

4. To exit, select option 5 from the main menu

## Functions

- `reverse_string()`: Reverses the input string
- `count_letters()`: Counts all characters except spaces and newlines
- `count_words()`: Counts words by tracking spaces (assumes words are space-separated)
- `get_user_input()`: Safely gets user input with buffer overflow protection
- `clear_input_buffer()`: Clears the input buffer to prevent issues with mixed input types

## Notes

- Maximum input string length is defined by `MAX_LENGTH` (currently set to 100)
- The word count function counts spaces between words, so it may not be accurate for strings with multiple consecutive spaces

## Limitations

- The word count function treats consecutive spaces as separate words
- Special characters and punctuation are counted as letters
