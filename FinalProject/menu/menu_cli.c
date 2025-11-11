#include "cs50.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"


int show_welcome(void);
void show_menu(void);
int verify_user_option(void);

int menu_cli(void)
{
    printf("\n");
    show_menu();

    return verify_user_option();
}

int show_welcome(void) 
{
    printf("\n");
    printf(GREEN "     ===============================\n");
    printf("          WELCOME TO MAC CLEANUP    \n");
    printf("            for iOS Developers    \n");
    printf("     ---------- CS50 2025 ----------\n");
    printf("          made by Cris Messias      \n");
    printf("     ===============================" RESET);

    sleep(3);

    return 0;
}

void show_menu(void) 
{
    printf(GREEN "          -----------------------\n");
    printf("          |#### MENU OPTIONS ####|\n");
    printf("          -----------------------\n");
    printf("          | 1: Cleanup Caches    |\n");
    printf("          -----------------------\n");
    printf("          | 2: Cleanup Logs      |\n");
    printf("          -----------------------\n");
    printf("          | 3: Cleanup Cookies   |\n");
    printf("          -----------------------\n");
    printf("          | 4: Cleanup Xcode     |\n");
    printf("          -----------------------\n");
    printf("          | 5: Cleanup All       |\n");
    printf("          -----------------------\n");
    printf("          | 0: Exit              |\n");
    printf("          -----------------------" RESET);
    printf("\n");
    
    sleep(1);
}

int verify_user_option(void) 
{
    char n;

    do
    {
        printf("\033[0;32m\n");
        n = get_char("Select option > ");
        printf("\033[0m\n");

        if (isdigit(n) && n >= '0' && n <= '5')
        {
            break;
        }
        else
        {
            printf(RED "Invalid input, try again.\n" RESET);
        }
    }
    while (true);
    
    // Convert type Char to Int
    return n - '0';

}