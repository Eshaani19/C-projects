
#include <stdio.h>
int main(void)
#define PACKAGE1 50
#define PACKAGE2 30
#define PACKAGE3 20
{
    int package;
    int hours;
    int people;
    int charge;

    printf("Please select from three packages: 1, 2, and 3\n");
    printf("Enter package selection: ");
    scanf("%d",&package);

    if (package==1 || package==2 || package==3)
        {
            printf("Enter hours: ");
            scanf("%d",&hours);
            if ((hours<=0) || (hours>4))
            {
                printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
            }
            else
            {
                printf("Enter number of people: ");
                scanf("%d",&people);
                if (package==1)
                {
                    if (people<50)
                        {
                            printf("Not meeting minimum requirement for number of guests.\n");
                        }
                    else if (people>200)
                        {
                            printf("Exceeded maximum number of guests.\n");
                        }
                    else
                    {
                        int cost_hours= 25*(hours-1);
                        int max_charge = 95;
                        int cost_people = 25*people;

                        if ((PACKAGE1 + cost_hours)>max_charge)
                            {
                                charge = max_charge + cost_people;
                                printf("Charge($): $%d\n", charge);
                            }
                        else
                        {
                            charge = PACKAGE1 + cost_hours + cost_people;
                            printf("Charge($): $%d\n", charge);
                        }   
                    }
                }
            else if (package==2)
                {
                    if (people<80)
                        printf("Not meeting minimum requirement for number of guests.\n");
                    else if (people>300)
                        printf("Exceeded maximum number of guests.\n");
                    else
                    {
                        int cost_hours= 15*(hours-1);
                        int max_charge = 55;
                        int cost_people = 22*people;
                        if ((PACKAGE1 + cost_hours)>max_charge)
                            {
                                charge = max_charge + cost_people;
                                printf("Charge($): $%d\n", charge);
                            }
                        else
                        {
                            charge = PACKAGE2 + cost_hours + cost_people;
                            printf("Charge($): $%d\n",charge);
                        }
                    }
                        
                }
            else if (package==3)
                {
                    if (people<20)
                        printf("Not meeting minimum requirement for number of guests.\n");
                    else if (people>150)
                        printf("Exceeded maximum number of guests.\n");
                    else
                    {
                        int cost_hours= 12*(hours-1);
                        int max_charge = 40;
                        int cost_people = 20*people;

                        if ((PACKAGE1 + cost_hours)>max_charge)
                            {
                                charge = max_charge + cost_people;
                                printf("Charge($): $%d\n", charge);
                            }
                        else
                        {
                            charge = PACKAGE1 + cost_hours + cost_people;
                            printf("Charge($): $%d\n", charge);
                        }   
                    }
                }
            } 
        }    
    else
        printf("Invalid selection. Select from 1 to 3.");
}