/*  
    LAB ASSIGNMENT: 09
    Question number: 05

    Roll number: 23CE01005
    Name: Anurag Mishra
    Branch: Civil Engineering
    Date: 22/03/2024
*/

#include <stdio.h>

struct CourseRecord
{
    char firstName[20];
    char lastName[20];
    char roll[20];
    char department[15];
    char courseCode[15];
    float marks[3];
};

float avgMarks(float *ptr)
{
    float avg=0;
    for(int i=0;i<3;i++)
    {
        avg+=*(ptr+i);
    }
    avg=avg/3.0;
    return avg;
}

char* pass(float *ptr)
{
    for(int i=0;i<3;i++)
    {
        if(*(ptr+i)<35.00)
        {
            return "FAILED";
        }
    }
    return "PASSED";
}

int main()
{
    struct CourseRecord record;
    printf("Enter first name, last name, roll number, department and course code:\n");
    gets(record.firstName);
    gets(record.lastName);
    gets(record.roll);
    gets(record.department);
    gets(record.courseCode);

    printf("\nEnter marks in the subjects one by one:\n");
    for(int i=0;i<3;i++)
    {
        printf("Marks in subject %d: ",i+1);
        scanf("%f",&record.marks[i]);
    }
    
    printf("Average marks of the student: %f\n",avgMarks(record.marks));
    printf("The student has %s!",pass(record.marks));
    return 0;
}