/* Eshaani Arvind
Task 1: A program that takes input from the user and encodes a string 
according to an algorithm */

#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch,new_ch;   //ch=characters entered, new_ch=replaced characters

    printf("Enter input: ");
    ch=getchar();               //get char instead of scanf

    while (ch!='\n')            //reads until end of line
    {
        if (ch>'0' && ch<'9')    //checks if ch is between 0 and 9
        {
            new_ch=(ch-'0')+6;
            new_ch=(new_ch%10)+'0';
            printf("%c",new_ch);
        }
        else if (ch>'a' && ch<'z')  //checks if ch is btw a and z
        {
            new_ch=(ch-'a')+6;
            new_ch=(new_ch%26)+'a';
            printf("%c",new_ch);
        }
        else if (ch>'A' && ch<'Z')  //checks if ch is btw A and Z
        {
            new_ch=(ch-'A')+6;
            new_ch=(new_ch%26)+'A';
            printf("%c",new_ch);
        }
        else if (ch==' ')       //ignores whitespace
        ;
        else                    //prints underscore for other characters
        {
            printf("_");
        }
        ch=getchar();
    }
}