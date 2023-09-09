//Eshaani Arvind
//U88155472
//Program to sort coffee from given csv file by total score in descending order

#include <stdio.h>
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

void selection_sort_coffee (struct coffee list[], int n);  //function prototypes
int find_largest (struct coffee list[], int n);

int main()
{
  char input [MAX_CHAR];       //input file 
  char output [MAX_CHAR];      //output file
  struct coffee a[MAX_NUM];    //array of structures named a
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
  selection_sort_coffee (a,n);   //sorting array of structures according to score
  fp2 = fopen(output, "w");     //opening output file in write mode
  for (int j = n-1; j >= 0; j-- )    //loop to write structures to output file in decending order
  {
    fprintf(fp2 ,"%s, %s, %s, %s, %.2lf\n", a[j].country, a[j].region, a[j].owner, a[j].variety, a[j].total_score);
  }               // .2lf to print only 2 digits after decimal point
  fclose (fp1);    //closing both files
  fclose (fp2);
  return 0;
}

int find_largest (struct coffee list[], int n) //function to find largest element in array to be used in selection sort 
{
  int largest_index = 0;                           
  for (int i = 1; i < n; i++)
  {
    if (list[i].total_score > list[largest_index].total_score) //checks if any score in array >largest
    {  
      largest_index = i;  //if so, they become largest
    }           
  }
  return largest_index;
}
void selection_sort_coffee (struct coffee list[], int n) //selection sort function to sort array
{
  int largest = 0;
  struct coffee temp;
  if (n == 1)
  {
    return;
  }
  largest = find_largest(list, n);     //function called to get index of largest element
  if (largest < n - 1) 
  {
    temp = list[n-1];             //swapping values using temp variable
    list[n-1] = list[largest];
    list[largest] = temp;   
  }
  selection_sort_coffee (list, n - 1);     //recursive function until all elements are sorted
}