# Simple Contact Book CLI Tool

This is a command-line interface (CLI) application for managing a simple phonebook. It allows users to create, delete, update, and search for contacts.

## Features

- Create new contacts with name and phone number
- Delete existing contacts
- Update contact information (name or number)
- Search for contacts by name or phone number
- List all contacts
- Dynamic memory allocation for storing contacts

## How to Use

1. Compile the C program using a C compiler (e.g., gcc):
```
gcc -o contact_book contact_book.c
```
2. Run the compiled program:
```
./contact_book
```
3. Follow the on-screen menu to interact with the contact book:
- 1: Create a new contact
- 2: Delete a contact
- 3: Update a contact
- 4: Find a contact by number
- 5: Find a contact by name
- 6: List all contacts
- 7: Exit the program

## Technical Details

- Written in C
- Uses dynamic memory allocation (malloc, realloc) for storing contacts
- Implements a simple struct-based data structure for contacts and the phonebook

## Limitations

- Maximum name length: 50 characters
- Maximum phone number length: 10 characters
- No persistent storage (contacts are lost when the program exits)

## Future Improvements

- Add persistent storage (e.g., save to file)
- Implement sorting functionality
- Add input validation for phone numbers
- Enhance search functionality (e.g., partial matches)
