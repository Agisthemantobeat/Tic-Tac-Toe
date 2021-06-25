/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*******************************************************************
START OF PROJECT
********************************************************************/

// Defining preprocessor directives
#include <stdio.h>
#include <stdlib.h>

// Defining Constants
#define X 'X'
#define O '0'
#define WAIT 4

/*

Creating node structure which stores the following values:
[int] position:      which stores the position of the character within the board.
[char] character:    which stores the character placed within the block inside the board.
[struct] node *next: pointer that stores the address of the next node.

*/
struct node
{
    int position;
    char character;
    struct node *next;
    
}*start = NULL;

// Declaring and Initlalizing prev_node which is used while creating the linked list
struct node *prev_node = NULL;

// This function clears the console screen and prints the ASCII art of this script
void printWelcomeMessage()
{
    system("clear");
    printf("'########:'####::'######:::::'########::::'###:::::'######:::::'########::'#######::'########:\n");
    printf("... ##..::. ##::'##... ##::::... ##..::::'## ##:::'##... ##::::... ##..::'##.... ##: ##.....::\n");
    printf("::: ##::::: ##:: ##:::..:::::::: ##:::::'##:. ##:: ##:::..:::::::: ##:::: ##:::: ##: ##:::::::\n");
    printf("::: ##::::: ##:: ##::::::::::::: ##::::'##:::. ##: ##::::::::::::: ##:::: ##:::: ##: ######:::\n");
    printf("::: ##::::: ##:: ##::::::::::::: ##:::: #########: ##::::::::::::: ##:::: ##:::: ##: ##...::::\n");
    printf("::: ##::::: ##:: ##::: ##::::::: ##:::: ##.... ##: ##::: ##::::::: ##:::: ##:::: ##: ##:::::::\n");
    printf("::: ##::::'####:. ######:::::::: ##:::: ##:::: ##:. ######:::::::: ##::::. #######:: ########:\n");
    printf(":::..:::::....:::......:::::::::..:::::..:::::..:::......:::::::::..::::::.......:::........::\n");
    printf("\n");
    printf("--------------------\n");
    printf("|    CREATORS:     |\n");
    printf("|    Arifa Arif    |\n");
    printf("|   Apoorv Gupta   |\n");
    printf("|  Vishesh Dvivedi |\n");
    printf("--------------------\n");
    printf("\n");
}

/* 

This function is used to append node to the linked list

Required parameters:
[int] position:   The value of position to be stored within the new node
[char] character: The character value to be stored within the new node

*/
void insertNode(int position, char character)
{
    struct node *current_node = NULL;
    current_node = (struct node*)malloc(sizeof(struct node));
    
    if(current_node == NULL)
    {
        printf("\n[ERROR] Memory cannot be allocated.\n");
        exit(0);
    }
    else
    {
        current_node->position = position;
        current_node->character = character;
        current_node->next = NULL;
        
        prev_node->next = current_node;
        prev_node = current_node;
    }
}

/*

This function is used to create the linked list which stores the value of board

*/
void createBoard()
{
    start = (struct node*)malloc(sizeof(struct node));
    if(start == NULL)
    {
        printf("\n[ERROR] Memory cannot be allocated.\n");
        exit(0);
    }
    else
    {
        start->position = 1;
        start->character = '1';
        start->next = NULL;
        prev_node = start;
    }
    
    for (int i=2; i<10; i++)
    {
        insertNode(i, i+'0');
    }
}

/*

This function is used to check if a certain position within the board is empty or not_eq

Required parameters:
[int] position: The position within the board to be checked.

Return:
[int] : Returns 1 if position is not occupied, else 0

*/
int checkPosition(int position)
{
    struct node *prev_node = start;
    while (prev_node!= NULL)
    {
        if(prev_node->position == position)
        {
            if ((prev_node->character==X) || (prev_node->character==O))
            {
                printf("\n[ERROR] Position %d is already occupied. Please choose another position.\n\n", position);
                sleep(WAIT);
                return 0;
            }
            else
            {
                return 1;
            }
        }
        prev_node = prev_node->next;
    }
}

/*

This function is used to insert a character at a certain position within the board.

Required parameters:
[int] position: The position to store the character within the board.
[char] character: The character to insert at the position.

*/
void insertCharacterAtPosition(int position, char character)
{
    struct node *prev_node = start;
    while (prev_node!= NULL)
    {
        if(prev_node->position == position)
        {
            prev_node->character = character;
        }
        prev_node = prev_node->next;
    }
}

/*

This function is used to check whether any user has won the game or not.

Return:
[int] : Returns 1 if any user wins, else 0 if no user won.

*/
int checkWin()
{
    struct node *prev_node = start;
    char charList[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for(int i=0; i<9; i++)
    {
        charList[i] = prev_node->character;
        prev_node = prev_node->next;
    }
    
    // Checking for horizontal victory
    for(int i=0; i<9; i+=3)
    {
        if ((charList[i] == charList[i+1]) && (charList[i] == charList[i+2]))
        {
            return 1;
        }
    }
    
    // Checking for vertical victory
    for(int i=0; i<3; i++)
    {
        if ((charList[i] == charList[i+3]) && (charList[i+3] == charList[i+6]))
        {
            return 1;
        }
    }
    
    // Checking for diagonal victory
    if ((charList[0] == charList[4]) && (charList[4] == charList[8]))
    {
        return 1;
    }
    else if ((charList[2] == charList[4]) && (charList[4] == charList[6]))
    {
        return 1;
    }
    
    return 0;
}

/*

This function is used to display the welcome message along with the game board.

*/
void display()
{
    printWelcomeMessage();
    struct node *prev_node;
    if(start == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int counter=0;
        prev_node = start;
        printf("\n");
        while(prev_node!=NULL)
        {
            for (int i=0; i<3; i++)
            {
                printf("     |     |     \n");
                for (int j=0; j<3; j++)
                {
                    if (j != 2)
                    {
                        printf("  %c  |", prev_node->character);
                        prev_node = prev_node->next;
                        counter ++;
                    }
                    else
                    {
                        printf("  %c  ", prev_node->character);
                        prev_node = prev_node->next;
                        counter++;
                    }
                }
                if (counter != 9)
                {
                    printf("\n_____|_____|_____\n");
                }
                else
                {
                    printf("\n     |     |     \n");
                }
            }
        }
    }
}

/*

Main function of the script.

*/
void main()
{
    int counter = 0, position=0, num=0;
    char character, choice[100];
    createBoard();
    while (counter < 9)
    {
        display();
        num = counter % 2;
        if (num == 0)
        {
            character = X;
        }
        else
        {
            character = O;
        }
        
        printf("\nPlayer %d, enter your choice: ", num+1);
        gets(choice);
        position = atoi(choice);
        if ((position >= 1) && (position <= 9))
        {
            if (checkPosition(position))
            {
                insertCharacterAtPosition(position, character);
                if(checkWin())
                {
                    display();
                    printf("\nConguratulations !!! Player %d won !!!", num+1);
                    break;
                }
            }
            else
            {
                continue;
            }
            counter++;
        }
        else
        {
            printf("\n[ERROR] Invalid input...Please enter a number between 1 and 9\n");
            sleep(WAIT);
        }
    }
    if(counter == 9)
    {
        display();
        printf("\nThe match ended with a DRAW !!! Better Luck Next Time !!!");
    }
}


/*******************************************************************
END OF PROJECT
********************************************************************/
