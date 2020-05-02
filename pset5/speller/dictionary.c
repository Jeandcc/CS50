// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>


#include "dictionary.h"

int amountOfLoadedWords = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 51795;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashIndex = hash(word);
    for (node *tmp = table[hashIndex]; tmp != NULL; tmp = tmp->next)
    {
        // printf("Dictionary Word: %s\nTested Word: %s\n", tmp->word, word);
        if(strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int wordLength = 0;
    int cummulate = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        wordLength++;
        int currentChar = (int) (toupper(word[i])) - 65;
        if(currentChar < 0)
        {
            currentChar = 25;
        }
        cummulate += (currentChar*wordLength);
    }

    return (wordLength * 26) + cummulate;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Opens the file and handles errors
    FILE *file = fopen(dictionary, "r");
    if(!file)
    {
        return false;
    }

    // Read each string from file (one at a time)
    char wordBuffer[LENGTH + 1];


    while(fscanf(file, "%s", wordBuffer) != EOF)
    {
        // printf("%s\n",wordBuffer);

        // Create a new node for each word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return 1;
        }
        strcpy(newNode->word, wordBuffer);
        newNode->next = NULL;

        // Call hash(word) to determine what index to be inserted in the hash table
        int hashIndex = hash(wordBuffer);
        // printf("%i\n",hashIndex);

        // Insert node to hash table on corrrect location
        if(table[hashIndex])
        {
            newNode->next = table[hashIndex];
        }
        table[hashIndex] = newNode;
        amountOfLoadedWords++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return amountOfLoadedWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        node *ptr = table[i];

        while (ptr)
        {
            node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    return true;
}
