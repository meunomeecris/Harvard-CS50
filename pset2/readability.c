#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int formula_coleman_liau(float l, float s);
void grade_level(int g);
float average_l(string t);
float average_s(string t);
float count_words(string t);
float count_sentences(string t);
float count_letters(string t);

int main(void)
{
    string t = get_string("Text: ");
    float l = average_l(t);
    float s = average_s(t);
    int f = formula_coleman_liau(l, s);
    grade_level(f);
}

// Calculate grade's level
void grade_level(int g)
{
    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (g >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", g);
    }
}

// Formula Coleman Liau
int formula_coleman_liau(float l, float s)
{
    return round((0.0588 * l) - (0.296 * s) - 15.8);
}

// Calculate L = (Total letters ÷ Total Words) × 100
float average_l(string t)
{
    float w = count_words(t);
    float l = count_letters(t);
    return (l / w) * 100;
}

// Calculate S =(Total Sentences ÷ Total Words) × 100
float average_s(string t)
{
    float s = count_sentences(t);
    float w = count_words(t);
    return (s / w) * 100;
}

// Calculate words based on the number of spaces
float count_words(string t)
{
    float w = 1.0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (isspace(t[i]))
        {
            w += 1.0;
        }
    }
    return w;
}

// Calculate setences based on the number of ponctuations
float count_sentences(string t)
{
    float s = 0.0;
    for (int i = 0, n = strlen(t); i < n; i++)
        if (t[i] == '.' || t[i] == '?' || t[i] == '!')
        {
            s += 1.0;
        }
    return s;
}

// Calculate the letters in a string whitout ponctuagtions or spaces
float count_letters(string t)
{
    float p = 0.0;
    float w = count_words(t) - 1;
    float l = strlen(t);

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (ispunct(t[i]))
        {
            p += 1.0;
        }
    }
    return l - p - w;
}
