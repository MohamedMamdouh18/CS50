#include <stdio.h>
#include <cs50.c>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
    string text = get_string("Text:"); //prompt user for the text

    int letters = 0 ;        //define all the vars
    int sents = 0 ;
    int words = 1 ;          //words = 1 because we have a word in the first

    for (int i = 0 ; i < strlen(text) ; i ++)  //make a loop to check all the strings using strlen which calculate the text lenghth
    {
        if ((text[i] != ' ') && (ispunct(text[i]) == false))
        {
            letters ++ ;
        }

        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sents ++ ;
        }

        if (((text[i] == ' ') && (text[ i + 1] != ' ')) || ((text[i] == 39) && (text[i + 1] == 'v')))
        {
            words ++ ;
        }
    }

    float l = (letters * 100) / words ; //l is the average letters every 100 words
    float s = (sents * 100) / words ; // s is the average senteces every 100 words

    float index = 0.0588 * l - 0.296 * s - 15.8 ; // then apply the algorithm

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
