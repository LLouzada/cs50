#include <cs50.h>
#include <stdio.h>
#include <string.h>
//#include "subsfuctions.h"



int string_lenght(string text);
int keyok(string text, int lenght);
string cipher(string plaintext, string key);
string alllowc(string key, int lenght);

int main(int argc, string argv[])
{
    //code by llouzada

    //check if the user is using right the program "./substitution key"
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int klenght = string_lenght(key);

    //check if the key is ok (26 characters long)
    if (klenght != 26)
    {
        printf("key must be 26 charcters long, only alfhabetic characters and without repetitions\n");
        return 1;
    }
    else
    {
        int rtn = keyok(argv[1], klenght);
        if (rtn == 1 || rtn == 2)
        {
            printf("key must be 26 alphabetic characters long, and without repetitions\n");
            return 1;
        }
    }

    //ask user for text
    string plaintext = get_string("plaintext: ");
    //convert the user text
    key = alllowc(key, klenght);
    string ciphertext = cipher(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);



    //tests
    //printf("OK\n");
    //printf("%i\n", argc);
    //printf("%s\n", argv[1]);
    //printf("%s\n", arg);
    //printf("%i\n", lenght);
    //string test = alllowc(key, klenght);
    //printf("%s\n", test);
}

int string_lenght(string text)
{
    //calculate and return the lenght of a string
    int count = 0;
    do
    {
        count++;
    }
    while ((int)text[count] != 0);

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
            if (j == i)
            {
                j++;
            }
            else
            {
                if ((int)text[i] == (int)text[j] || (int)text[i] == (int)text[j] + 32 || (int)text[i] == (int)text[j] - 32)
                {
                    return 2;
                }
            }
        }
    }
    return 0;
}
string alllowc(string key, int lenght)
{
    //converts all key characters in lowercase
    for (int i = 0; i < lenght; i++)
    {
        if ((int)key[i] < 91)
        {
            key[i] = (int)key[i] + 32;
        }
    }

    return key;
}

string cipher(string plaintext, string key)
{
    //converts the text
    //11K, 12L, 13M, 14N, 15O
    //16P, 17Q, 18R, 19S, 20T, 21U, 22V, 23W, 24X, 25Y, 26Z.
    int plenght = string_lenght(plaintext);

    for (int i = 0; i < plenght; i++)
    {
        //uppercase
        if ((int)plaintext[i] < 91)
        {
            //A
            if ((int)plaintext[i] == 65)
            {
                plaintext[i] = (int)key[0] - 32;
            }
            //B
            else if ((int)plaintext[i] == 66)
            {
                plaintext[i] = (int)key[1] - 32;
            }
            //C
            else if ((int)plaintext[i] == 67)
            {
                plaintext[i] = (int)key[2] - 32;
            }
            //D
            else if ((int)plaintext[i] == 68)
            {
                plaintext[i] = (int)key[3] - 32;
            }
            //E
            else if ((int)plaintext[i] == 69)
            {
                plaintext[i] = (int)key[4] - 32;
            }
            //F
            else if ((int)plaintext[i] == 70)
            {
                plaintext[i] = (int)key[5] - 32;
            }
            //G
            else if ((int)plaintext[i] == 71)
            {
                plaintext[i] = (int)key[6] - 32;
            }
            //H
            else if ((int)plaintext[i] == 72)
            {
                plaintext[i] = (int)key[7] - 32;
            }
            //I
            else if ((int)plaintext[i] == 73)
            {
                plaintext[i] = (int)key[8] - 32;
            }
            //J
            else if ((int)plaintext[i] == 74)
            {
                plaintext[i] = (int)key[9] - 32;
            }
            //K
            else if ((int)plaintext[i] == 75)
            {
                plaintext[i] = (int)key[10] - 32;
            }
            //L
            else if ((int)plaintext[i] == 76)
            {
                plaintext[i] = (int)key[11] - 32;
            }
            //M
            else if ((int)plaintext[i] == 77)
            {
                plaintext[i] = (int)key[12] - 32;
            }
            //N
            else if ((int)plaintext[i] == 78)
            {
                plaintext[i] = (int)key[13] - 32;
            }
            //O
            else if ((int)plaintext[i] == 79)
            {
                plaintext[i] = (int)key[14] - 32;
            }
            //P
            else if ((int)plaintext[i] == 80)
            {
                plaintext[i] = (int)key[15] - 32;
            }
            //Q
            else if ((int)plaintext[i] == 81)
            {
                plaintext[i] = (int)key[16] - 32;
            }
            //R
            else if ((int)plaintext[i] == 82)
            {
                plaintext[i] = (int)key[17] - 32;
            }
            //S
            else if ((int)plaintext[i] == 83)
            {
                plaintext[i] = (int)key[18] - 32;
            }
            //T
            else if ((int)plaintext[i] == 84)
            {
                plaintext[i] = (int)key[19] - 32;
            }
            //U
            else if ((int)plaintext[i] == 85)
            {
                plaintext[i] = (int)key[20] - 32;
            }
            //V
            else if ((int)plaintext[i] == 86)
            {
                plaintext[i] = (int)key[21] - 32;
            }
            //W
            else if ((int)plaintext[i] == 87)
            {
                plaintext[i] = (int)key[22] - 32;
            }
            //X
            else if ((int)plaintext[i] == 88)
            {
                plaintext[i] = (int)key[23] - 32;
            }
            //Y
            else if ((int)plaintext[i] == 89)
            {
                plaintext[i] = (int)key[24] - 32;
            }
            //Z
            else if ((int)plaintext[i] == 90)
            {
                plaintext[i] = (int)key[25] - 32;
            }

        }
        else //lowercase
        {
            //a
            if ((int)plaintext[i] == 97)
            {
                plaintext[i] = (int)key[0];
            }
            //b
            else if ((int)plaintext[i] == 98)
            {
                plaintext[i] = (int)key[1];
            }
            //c
            else if ((int)plaintext[i] == 99)
            {
                plaintext[i] = (int)key[2];
            }
            //d
            else if ((int)plaintext[i] == 100)
            {
                plaintext[i] = (int)key[3];
            }
            //E
            else if ((int)plaintext[i] == 101)
            {
                plaintext[i] = (int)key[4];
            }
            //f
            else if ((int)plaintext[i] == 102)
            {
                plaintext[i] = (int)key[5];
            }
            //g
            else if ((int)plaintext[i] == 103)
            {
                plaintext[i] = (int)key[6];
            }
            //h
            else if ((int)plaintext[i] == 104)
            {
                plaintext[i] = (int)key[7];
            }
            //i
            else if ((int)plaintext[i] == 105)
            {
                plaintext[i] = (int)key[8];
            }
            //j
            else if ((int)plaintext[i] == 106)
            {
                plaintext[i] = (int)key[9];
            }
            //k
            else if ((int)plaintext[i] == 107)
            {
                plaintext[i] = (int)key[10];
            }
            //l
            else if ((int)plaintext[i] == 108)
            {
                plaintext[i] = (int)key[11];
            }
            //m
            else if ((int)plaintext[i] == 109)
            {
                plaintext[i] = (int)key[12];
            }
            //n
            else if ((int)plaintext[i] == 110)
            {
                plaintext[i] = (int)key[13];
            }
            //o
            else if ((int)plaintext[i] == 111)
            {
                plaintext[i] = (int)key[14];
            }
            //p
            else if ((int)plaintext[i] == 112)
            {
                plaintext[i] = (int)key[15];
            }
            //q
            else if ((int)plaintext[i] == 113)
            {
                plaintext[i] = (int)key[16];
            }
            //r
            else if ((int)plaintext[i] == 114)
            {
                plaintext[i] = (int)key[17];
            }
            //s
            else if ((int)plaintext[i] == 115)
            {
                plaintext[i] = (int)key[18];
            }
            //t
            else if ((int)plaintext[i] == 116)
            {
                plaintext[i] = (int)key[19];
            }
            //u
            else if ((int)plaintext[i] == 117)
            {
                plaintext[i] = (int)key[20];
            }
            //v
            else if ((int)plaintext[i] == 118)
            {
                plaintext[i] = (int)key[21];
            }
            //w
            else if ((int)plaintext[i] == 119)
            {
                plaintext[i] = (int)key[22];
            }
            //x
            else if ((int)plaintext[i] == 120)
            {
                plaintext[i] = (int)key[23];
            }
            //y
            else if ((int)plaintext[i] == 121)
            {
                plaintext[i] = (int)key[24];
            }
            //z
            else if ((int)plaintext[i] == 122)
            {
                plaintext[i] = (int)key[25];
            }
        }
    }
    return plaintext;
}
