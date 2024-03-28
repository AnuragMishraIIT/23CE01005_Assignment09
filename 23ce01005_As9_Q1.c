/*  
    LAB ASSIGNMENT: 9
    Question number: 1

    Roll number: 23CE01005
    Name: Anurag Mishra
    Branch: Civil Engineering
    Date: 22/03/2024
*/

#include <stdio.h>

typedef struct company
{
    char name[30];
    char address[30];
    unsigned int phone;
    unsigned int noOfEmployee;
} comp;

int main()
{
    int n;
    printf("Enter the number of companies you want to enter:\n");
    scanf("%d",&n);
    comp companies[n];

    printf("\n-------------------------------------------------\nEnter the details of companies one-by-one:\n-------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {   
        printf("For company %d:\n",i+1);
        getchar();
        printf("Enter name:\n");
        gets(companies[i].name);
        printf("Enter address:\n");
        gets(companies[i].address);
        printf("Enter phone number:\n");
        scanf("%u",&companies[i].phone);
        printf("Enter number of employees:\n");
        scanf("%u",&companies[i].noOfEmployee);
    }

    printf("\n-------------------------------------------------\nData taken:\n-------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {   
        printf("\nFor company %d:\n",i+1);

        printf("Name: %s\nAddress: %s\nPhone: %u\nNumber of employees: %u\n",companies[i].name,companies[i].address,companies[i].phone,companies[i].noOfEmployee);
    }

    return 0;
}