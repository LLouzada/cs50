#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}

int compute_score(string word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        //check if the letter is actualy a letter
        if (((int) word[i] >= 65 && (int) word[i] <= 90) || ((int) word[i] >= 97 && (int) word[i] <= 122))
        {
            //check if the letter is (D or d) or (G or g)
            if (((int) word[i] == 68 || (int) word[i] == 100) || ((int) word[i] == 71 || (int) word[i] == 103))
            {
                sum += 2;
            }
            //check if the letter is (B or b) or (C or c)
            else if (((int) word[i] == 66 || (int) word[i] == 98) || ((int) word[i] == 67 || (int) word[i] == 99))
            {
                sum += 3;
            }
            //check if the letter is (M or m) or (P or p)
            else if (((int) word[i] == 77 || (int) word[i] == 109) || ((int) word[i] == 80 || (int) word[i] == 112))
            {
                sum += 3;
            }
            //check if the letter is (F or f) or (H or h)
            else if (((int) word[i] == 70 || (int) word[i] == 102) || ((int) word[i] == 72 || (int) word[i] == 104))
            {
                sum += 4;
            }
            //check if the letter is (V or v) or (W or w) or (Y or y)
            else if (((int) word[i] == 86 || (int) word[i] == 118) || ((int) word[i] == 87 || (int) word[i] == 119) || ((int) word[i] == 89 || (int) word[i] == 121))
            {
                sum += 4;
            }
            //check if the letter is (K or k)
            else if (((int) word[i] == 75 || (int) word[i] == 107))
            {
                sum += 5;
            }
            //check if the letter is (J or j) or (X or x)
            else if (((int) word[i] == 74 || (int) word[i] == 106) || ((int) word[i] == 88 || (int) word[i] == 120))
            {
                sum += 8;
            }
            //check if the letter is (Q or q) or (Z or z)
            else if (((int) word[i] == 81 || (int) word[i] == 113) || ((int) word[i] == 90 || (int) word[i] == 122))
            {
                sum += 10;
            }
            else
            {
                sum += 1;
            }
        }
        else
        {
            sum += 0;
        }
    }
    return sum;
}
