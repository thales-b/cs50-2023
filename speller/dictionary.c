#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} node;

// Number of buckets in the hash table
const unsigned int N = 26;

// Hash table
node* table[N];

int num_words = 0;

// Hashes word to a number
unsigned int hash(const char* word)
{
    // Simple hash function that maps the first character to the range 0-25
    return tolower(word[0]) - 'a';
}

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    int index = hash(word);
    node* n = table[index];
    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char* dictionary)
{
    // Open dictionary file
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return false;
    }

    // Clear the hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Buffer for reading words
    char word[LENGTH + 1];

    // Read words from dictionary file
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            printf("Failed to allocate memory for node\n");
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Hash word to get index
        int index = hash(word);

        // Insert new node into hash table
        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            // Add new node to the beginning of the linked list
            new_node->next = table[index];
            table[index] = new_node;
        }

        num_words++;
    }

    // Close dictionary file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return num_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* n = table[i];
        while (n != NULL)
        {
            node* temp = n;
            n = n->next;
            free(temp);
        }
    }

    num_words = 0;

    return true;
}
