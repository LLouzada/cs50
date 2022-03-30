#include <cs50.h>
#include <stdio.h>
#include <math.h>
int rounded(float num);

int count_lenght(string text);
int count_letters(string text, int lenght);
int count_words(string text, int lenght);
int count_sentences(string text, int lenght);
int coleman_index(int letters, int words, int sentences);


int main(void)
{

    string text = get_string("Text: ");

    //count the lenght, letters, words and senteces in the string
    int lenght = count_lenght(text);
    int letters = count_letters(text, lenght);
    int words = count_words(text, lenght);
    int sentences = count_sentences(text, lenght);

    // The Coleman-Liau index
    int grade = coleman_index(letters, words, sentences);


    /*
    variables test
    printf("%s\n", text);
    printf("%i\n", letters);
    printf("%i\n", words);
    printf("%i\n", sentences);
    printf("%.i\n", grade);
    */

    //print the grade
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_lenght(string text)
{
    //check the string lenght
    int lenght = 0;
    int j = 0;
    while ((int) text[j] != 0)
    {
        lenght++;
        j++;
    }
    return lenght;
}

int count_letters(string text, int lenght)
{
    int sum = 0;
    //run through all the string
    for (int i = 0; i < lenght; i++)
    {
        //check if the character is a letter
        if (((int) text[i] > 64 && (int) text[i] < 91) || ((int) text[i] > 96 && (int) text[i] < 123))
        {
            //if it is a chracter, add to the sum
            sum ++;
        }
    }
    return sum;
}

int count_words(string text, int lenght)
{
    int sum = 0;
    //run through all the string
    for (int i = 1; i < lenght; i++)
    {
        //check if the character is a space
        if ((int) text[i] == 32)
        {
            //if it is a word, add to the sum
            sum++;
        }
    }
    return sum + 1;
}

int count_sentences(string text, int lenght)
{
    int sum = 0;
    //run through all the string
    for (int i = 1; i < lenght; i++)
    {
        //check if the chracter is ".", "?" or "!"
        if ((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63)
        {
            //if it is a sentence, add to the sum
            sum++;
        }
    }
    return sum;
}

int coleman_index(int letters, int words, int sentences)
{
    //variables
    float l = (float)letters / (float)words * 100;
    float s = (float)sentences / (float)words * 100;
    //formula
    int index = round((0.0588 * l) - (0.296 * s) - 15.8);

    return index;
}

//challenge: Make my own round function
int rounded(float num)
{
    return 1;
}