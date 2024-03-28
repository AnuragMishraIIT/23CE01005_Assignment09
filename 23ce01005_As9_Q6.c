/*  
    LAB ASSIGNMENT: 09
    Question number: 06

    Roll number: 23CE01005
    Name: Anurag Mishra
    Branch: Civil Engineering
    Date: 22/03/2024
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int size=0;

typedef struct Students
{
    char name[30];
    char roll[30];
    float percent;
} stud;


void insert(stud* DB)
{
    printf("Enter Roll Number, Name, Percentage of the person to add to database:\n");
    printf("Input: ");
    gets(DB[size].roll);
    gets(DB[size].name);
    scanf("%f",&DB[size].percent);
    size++;

    for(int i=0;i<size-1;i++)
    {   bool flag=0;
        for(int j=0;j<size-i-1;j++)
        {
            if(strcmp(DB[j].roll,DB[j+1].roll)>0)
            {
                stud temp=DB[j];
                DB[j]=DB[j+1];
                DB[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    return;
}

void sortName(stud* DB)
{
    int i;
    stud temp; //Temporary structure for swapping
    for(int i=0;i<size-1;i++)
    {   
        for(int j=0;j<size-i-1;j++)
        {
            if(strcmp(DB[j].name,DB[j+1].name)>0)
            {
                temp=DB[j];
                DB[j]=DB[j+1];
                DB[j+1]=temp;
            }
        }
    }
    printf("\nThe Database has been sorted by Name.\n");
}

void findOne(stud* DB)
{
    int i,j,found=0;
    char str[30];
    printf("Enter starting letters of name:\n");
    printf("Input: ");
    gets(str);

    printf("\n-------------------------------------------------------------------------\nThe records stored in the Database are:\n-------------------------------------------------------------------------\n");
    printf("Roll number\tName\tPercentage");
    printf("\n-------------------------------------------------------------------------\n");

    int sublength=strlen(str),count;
    for(i=0;i<size;i++)//For each entry
    {   
        j=0,count=0;
        while(str[j]!=0)
        {
            if(str[j]==DB[i].name[j])
            {
                count++;
            }
            j++;
        }
        if(count==sublength)
        {
            found=1;
            printf("%s\t%s\t%f\n",DB[i].roll,DB[i].name,DB[i].percent);
        }
    }
    if(found==0)
    {
        printf("No record(s) found:\n");
    }
    printf("\n-------------------------------------------------------------------------\n");
    return;
}

void specs(stud* DB,float array[])
{
    int i;
    array[0]=size;
    array[1]=DB[0].percent;
    array[2]=DB[0].percent;
    array[3]=0;
    array[4]=0;
    for(i=0;i<size;i++)
    {
        if(DB[i].percent>array[1])
        {
            array[1]=DB[i].percent;
            
        }
        if(DB[i].percent<array[2])
        {
            array[2]=DB[i].percent;
        }
        array[3]+=DB[i].percent;
    }

    array[3]=array[3]/size;
    for(int i=0;i<size;i++)
    {
        array[4]+=pow(DB[i].percent-array[3],2.0);
    }
    array[4]=sqrt(array[4]/size);
    printf("\n-------------------------------------------------------------------------\n");
    printf("\nSpecifications of the Database:\n");
    printf("Number of records: %d\nHighest percentage: %.5f\nLowest percentage: %.5f\nMean: %.5f\nStandard Deviation: %.5f\n", (int)array[0],array[1],array[2],array[3],array[4]);
    printf("\n-------------------------------------------------------------------------\n");
    return;
}

void delete(stud* DB)
{
    char rollnum[30];
    printf("Enter the roll number to delete:\n");
    printf("Input: ");
    gets(rollnum);
    for(int i=0;i<size;i++)
    {
        if(strcmp(DB[i].roll,rollnum)==0)
        { 
            for(int j=i;j<size-1;j++)
            {
                DB[j]=DB[j+1];
            }
            size--;
            i--;
        }
    }
}

void print(stud* DB)
{
    printf("\n-------------------------------------------------------------------------\nThe records stored in the Database are:\n-------------------------------------------------------------------------\n");
    printf("Roll number\tName\t\tPercentage");
    printf("\n-------------------------------------------------------------------------\n");

    for(int i=0;i<size;i++)
    {
        printf("%s\t%s\t%.5f\n",DB[i].roll,DB[i].name,DB[i].percent);
    }
    printf("\n-------------------------------------------------------------------------\n");
    printf("\n\n");
    return;
}

int main()
{
    stud DB[100];
    int exit=0;
    int choice=0;
    
    float array[5];//For returning an array in specs
    
    label:
    printf("\n-------------------------------------------------------------------------\n");
    printf("Enter 1 for Inserting\nEnter 2 for Sorting by name\nEnter 3 for Finding name by initial set of characters\nEnter 4 for Specifications\nEnter 5 for Delete\nEnter 6 for Showing entire Database\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Input: ");
    scanf("%d",&choice);
    getchar();

    switch(choice)
    {
        case 1:
        insert(DB);
        break;

        case 2:
        sortName(DB);
        break;

        case 3:
        findOne(DB);
        break;

        case 4:
        specs(DB,array);
        break;

        case 5:
        delete(DB);
        break;

        case 6:
        print(DB);
        break;
    }
    printf("Press 1 to exit and any other key to continue:\n");
    printf("Input: ");
    scanf("%d",&exit);
    getchar();
    if(exit!=1)
    {
        goto label;
    }
    
    return 0;
}