#include <cs50.h>
#include <stdio.h>

int get_valid_int(void);
void print_spaces(int *spaces);
void print_hashes(int *side);

int main(void)
{
    int height = get_valid_int();
    int spaces = height;
    int right = 0;
    int left = 0;

    for (int rows = 0; rows < height; rows++)
    {
        print_spaces(&spaces);

        print_hashes(&left);

        printf("  ");

        print_hashes(&right);

        printf("\n");
    }
}

// Gets a height between 1 and 8
int get_valid_int(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    return n;
}

// Prints the spaces
void print_spaces(int *spaces)
{
    for (int i = 1; i < *spaces; i++)
    {
        printf(" ");
    }
    *spaces -= 1;
}

// Prints rows with hashes
void print_hashes(int *side)
{
    for (int i = 0; i <= *side; i++)
    {
        printf("#");
    }
    *side += 1;
}
