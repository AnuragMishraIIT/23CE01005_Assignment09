/*  
    LAB ASSIGNMENT: 09
    Question number: 3

    Roll number: 23CE01005
    Name: Anurag Mishra
    Branch: Civil Engineering
    Date: 22/03/2024
*/

#include <stdio.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} date;

int outFunc(date Date1,date Date2)
{
    int output=0;
    if(Date1.year!=Date2.year)
    {
        output=((Date1.year>Date2.year)?1:(-1));
        
    }
    else if(Date1.month!=Date2.month)
    {
        output=((Date1.month>Date2.month)?1:(-1));

    }
    else if(Date1.day!=Date2.day)
    {
        output=((Date1.day>Date2.day)?1:(-1));

    }
    return output;
}

int main()
{
    date Date1,Date2;
    printf("For First Date, Enter day, month and year (in DD MM YYYY format)\n");
    scanf("%d %d %d",&Date1.day,&Date1.month,&Date1.year);
    printf("For Second Date, Enter day, month and year (in DD MM YYYY format)\n");
    scanf("%d %d %d",&Date2.day,&Date2.month,&Date2.year);

    printf("The returned value is %d\n",outFunc(Date1,Date2));
    return 0;
}