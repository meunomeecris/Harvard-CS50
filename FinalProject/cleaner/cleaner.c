#include "cs50.h"
#include "menu_cli.h"
#include "core.h"
#include <stdio.h>
#include <unistd.h>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void print_logo(void);

int main(void)
{
    int user_option;

    print_logo();
    sleep(2);
    show_welcome();

    while (true)
    {
        user_option = menu_cli();

        if (user_option == 0)
        {   
            sleep(1);
            printf(GREEN "=========== MAC CLEANUP ===========\n");
            printf("See next time you mac freez!\n" RESET);
            sleep(1);
            print_logo();
            break;
        }

        read_and_clean(&user_option);
        
        sleep(1);
        printf(YELLOW "\nPress ENTER to return to the menu" RESET);
        getchar(); 
    }

return 0;
}

void print_logo(void) 
{
    printf(GREEN "\n");
    printf("                                ,----,.               \n");
    printf("                              ,'   ,' |               \n");
    printf("                            ,'   .'   |    ,----..    \n");
    printf("                          ,----.'    .'   /   /   \\   \n");
    printf("                          |    |   .'    /   .     :  \n");
    printf("                .--.--.   :    :  |--,  .   /   ;.  \\ \n");
    printf("       ,---.   /  /    '  :    |  ;.' \\.   ;   /  ` ; \n");
    printf("      /     \\ |  :  /`./  |    |      |;   |  ; \\ ; | \n");
    printf("     /    / ' |  :  ;_    `----'.'\\   ;|   :  | ; | ' \n");
    printf("    .    ' /   \\  \\    `.   __  \\  .  |.   |  ' ' ' : \n");
    printf("    '   ; :__   `----.   \\/   /\\/  /  :'   ;  \\; /  | \n");
    printf("    '   | '.'| /  /`--'  / ,,/  ',-   . \\   \\  ',  /  \n");
    printf("    |   :    :'--'.     /\\ ''\\       ;   ;   :    /   \n");
    printf("     \\   \\  /   `--'---'  \\   \\    .'     \\   \\ .'    \n");
    printf("      `----'               `--`-,-'        `---`      \n");
    printf("                                                       \n");
    printf("\n" RESET);
}
