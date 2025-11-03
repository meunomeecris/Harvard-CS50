#include "cs50.h"
#include "menu_cli.h"
#include "core.h"
#include <stdio.h>

// Max number of candidates
#define MAX 9

int main(void)
{
    int user_option = menu_cli();
    printf("You choose option: %d\n", user_option);

    read_and_clean(&user_option);

    return 0;
}
