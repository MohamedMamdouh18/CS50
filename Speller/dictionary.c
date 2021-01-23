// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"

// Number of buckets in hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;



// Hash table
node *table[N];
int words = 0 ;


// Hashes word to a number
unsigned int hash(const char *word)
{
    int n;
    int hash = 0;
    for (int count = 0; count < strlen(word); count++)
    {
        n = word[count] - 'a' + 1 ;
        hash = (n + (hash << 3)) % N ;  //the hash value ranges from 0:N
    }

    return hash ;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char checked_word[strlen(word)] ;
    strcpy(checked_word, word) ;  //make a copy because the word is const
    for (int i = 0 ; i < strlen(word) ; i ++)
    {
        checked_word[i] = tolower(checked_word[i]) ;  // turning all the letters to smallcase
    }
    int h = hash(checked_word) ;

    //check the word in the dictionary-hashtable-
    for (node *check = table[h] ; check != NULL ; check = check->next)
    {
        if (!strcmp(check->word, checked_word))
        {
            //return true if exists
            return true ;
        }
    }
    return false ;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open the dictionary to hash the words
    FILE *fptr = fopen(dictionary, "r");

    if (fptr == NULL)
    {
        return false ;
    }

    //assign all hashtable pointers to null
    for (int i = 0 ; i < N ; i ++)
    {
        table[i]  = NULL ;
    }
    int h ;
    char word[LENGTH + 1];
    node *test ;

    //get all the words from dictionary
    while (fscanf(fptr, "%s", word) != EOF)
    {
        do
        {
            test =  malloc(sizeof(node));
            if (test == NULL)
            {
                free(test) ;
            }
        }
        while (test == NULL) ;

        h = hash(word);
        strcpy(test -> word, word);
        test -> next = table[h] ;
        table[h] = test ;
        words ++ ;
    }

    fclose(fptr);
    return true ;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (words >= 1)
    {
        return words ;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (words == 0)
    {
        return false ;
    }
    else
    {
        //free all memory if words!= 0
        for (int i = 0 ; i < N ; i++)
        {
            while (table[i] != NULL)
            {
                node *tmp = table[i]->next;
                free(table[i]);
                table[i] = tmp;
            }
        }
    }

    return true ;
}
