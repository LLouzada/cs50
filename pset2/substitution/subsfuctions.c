#include "subsfuctions.h"
#include <stdio.h>
#include <cs50.h>

int string_lenght(string text)
{
    //calculate and return the lenght of a string
    int count = 0;
    do
    {
        count++;
    }while ((int)text[count] != 0 );

    return count;

}

int keyok(string text, int lenght)
{
    //checks if the string contains only alphabetic char
    for (int i = 0; i < lenght; i++)
    {
        if ((int)text[i] < 65 || ((int)text[i] > 90 && (int)text[i] < 97) || (int)text[i] > 122)
        {
            return 1;
        }
    }

    //checks if the string has repetitions
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            if ( j == i)
            {
                j++;
            }
            else
            {
                if((int)text[i] == (int)text[j] || (int)text[i] == (int)text[j] + 32 || (int)text[i] == (int)text[j] - 32)
                {
                    return 2;
                }
            }
        }
    }
    return 0;
}