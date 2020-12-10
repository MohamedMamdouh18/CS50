#include <stdio.h>
#include <stdlib.h>
#include <cs50.c>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //first thing check the validation of the key
    if (argc != 2) //we check if the key is written or not
    {
        printf("Usage: ./substitution KEY \n");
        return 1 ;
    }
    else
    {
        if (strlen(argv[1]) != 26) //we check the key length
        {
            printf("Key must contain 26 characters \n");
            return 1;
        }
        else
        {
            for (int i = 0 ; i < strlen(argv[1]) ; i ++) //we check if the key contain non-alphabetic characters
            {
                if (isalpha(argv[1][i]) == false)
                {
                    printf("key must only obtain alphabetic characters \n");
                    return 1;
                }
                for (int j = 0 ; j < i ; j ++)
                {
                    if (argv[1][j] == argv[1][i]) //we check foe the repeated characters
                    {
                        printf("key must not contain repeated characters \n");
                        return 1 ;
                    }
                }
            }
        }
    }
    char capitals[27] = {0}; //we make 2 arrays and put the priginal alphabet characters in it
    char lowers[27] = {0};

    for (int l = 0 ; l < 26 ; l ++)
    {
        capitals[l] += 65 + l ;
    }

    for (int t = 0 ; t < 26 ; t ++)
    {
        lowers[t] += 97 + t ;
    }


    for (int p = 0 ; p < 26 ; p ++) // we transfer all the key to upper case characters
    {
        if (islower(argv[1][p]))
        {
            argv[1][p] -= 32 ;
        }
    }



    string plaintext = get_string("","plaintext:");


    for (int z = 0 ; z < strlen(plaintext) ; z ++) // the encryotion starts here
    {
        for (int x = 0 ; x < strlen(argv[1]) ; x ++)
        {
            if (isupper(plaintext[z]))
            {
                if (plaintext[z] == capitals[x]) //we encrypt upper case characters
                {
                    plaintext[z] = argv[1][x] ;
                    break ;
                }
            }
            else if (islower(plaintext[z]))
            {
                if (plaintext[z] == lowers[x]) //we encrypt lowe case characters
                {
                    plaintext[z] = argv[1][x] + 32 ;
                    break ;
                }
            }
        }
    }

    printf("ciphertext: %s\n", plaintext); //voila

}
