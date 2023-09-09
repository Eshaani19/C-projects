/*Eshaani Arvind
U88155472*/

/* A program to compute the number of elements equal to the median in 
an input array of size N, with N being an odd number.*/

/* I have used multiple functions in this program, all of them use pointers
instead of subscripting, except the main function */

#include <stdio.h>

int compute_median(int *a,int n)
{
  int *median;
  median= a+(n/2);          //median = pointer to median element
  int *p, count=0;          //median = size of array/2
  for(p = a; p < a+n; p++)  //loop to check for duplicates
  {
    if(*p == *median)       //if element in array=median, count incremented
    {
      count++;
    }
  }
  return count;
}   

int find_largest(int *a, int n) //function to find largest element in array to be used in selection sort 
{
  int largest_index = 0;
  int *p;                           //using pointers
  for (int i = 1; i < n; i++)
  {
    p=a+i;
    if (*p > *(a+largest_index)) {  //checks if any element in array>largest
      largest_index = i;  }         //if so, they become largest
  }
  return largest_index;
}

void selection_sort(int *a, int n) //selection sort function to sort array
{
  int largest = 0,temp,*p;
  if (n == 1)
  {
    return;
  }
  largest = find_largest(a, n);     //function called to get index of largest element
  if (largest < n - 1) 
  {
    p = a+(n-1);
    temp = *p;                  //swapping values using pointers
    *p = *(a+largest);
    *(a+largest) = temp;
  }
  selection_sort(a, n - 1);     //recursive function until all elements are sorted
}

int main(void)
{
    int n,result;
    printf("Enter array size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for (int i=0; i<n; i++)
    {
      scanf("%d",&a[i]);  //for loop to put elements in array
    }
    selection_sort(a,n);  //selection sort function called to sort array
    result=compute_median(a,n); //median function called with new array
    printf("Output: %d",result);
}