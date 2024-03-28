/*  
    LAB ASSIGNMENT: 09
    Question number: 4

    Roll number: 23CE01005
    Name: Anurag Mishra
    Branch: Civil Engineering
    Date: 22/03/2024
*/

#include <stdio.h>

typedef struct Address
{
    char street[20];
    char city[20];
    int pincode;
} add;

typedef struct Person
{
    char name[25];
    add address;
} per;

int main()
{
    per person;
    printf("Enter Name, Street, City and Pincode:\n");
    gets(person.name);
    gets(person.address.street);
    gets(person.address.city);
    scanf("%d",&person.address.pincode);

    printf("\n------------------------------------------------\nDetails taken\n------------------------------------------------\n");
    
    printf("Name: %s\nAddress:\n\tStreet: %s\n\tCity: %s\n\tPincode: %d\n",person.name,person.address.street,person.address.city,person.address.pincode);
    return 0;
}