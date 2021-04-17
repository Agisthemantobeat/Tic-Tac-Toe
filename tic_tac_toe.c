/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char square[3][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

int check();
void chessboard();
void printWelcomeMessage();

int main()
{
    int player = 1, i, choice;

    char mark;
    do
    {
        printWelcomeMessage();
        chessboard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        if (choice >0 && choice <=9)
        {
        if (choice == 1 && square[0][0] == '1')
            square[0][0] = mark;
            
        else if (choice == 2 && square[0][1] == '2')
            square[0][1] = mark;
            
        else if (choice == 3 && square[0][2] == '3')
            square[0][2] = mark;
            
        else if (choice == 4 && square[1][0] == '4')
            square[1][0] = mark;
            
        else if (choice == 5 && square[1][1] == '5')
            square[1][1] = mark;
            
        else if (choice == 6 && square[1][2] == '6')
            square[1][2] = mark;
            
        else if (choice == 7 && square[2][0] == '7')
            square[2][0] = mark;
            
        else if (choice == 8 && square[2][1] == '8')
            square[2][1] = mark;
            
        else if (choice == 9 && square[2][2] == '9')
            square[2][2] = mark;
            
        else
        {
            printf("Wait for a while, Invalid move \n");
            sleep(2);
            player--;
         
        }
            
        }
        else
        {
            printf("Wait for a while, Invalid move \n");
            sleep(2);
            player--;
        }
        i = check();

        player++;
    }while (i ==  - 1);
    
    chessboard();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");



}

/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int check()
{
    if (square[0][0] == square[0][1] && square[0][1] == square[0][2])
        return 1;
        
    else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])
        return 1;
        
    else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])
        return 1;
        
    else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])
        return 1;
        
    else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])
        return 1;
        
    else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])
        return 1;
        
    else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
        return 1;
        
    else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
        return 1;
        
    else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' &&
        square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0] 
        != '7' && square[2][1] != '8' && square[2][2] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void chessboard()
{
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[0][0], square[0][1], square[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[1][0], square[1][1], square[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[2][0], square[2][1], square[2][2]);

    printf("     |     |     \n\n");
}

/*******************************************************************
FUNCTION TO PRINT WELCOME MESSAGE ON START OF GAME
 ********************************************************************/

void printWelcomeMessage()
{
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
    printf("|   Apporv Gupta   |\n");
    printf("|  Vishesh Dvivedi |\n");
    printf("--------------------\n");
    printf("\n");
    
}

/*******************************************************************
END OF PROJECT
 ********************************************************************/
