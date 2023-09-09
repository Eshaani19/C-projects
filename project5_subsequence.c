/* Eshaani Arvind
U88155472 */
// A program to check if one string is the subsequence of another string

#include <stdio.h>
#include <ctype.h> 
#define STR_LEN 1000

int main(void)
{
    char word1[STR_LEN+1];  
    char word2[STR_LEN+1];
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);
    int flag = 0;
    char *s=word1 , *t=word2;
    while (*t  && *s) //*t!='\0'
    {
        if(tolower(*s) == tolower(*t)) //case insensitive
        {
            s++;  //advances pointer on s only if previous letter is equal
        }
        t++; //otherwise only moves t ahead
    }            //!*s will be true if *s is '\0'.
    flag= !*s;  //if we have not reached the end of s, that means all letters of s was not equal to letters in 
    if (flag) printf("YES");  //if flag=1, *s='\0', yes
    else printf("NO");        //if flag=0, *s != '\0', no
}

    /*int count1=0;
    char *c1;
    for(c1=word1; c1<&word1[STR_LEN]; c1++){
        if (*c1=='\0'){
            break;}
        else{
            count1++;}}
    int count2=0;
    char *c2;
    for(c2=word2; c2<&word2[STR_LEN]; c2++){
        if (*c2=='\0'){
            break;}
        else{
            count2++;}}
    int flag = 0;
    char *p , *q;
    //printf("count1: %d,count2: %d",count1,count2);
    if (count1>count2){
        flag=0;}
    else{
        p=word1;
        q=word2;
        for( ; *p != '\0'; p++)
        {
            for( ; *q != '\0'; q++)
            {
                if(tolower(*p) == tolower(*q))
                {
                    flag = 1;
                    break;
                }
                else flag = 0;
            }
        }
    }*/
