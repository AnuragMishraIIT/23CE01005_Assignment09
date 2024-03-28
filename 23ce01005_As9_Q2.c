/*
    LAB ASSIGNMENT: 9
    Question number: 02

    Roll number: 23CE01005
    Name: Anurag Mishra
    Branch: Civil Engineering
    Date: 22/03/2024
*/

#include <stdio.h>

typedef struct students
{
    char roll[15];
    char name[20];
    char address[20];
    unsigned short int age;
    double avgmarks;
} stud;

void inputStud(stud array[], unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nFor student %u\nEnter Roll number, Name, Address, Age and Average marks\n", i + 1);
        getchar();
        gets(array[i].roll);
        gets(array[i].name);
        gets(array[i].address);
        scanf("%hu %lf",&array[i].age,&array[i].avgmarks);
    }
    return;
}

void outputStud(stud array[], unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nFor student %u\nRoll number: %s\nName: %s\nAddress: %s\nAge: %hu\nAverage marks: %lf\n", i + 1,array[i].roll, array[i].name, array[i].address, array[i].age, array[i].avgmarks);
    }
    return;
}

int main()
{
    unsigned int n;
    printf("Enter the number of students:\n");
    scanf("%u", &n);
    stud stud_array[n];

    inputStud(stud_array, n);
    outputStud(stud_array,n);
    return 0;
}