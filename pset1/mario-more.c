#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hight;
    do
    {
        //Ask user for hight
        hight = get_int("How hight should the pyramids be? ");

    }
    while (hight < 1 || hight > 8 || hight == 0);

    int aux = hight;
    int d = aux;
    for (int i = 0; i < hight; i++)
    {
        //print espaces
        while (d > 1)
        {
            printf(" ");
            d--;
        }
        //print block
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        for (int c = 0; c < 2; c++)
        {
            printf(" ");
        }
        for (int e = 0; e <= i; e++)
        {
            printf("#");
        }
        //print new line
        printf("\n");
        aux--;
        d = aux;
    }
}