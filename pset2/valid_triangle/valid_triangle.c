#include <stdio.h>
#include <stdbool.h>

bool isNegative(float arr[]);
bool valid_triangle(float arr[]);

int main(void)
{
    printf("Is this a valid triangle??\n");
    float number[3];
    bool is_Negative = true;
    bool is_Valid = true; 

    for(int i = 0; i < 3; i++)
    {   
        printf("Insert the lenght of the side number %i of the triangle: ", i+1);
        scanf("%f", &number[i]);
    }

    is_Negative = isNegative(number);
    if(is_Negative == false)
    {
        printf("Triangles dont have negative sides\n");
    }else{
        is_Valid = valid_triangle(number);
        if(is_Valid)
        {
            printf("This is a valid triangle!\n");
        }else
        {
            printf("This is a invalid triangle!\n");
        }
    }
}

bool valid_triangle(float arr[])
{
    if((arr[0] + arr[1] <= arr[2]) || (arr[1] + arr[1] <= arr[0]) || (arr[0] + arr[2] <= arr[1]))
    {
        return false;
    }else
    {
        return true;
    }
}

bool isNegative(float arr[])
{
    for(int i = 0; i < 3; i++)
    {
        if(arr[i] <= 0)
        {
            return false;
        }
    }
    return true;
}