/* Eshaani Arvind
U88155472 
A program with a recursive function that maps an integer into a single
digit to be used as checksum, where the checksum is a sum of the digits 
entered as input.
*/

#include <stdio.h>

int checksum(long n)                    //function checksum
{
    int a = n % 10;
    long b = n / 10;            
    int sum;                           //initializing variables
    int result;
    int check_sum;
    if (b > 10)                        //if no. of digits is>2
    {
        sum = a + (b % 10);                         //sum= one's digit+tens digit
        result = sum + checksum((b / 10));          //result= sum+recursion of the digits left
        check_sum = (result / 10) + (result % 10);  //check_sum= adding up the final digits
        if (check_sum > 10)                 //if final number not a single digit
        {
            return checksum(check_sum);     //making it a single digit 
        }
        else                                //otherwise returning same
        {
            return check_sum;
        }
    }
    else                               //if number of digits<=2
    {
        sum = a + b;
        return (sum / 10)+(sum % 10);  //ones digit+tens digit
    }
}

int main()
{
    int final_result;
    long N;                       //long type since number is between range 0 to 10^12

    printf("Input: ");
    scanf("%ld", &N);

    final_result = checksum(N);   //storing in variable
    printf("Checksum: %d",final_result);
}