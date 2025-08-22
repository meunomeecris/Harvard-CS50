#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string user_name = get_string("Tell me your name, humain? ");

    printf("hello, %s\n", user_name);
}
