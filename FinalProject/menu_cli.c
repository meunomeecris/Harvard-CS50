#include "cs50.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int welcome(void);
void menu(void);
int selectOption(void);

int menu_cli(void)
{
    welcome();
    printf("\n");
    menu();

    return selectOption();
}

int welcome(void) 
{
    printf("\n");
    printf("     \033[0;32m-------------------------------\n");
    printf("          WELCOME TO MAC CLEANUP    \n");
    printf("     ---------- CS50 2025 ----------\n");
    printf("          made by Cris Messias      \n");
    printf("     -------------------------------\033[0m\n");

    sleep(1);

    return 0;
}

void menu(void) 
{
    printf("          \033[0;32m---------------------\n");
    printf("          |     MENU OPTIONS   |\n");
    printf("          ---------------------\n");
    printf("          | 1: Cleanup Caches  |\n");
    printf("          ---------------------\n");
    printf("          | 2: Cleanup Logs    |\n");
    printf("          ---------------------\n");
    printf("          | 3: Cleanup Cookies |\n");
    printf("          ---------------------\n");
    printf("          | 4: Cleanup Xcode   |\n");
    printf("          ---------------------\n");
    printf("          | 5: Cleanup All     |\n");
    printf("          ---------------------\033[0m\n");
    printf("\n");
    
    sleep(2);
}

int selectOption(void) 
{
    char n;

    do
    {
        printf("\033[0;32m\n");
        n = get_char("Select option > ");
        printf("\033[0m\n");

        if (isdigit(n) && n >= '1' && n <= '5')
        {
            break;
        }
        else
        {
            printf("\033[0;31m");
            printf("Invalid input, try again.\n");
        }
    }
    while (true);
    
    // Convert type Char to Int
    return n - '0';

}