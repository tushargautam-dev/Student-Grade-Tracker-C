#include <stdio.h>

char name[50];
int roll;
float marks[5], total = 0, average = 0;
char grade;
int dataEntered = 0;

// Function to Enter Details
void enterDetails()
{
    total = 0;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("\nEnter Marks of 5 Subjects:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    average = total / 5;
    dataEntered = 1;

    printf("\nStudent Details Saved Successfully!\n");
}

// Function to Show Report Card
void reportCard()
{
    if(dataEntered == 0)
    {
        printf("\nPlease Enter Student Details First!\n");
        return;
    }

    printf("\n========== REPORT CARD ==========\n");
    printf("Student Name : %s\n", name);
    printf("Roll Number  : %d\n", roll);

    for(int i = 0; i < 5; i++)
    {
        printf("Subject %d : %.2f\n", i + 1, marks[i]);
    }

    printf("Total Marks : %.2f\n", total);
}

// Function to Calculate Average
void calculateAverage()
{
    if(dataEntered == 0)
    {
        printf("\nPlease Enter Student Details First!\n");
        return;
    }

    printf("\nAverage Marks : %.2f\n", average);
}

// Function to Show Grade
void showGrade()
{
    if(dataEntered == 0)
    {
        printf("\nPlease Enter Student Details First!\n");
        return;
    }

    if(average >= 90)
        grade = 'A';
    else if(average >= 80)
        grade = 'B';
    else if(average >= 70)
        grade = 'C';
    else if(average >= 60)
        grade = 'D';
    else
        grade = 'F';

    printf("\nGrade : %c\n", grade);

    if(grade == 'F')
        printf("Result : Fail\n");
    else
        printf("Result : Pass\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf("      STUDENT GRADE TRACKER\n");
        printf("=====================================\n");
        printf("1. Enter Student Details\n");
        printf("2. View Report Card\n");
        printf("3. Calculate Average\n");
        printf("4. Show Grade\n");
        printf("5. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterDetails();
                break;

            case 2:
                reportCard();
                break;

            case 3:
                calculateAverage();
                break;

            case 4:
                showGrade();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}