/* Eshaani Arvind
U88155472 
A program that checks if two conditions are held for a given array: 
1) a1 < a2 < … < an (if every element is smaller than its next)
2) For every i from 2 to n, ai isn’t divisible by ai-1 
*/

#include <stdio.h>
int main(void)
{
    int n, i = 0, j = 0;              //length of the array
    int condition = 0;                //flag variable?

    printf("Enter the length of the input array: ");
    scanf("%d", &n);

    int array [n];           //initializing the array
    printf("Enter the array elements: ");

    for (j ; j < n ; j++)     //reading data into array
        scanf("%d", &array[j]);

    for (i ; i < n ; i++)     //traversing array
    {
        if (array[i] < array[i+1])           //checking condition 1
        {
            condition=1;
        }
        else
        {
            break;
        }
    }
    if (condition == 1)        //checking condition 2 only if 1 is satisfied
        for (i = 2; i < n; i++)
        {
            if (array[i] % array[i-1] == 0)   //checking condition 2
            {
                condition = 0;
                break;
            }
            else 
            {
                condition = 1;
            }
        }
    printf("Output: ");
    if (condition == 1)       //checking value of flag variable
    {
        printf("yes");
    }
    else 
    {
        printf("no");
    }   
}