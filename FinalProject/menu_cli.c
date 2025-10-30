#include "cs50.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int logo(void);

int menu_cli(void)
{
    char n;
    logo();
    sleep(2);

    printf("\n");
    printf("     \033[0;32m-------------------------------\n");
    printf("          WELCOME TO MAC CLEANUP    \n");
    printf("     ---------- CS50 2025 ----------\n");
    printf("          made by Cris Messias      \n");
    printf("     -------------------------------\033[0m\n");

    sleep(1);

    printf("\n");
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


int logo() 
{
    const char *lines[] = {
        "                        .8 ",
        "                      .888",
        "                    .8888'",
        "                   .8888'",
        "                   888'",
        "                   8'",
        "      .88888888888. .88888888888.",
        "   .8888888888888888888888888888888.",
        " .8888888888888888888888888888888888.",
        ".&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&'",
        "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&'",
        "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&'",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%.",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%.",
        "`%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%.",
        " `00000000000000000000000000000000000'",
        "  `000000000000000000000000000000000'",
        "   `0000000000000000000000000000000'",
        "     `###########################'",
        "jgs    `#######################'",
        "         `#########''########'",
        "           `\"\"\"\"\"\"'  `\"\"\"\"\"' ",
        ""
    };
    

    // Número de linhas
    size_t n_lines = sizeof(lines) / sizeof(lines[0]);

    // Imprime cada linha
    for (size_t i = 0; i < n_lines; ++i)
    {
        printf("\033[0;32m");
        puts(lines[i]);
        printf("\033[0m");
    }

    return 0;
}