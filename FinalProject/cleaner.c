#include "cs50.h"
#include "menu_cli.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(void)
{
    int input = menu_cli();
    printf("Option: %d\n", input);
}




