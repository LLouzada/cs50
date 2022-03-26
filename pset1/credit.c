#include <cs50.h>
#include <stdio.h>

//functions declarations
int cardLenght(int arr[]);
bool cardValidator(int arr[], int cLenght);
string creditor(int arr[], int cLenght);

int main(void)
{
    int arr[17];
    //fill the array whith -1
    //(I'll use to know when stop processing the card number, since -1 isnt a valid number)
    for (int i = 0; i < 17; i++)
    {
        arr[i] = -1;
    }

    //variables for checking the lenght
    long test_div9 = 1000000000;
    long test_div17 = 10000000000000000;
    long number;
    int test9;
    int test17;

    //imput
    do
    {
        number = get_long("Insert your credit card number: ");

        //test if the number is less than 10 digits
        test9 = number / test_div9;
        //test if the number is over 16 digits
        test17 = number / test_div17;
    }
    while (test9 == 0 || test17 != 0);

    //will be used to separate each number of the card
    int divisor = 10;


    for (int j = 0; j < 16; j++)
    {
        //put each number from the card in slot of the array
        //starts from the last digit (ends in the number befor the first -1)
        arr[j] = number % divisor;
        number /= divisor;
        if (number == 0)
        {
            break;
        }
    }

    //receive the card lenght and if the luhn´s algorithm is valid
    int cLenght = cardLenght(arr);
    bool valid = cardValidator(arr, cLenght);

    if (valid)
    {
        //check the creditor
        string creditorf = creditor(arr, cLenght);
        printf("%s", creditorf);
    }
    else
    {
        printf("INVALID\n");
    }

}

//chech the car number lenght
int cardLenght(int arr[])
{
    int i = 0;
    while (arr[i] != -1)
    {
        i++;
    }
    return i;
}

//check if the card is valid using Luhn´s Algorithm
bool cardValidator(int arr[], int cLenght)
{
    int sum = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;

    //first to the multipling by 2 part
    for (int i = 1; i < cLenght; i += 2)
    {
        aux = arr[i] * 2;

        //checks if the number is 2 digits or 1
        //if its 1
        if (aux / 10 == 0)
        {
            sum += aux;
        }
        //if is 2
        else
        {
            aux2 = aux / 10;
            aux3 = aux % 10;
            sum = sum + aux2 + aux3;
        }
    }
    int sum2 = 0;
    int total = 0;
    //second part of the algorithm
    for (int i = 0; i < cLenght; i += 2)
    {
        sum2 += arr[i];
    }

    total = sum + sum2;

    if (total % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}

//check the creditor: ONLY WORKS for AMEX, VISA and MASTERCARD
string creditor(int arr[], int cLenght)
{
    //VISA
    if (cLenght == 13)
    {
        if (arr[12] == 4)
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    //VISA & MASTERCARD
    else if (cLenght == 16)
    {
        if (arr[15] == 4)
        {
            return "VISA\n";
        }
        else if (arr[15] == 5)
        {
            if (arr[14] == 1 || arr[14] == 2 || arr[14] == 3 || arr[14] == 4 || arr[14] == 5)
            {
                return "MASTERCARD\n";
            }
            else
            {
                return "INVALID\n";
            }
        }
        else
        {
            return "INVALID\n";
        }
    }
    //AMEX
    else if (cLenght == 15)
    {
        if (arr[14] == 3)
        {
            if (arr[13] == 4 || arr[13] == 7)
            {
                return "AMEX\n";
            }
            else
            {
                return "INVALID\n";
            }
        }
        else
        {
            return "INVALID\n";
        }
    }
    else
    {
        return "INVALID\n";
    }
}

