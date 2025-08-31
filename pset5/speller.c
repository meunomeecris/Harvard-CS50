// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 143000;

// Hash table
node *table[N];

// Count nodes in Hash table
unsigned int hash_count;

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Sum of values of each char based on the ASCII Table
        sum += toupper(word[i]);
    }

    // In case the sum cant be stored in the hash table
    if (sum > N)
        sum %= N;

    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    // Read each word in the fil
    char new_word[LENGTH + 1];
    while (fscanf(file, "%s", new_word) != EOF)
    {
        // Add each word to the hash table
        // Create space for a new hash table node
        node *new_node = malloc(sizeof(node));
        if (file == NULL)
            return false;

        // Copy the word into the new node
        strcpy(new_node->word, new_word);
        new_node->next = NULL;

        // Hash the word to obtain its hash value
        unsigned int hash_value = hash(new_word);

        // Insert the new node into the hash table (using the index specified by its hash value)
        new_node->next = table[hash_value];
        table[hash_value] = new_node;
        hash_count++;
    }

    // Close the dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return hash_count;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get the head of the link list
    node *table_head = table[hash(word)];
    // Set cursor point trough the link list
    node *cursor = table_head;

    while (cursor != NULL)
    {
        // Check if the  any of the nodes from that link list has the word
        if (strcasecmp(cursor->word, word) == 0)
        {
            return 1;
        }
        // Set the cursor as the next node
        cursor = cursor->next;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through each hast table
    for (int i = 0; i < N; i++)
    {
        // Get the head of the link list
        node *table_head = table[i];
        // Set cursor point trough the link list
        node *cursor = table_head;
        node *tmp;

        while (cursor != NULL)
        {
            // Set the temporary node as the same as cursor
            tmp = cursor;
            // Then override the cursos with the next node
            cursor = cursor->next;
            // Free the memory allocated to that node
            free(tmp);
        }
    }

    return 1;
}
