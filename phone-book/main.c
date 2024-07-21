#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 50
#define MAX_NUM 10

typedef struct
{
    char name[50];
    char number[10];
} Contact;

typedef struct
{
    Contact *contacts;
    int size;
    int capcity;
} Phonebook;

// utility functions
int take_opt_input();
char *take_input();
void clear_input_buffer();
void print_contact_book(Phonebook *book);

// action functions
void print_menu();
void create_new_contact(Phonebook *book);
void update_contact(Phonebook *book);
void delete_contact(Phonebook *book);
void find_by_num(Phonebook *book);
void find_by_name(Phonebook *book);

int main()
{
    // data of our phonebook;
    Phonebook *book;
    book->contacts = NULL;
    book->size = 0;
    book->capcity = 0;
    // integer for option selection
    int opt;
    do
    {
        print_menu();
        opt = take_opt_input();
        switch (opt)
        {
        case 1:
            create_new_contact(book);
            break;
        case 2:
            delete_contact(book);
            break;
        case 3:
            update_contact(book);
            break;
        case 4:
            find_by_num(book);
            break;
        case 5:
            find_by_name(book);
            break;
        case 6:
            print_contact_book(book);
            break;
        case 7:
            puts("Exiting...");
            break;
        default:
            puts("Something went wrong!");
            break;
        }
    } while (opt != 7);
    free(book->contacts);
    return 0;
}

// return user input
int take_opt_input()
{
    int option;
    printf("Select an option: ");
    scanf("%d", &option);
    clear_input_buffer();
    return option;
}

// take string user input and the return it for further use.
char *take_input()
{
    int size_of_array = 100;
    char *user_input = malloc(size_of_array * sizeof(char));
    if (user_input == NULL)
    {
        puts("Memory initialization failed!");
        exit(1);
    }
    // taking string as input from user.
    if (fgets(user_input, size_of_array, stdin) != NULL)
    {
        size_t inp_len = strlen(user_input);
        // checking for input and if the last char is new line char
        if (inp_len > 0 && inp_len < 100 && user_input[inp_len - 1] == '\n')
        {
            // removing new line char from input.
            user_input[inp_len - 1] = '\0';
        }
        else
        {
            puts("Taking input failed!");
            user_input[0] = '\0';
        }
    }
    return user_input;
}

// creating a new contact funciton
void create_new_contact(Phonebook *book)
{
    printf("Enter name: ");
    char *name = take_input();
    printf("Enter number: ");
    char *number = take_input();

    if (book->size >= book->capcity)
    {
        // increase capcity by twice or if it's zero then make it one.
        book->capcity = book->capcity == 0 ? 1 : book->capcity * 2;
        // allocate memory
        book->contacts = realloc(book->contacts, sizeof(Contact) * book->capcity);
        if (&book->capcity == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    strncpy(book->contacts[book->size].name, name, MAX_NAME - 1);
    strncpy(book->contacts[book->size].number, number, MAX_NUM - 1);

    // increase size by one.
    book->size++;
    puts("\n Contact added successfully \n");
    free(name);
    free(number);
}

// simple print function which loops over the array and print each
void print_contact_book(Phonebook *book)
{
    puts("\n------------------Contacts------------------\n");
    for (int i = 0; i < book->size; i++)
    {
        printf("%d: %s - %s\n", i + 1, book->contacts[i].name, book->contacts[i].number);
    }
    puts("\n--------------------------------------------\n");
}

// find a contact by it's name
void find_by_name(Phonebook *book)
{
    printf("Enter name: ");
    char *name = take_input();
    for (int i = 0; i < book->size; i++)
    {
        if (strstr(name, book->contacts[i].name))
        {
            puts("\n--------------------------------------------\n");
            printf("%d: %s - %s\n", i + 1, book->contacts[i].name, book->contacts[i].number);
            puts("\n--------------------------------------------\n");
        }
        else
        {
            continue;
        }
    }
    free(name);
}

// find a contact by it's number
void find_by_num(Phonebook *book)
{
    printf("Enter number: ");
    char *number = take_input();
    for (int i = 0; i < book->size; i++)
    {
        if (strstr(number, book->contacts[i].number))
        {
            puts("\n--------------------------------------------\n");
            printf("%d: %s - %s\n", i + 1, book->contacts[i].name, book->contacts[i].number);
            puts("\n--------------------------------------------\n");
        }
        else
        {
            continue;
        }
    }
    free(number);
}

// delete contact from book
void update_contact(Phonebook *book)
{
    int index;
    printf("Enter index of the contact: ");
    scanf("%d", &index);
    index = index - 1;
    if (index < 0 || index >= book->size)
    {
        puts("Invalid index try again!");
        exit(1);
    };

    // take opt to change number or name
    printf("for name enter (1) or for number enter (2): ");
    int option;
    scanf("%d", &option);

    clear_input_buffer();
    if (option == 1)
    {
        printf("Enter name: ");
        char *name = take_input();
        if (strlen(name) > 0)
        {
            strncpy(book->contacts[index].name, name, MAX_NAME - 1);
            book->contacts[index].name[MAX_NAME - 1] = '\0';
        }
        // strncpy(book->contacts[index].name, name, MAX_NAME - 1);
        free(name);
    }
    else if (option == 2)
    {
        printf("Enter number: ");
        char *number = take_input();
        if (strlen(number) > 0)
        {
            strncpy(book->contacts[index].number, number, MAX_NUM - 1);
            book->contacts[index].number[MAX_NUM - 1] = '\0';
        }
        // strncpy(book->contacts[index].number, number, MAX_NUM - 1);
        free(number);
    }
    else
    {
        puts("You have selected something wrong!");
    }

    puts("\nContact Updated Successfully\n");
};

// delete contact from book
void delete_contact(Phonebook *book)
{
    int index;
    printf("Enter index of the contact: ");
    scanf("%d", &index);

    index = index - 1;
    if (index < 0 || index >= book->size)
    {
        puts("Invalid index try again!");
    };

    // remove contact by shifting all the struct in array to left
    for (int i = index; i < book->size - 1; i++)
    {
        book->contacts[i] = book->contacts[i + 1];
    }

    // decrease book size;
    book->size--;
    puts("\nContact deleted Successfully\n");
};

// printing some helper text after each iteration
void print_menu()
{
    puts("---------------------------------------\n"
         "| It's a simple contact book cli tool.\n"
         "| 1. Create\n"
         "| 2. Delete\n"
         "| 3. Update\n"
         "| 4. Find by number\n"
         "| 5. Find by name\n"
         "| 6. List all contacts\n"
         "| 7. Exit\n"
         "---------------------------------------");
}

// Simple util function to clear input buffer
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
