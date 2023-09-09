/* Eshaani Arvind
Task 2: A program that takes speeds of spacecrafts A and B
as input from the user and finds how many days it takes B to go faster 
than A */

#include <stdio.h>
int main(void)
{
    int n, speed_a = 0, speed_b = 0;       //initializing variables

    printf("Number of cases: ");
    scanf("%d", &n);

    for (int i = 1, days = 0; i < (n+1) ; i++)   //loop runs for number of cases starting with 1
    {
        printf("Speed of A: ");
        scanf("%d", &speed_a); 

        printf("Speed of B: ");
        scanf("%d", &speed_b);

        while (speed_a >= speed_b)          //loop runs until B is faster than A
        {
            speed_a = speed_a * 2;          //speed is doubled
            speed_b = speed_b * 3;          //speed is tripled
            days ++;
        }
        printf("Case #%d: %d day(s)\n",i,days);
        days = 0;                      //initializing back to zero for new count
    }
}
