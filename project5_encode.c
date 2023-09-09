/* Eshaani Arvind
U88155472 */
//Modiying an encoding program with command line arguments as input

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define total_input 1000        //input characters must be lesser than 1000

void encode(char *input, char *output); //function prototype

int main(int argc, char *argv[])
{
    char output[total_input+1];
    char *p=output;
    int i=1;
    /*if(argc<2)
        printf("Invalid input!");
        return 0;*/
    while(i<argc)
    {
        encode(argv[i],p);
        while(*p!='\0')
        {
            p++;
            i++;
        }
    }
    printf("%s",output);
}

void encode(char *input, char *output) //function to encode
{
    char new_ch,*p,*q;  //ch=characters entered, new_ch=replaced characters
    for (p=output, q=input; *q!='\0'; q++)           //reads until end of array
    {
        if (*q>'0' && *q<'9')    //checks if ch is between 0 and 9
        {
            new_ch=(*q-'0')+6;
            new_ch=(new_ch%10)+'0';
            *p++=new_ch;
        }
        else if (*q>'a' && *q<'z')  //checks if ch is btw a and z
        {
            new_ch=(*q-'a')+6;
            new_ch=(new_ch%26)+'a';
            *p++=new_ch;
        }
        else if (*q>'A' && *q<'Z')  //checks if ch is btw A and Z
        {
            new_ch=(*q-'A')+6;
            new_ch=(new_ch%26)+'A';
            *p++=new_ch;
        }
        else if (*q==' ')       //ignores whitespace
        {
            ;
        }
        else                    //prints underscore for other characters
        {
            new_ch='_'; 
            *p++=new_ch;
        }
    }
    *p='\0';
}
