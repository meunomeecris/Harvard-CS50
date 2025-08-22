#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int is_key_alphabetical(string k);
int is_valid_key(int n, string k);
void ciphertext(string p, string k);
int is_unique_key(string k);
const string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (is_valid_key(argc, argv[1]) == 1)
    {
        return 1;
    }
    else
    {
        string p = get_string("plaintex: ");
        ciphertext(p, argv[1]);
    }
    return 0;
}

// Cipher algorithm based on the key
void ciphertext(string p, string k)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isalpha(p[i]) == 0)
        {
            printf("%c", p[i]);
        }
        else
        {
            for (int j = 0, m = strlen(a); j < m; j++)
            {
                if (toupper(p[i]) == a[j])
                {
                    if (islower(p[i]) != 0)
                    {
                        printf("%c", tolower(k[j]));
                    }
                    else
                    {
                        printf("%c", toupper(k[j]));
                    }
                    break;
                }
            }
        }
    }
    printf("\n");
}

// Check valid command-line arguments
int is_valid_key(int n, string k)
{
    if (n != 2)
    {
        printf("Missing key.\n");
        return 1;
    }
    else if (strlen(k) != 26)
    {
        printf("Key must be 26 characters long.\n");
        return 1;
    }
    else if (is_key_alphabetical(k) == 1)
    {
        printf("Key must contain only alphabetical characters.\n");
        return 1;
    }
    else if (is_unique_key(k) == 1)
    {
        printf("Key must contains uniques characters.\n");
        return 1;
    }
    return 0;
}

// Check if string is alphabetical
int is_key_alphabetical(string k)
{
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isalpha(k[i]) == 0)
        {
            return 1;
            break;
        }
    }
    return 0;
}

// Check if the key has 26 uniques characters
int is_unique_key(string k)
{
    int n = strlen(k);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (toupper(k[i]) == toupper(k[j]))
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}
