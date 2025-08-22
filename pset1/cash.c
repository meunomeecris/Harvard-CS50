#include <cs50.h>
#include <stdio.h>

int get_valid_int(void);
void calculate_coins(int *coins, int *remainder, int *change, int valeur_coin);
void calculate_change(void);

int main(void)
{
    calculate_change();
}

// Get int more then 0
int get_valid_int(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);
    return n;
}

// Give the numbers of coins for each change
void calculate_coins(int *coins, int *remainder, int *change, int valeur_coin)
{
    *coins += *remainder / valeur_coin;
    *remainder -= (valeur_coin * *coins);
    *change += *coins;
}

// Take the change and transforme in numbers of coins
void calculate_change(void)
{
    int change = get_valid_int();
    int remainder = change;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int coins_to_change = 0;

    do
    {
        if (remainder / 25)
        {
            calculate_coins(&quarters, &remainder, &coins_to_change, 25);
        }
        else if (remainder / 10)
        {
            calculate_coins(&dimes, &remainder, &coins_to_change, 10);
        }
        else if (remainder / 5)
        {
            calculate_coins(&nickels, &remainder, &coins_to_change, 5);
        }
        else if (remainder / 1)
        {
            calculate_coins(&pennies, &remainder, &coins_to_change, 1);
        }
    }
    while (remainder != 0);

    printf("%i\n", coins_to_change);
}
