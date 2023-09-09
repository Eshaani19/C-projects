//Eshaani Arvind
//U88155472
/* Program to create a vocabulary of unique words for a given text 
file and assign a different number from 1 to N to each unique word 
that is sorted alphabetically. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 1000          //max number of words
#define MAX_LETTERS 100         //max number of letters

void selection_sort(char a[][MAX_LETTERS+1],int n); //function prototypes
int find_largest(char a[][MAX_LETTERS+1], int n);
 
int main(int argc, char * argv[])
{
    char words[MAX_WORDS+1][MAX_LETTERS+1];      //to store all words from input file
    char new_words[MAX_WORDS+1][MAX_LETTERS+1];  //new array without duplicates
    char read_words[MAX_WORDS+1];                //array to read from output file created
    int n1=0, n2=0;              //n1= len of words array, n2=len of new_words array
    FILE *fp1, *fp2;             //declaring pointers to files
    fp1 = fopen(argv[1], "r");   //filename from command line argument
    int i=0;
    while (!feof(fp1) && !ferror(fp1))
    {
        fscanf(fp1,"%s",words[i]);   //reading content of input file into words array
        i++;           
        n1+=1;      //keeping count of elements
    }
    int j,l;       
    for(i=0; i<n1; i++)  //loop to convert every character in array to uppercase
    {
        l=strlen(words[i]);
        for(int j=0; j<l; j++)
        {
            words[i][j]=toupper(words[i][j]);
        }
    }
    selection_sort(words,n1);  //calling function to sort array alphabetically
    int k=0;
    for (i=0; i<n1; i++)       //loop to check for duplicates 
    {
        int flag=0;
        for (int a = 0; a < n2; a++) 
        {
            if (strcmp(words[i],new_words[a])==0)
            {
                flag=1;
            }
        }
        if (!flag)              //writes only once into new words array  
        {
            strcpy(new_words[k],words[i]);
            k++;
            n2+=1;
        }
    }
    i=0;
    fp2 = fopen(argv[2], "w");  //opening file in write mode
    for(i=0; i<n2; i++ )        //loop to write into output file from new words array
    {
        if(new_words[i][0] !=' ' && new_words[i][0] !='\0' && new_words[i][0] != '\n') //no extra characters stored
        {
            fprintf(fp2,"%d %s\n",i,new_words[i]);
        }
    }
    fclose(fp1);    //closing both files
    fclose(fp2);
    fp2=fopen(argv[2],"r");     //opening output file in read mode
    while (!feof(fp2) && !ferror(fp2))
    {
        while ( fgets (read_words, MAX_WORDS, fp2 ) != NULL )
        {
            printf ("%s", read_words);
        }
    }
    fclose(fp2);
    return 0;
}

void selection_sort(char a[][MAX_LETTERS+1], int n) //selection sort for array of strings
{
    int largest = 0; 
    char temp[MAX_LETTERS+1];
    if (n == 1)
        return;
    largest = find_largest(a, n);
    if (largest < n - 1) 
    {
        strcpy(temp,a[n-1]);        //temp = a[n-1];
        strcpy(a[n-1],a[largest]);  //a[n-1] = a[largest];
        strcpy(a[largest],temp);    //a[largest] = temp;
    }
    selection_sort(a, n - 1);
}

int find_largest(char a[][MAX_LETTERS+1], int n) //finding index of largest string in array
{
    int largest_index = 0;
    int i=1;
    for (i = 1; i < n; i++)
        if(strcmp(a[i],a[largest_index])>0) //if (a[i] > a[largest_index])
            largest_index = i;
    return largest_index;
}