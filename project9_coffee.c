//Eshaani Arvind
//U88155472
//Program to modify project 7 to sort coffee from given csv file by total score in descending order using quick sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100          //max number of coffees
#define MAX_CHAR 150         //max number of characters

struct coffee                //defining structure coffee
{
    char country [MAX_CHAR]; //arrays with max character capacity for strings
    char region [MAX_CHAR];
    char owner [MAX_CHAR];
    char variety [MAX_CHAR];;
    double total_score;
};

int score_compare (const void* p, const void* q);

int main()
{
  char input [MAX_CHAR];       //input file 
  char output [MAX_CHAR];      //output file
  struct coffee a [MAX_NUM];    //array of structures named a
  FILE * fp1;     //declaring file pointers
  FILE * fp2;

  printf ("Enter the file name: ");
  scanf ("%s", input);
  strcpy (output, "sorted_");   //creating required file name of output file
  strcat (output, input);
  printf ("Output file name: ");
  printf ("%s", output);
  fp1 = fopen (input, "r");    //opening input file in read mode

  int n = 0;                    //variable to keep count of structures added
  while (!feof (fp1) && !ferror (fp1))   //loop to add structures into array
  {
    fscanf (fp1 ,"%[^,],%[^,],%[^,],%[^,],%lf\n", a[n].country,a[n].region, a[n].owner, a[n].variety, &a[n].total_score); //reading into struct varable
    n++;      //updating count variable
  }

  qsort(a, n, sizeof(struct coffee), score_compare); //sorting using q sort according to scores
  
  fp2 = fopen(output, "w");     //opening output file in write mode
  
  for (int j = n-1; j >= 0; j-- )    //loop to write structures to output file in decending order
  {
    fprintf(fp2 ,"%s, %s, %s, %s, %.2lf\n", a[j].country, a[j].region, a[j].owner, a[j].variety, a[j].total_score);
  }               // .2lf to print only 2 digits after decimal point
  
  fclose (fp1);    //closing both files
  fclose (fp2);
  return 0;
}

int score_compare(const void* p, const void* q)
{
    const struct coffee *p1 = p;    //typecasting to structure format
    const struct coffee *q1 = q;
    if (p1->total_score < q1->total_score)  //comparing scores of each structure
        return -1;                          //returns -1, 0 or 1
    else if (p1->total_score == q1->total_score)
        return 0;
    else
        return 1;
    //return p1->totalscore - q1->total_score;
}
