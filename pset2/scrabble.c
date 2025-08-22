#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void winner(int s1, int s2);
int score(string w);

int main(void)
{
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    int score1 = score(w1);
    int score2 = score(w2);

    winner(score1, score2);
}

// Funcion that get's a String (word) and return an Int (score)
int score(string w)
{
    int score = 0;
    for (int i = 0, n = strlen(w); i < n; i++)
    {
        const char c = toupper(w[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' ||
            c == 'S' || c == 'T' || c == 'U')
        {
            score += 1;
        }
        else if (c == 'D' || c == 'G')
        {
            score += 2;
        }
        else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
        {
            score += 3;
        }
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
        {
            score += 4;
        }
        else if (c == 'K')
        {
            score += 5;
        }
        else if (c == 'J' || c == 'X')
        {
            score += 8;
        }
        else if (c == 'Q' || c == 'Z')
        {
            score += 10;
        }
    }
    return score;
}

// Function thats gets two Int (scores) and return a String (winner or tie)
void winner(int s1, int s2)
{
    if (s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if (s1 < s2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
