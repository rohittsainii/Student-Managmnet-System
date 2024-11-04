#include<stdio.h>
#define STUDENT_MAX 100
#define STUDENT_MARKS 3
#define STUDENT_NAME 50

typedef struct
{
    char name[50];
    int roll_no;
    int marks[3];
    float avg;
}Student;
    Student student[STUDENT_MAX];

    void add_student(void);
    void display_student(void);
    void search_student(void);
    void avarage_student(void);

int student_count =0;

int main()
{
    int n;
    printf("\n\n------Enter Database for the Student-------");
    printf("\n------1. Add Student");
    printf("\n------2. Display Details of Students");
    printf("\n------3. Search a Student");
    printf("\n------4. Calculate Avarage");
    printf("\n\nEnter a Choice:");
    scanf("%d",&n);

    switch(n)
    {
        case 1:
            add_student();
            break;
        case 2:
            display_student();
            break;
        case 3:
            search_student();
            break;
        case 4:
            avarage_student();
            break;
        default:
            printf("Invaild Input!!");
            break;
    }
    return 0;
}

void add_student(void)
{
    int i;
    float avg;
    if (student_count == STUDENT_MAX)
    {
        printf("DataBase is Full!\n");
        return;
    }
    
    printf("\nEnter a Student Name: ");
    scanf("%s", student[student_count].name);

    printf("\nEnter the Roll No: ");
    scanf("%d",&student[student_count].roll_no);

    for(i=0;i<STUDENT_MARKS;i++)
    {   
        printf("\nEnter Marks for %dst Subject: ",i+1);
        scanf("%d",&student[student_count].marks[i]);
    }
    student[student_count].avg = (student[student_count].marks[0]+student[student_count].marks[1]+student[student_count].marks[2])/3; 
    student_count ++;
    printf("\n-----Succesful Added!!!------");
    main();
}

void display_student(void)
{
    int i,j;
    if (student_count == 0)
    {
        printf("\nNo Student in the Database");
    }
    for (i = 0; i < student_count; i++)
    {
        printf("\nStudents Name is: %s",student[i].name);
        for (j = 0; j < STUDENT_MARKS; j++)
        {
            printf("\nStudent Marks of %d Subject: %d",j+1,student[i].marks[j]);
        }
        printf("\nThe Avarage of the Student is: %.2f\n\n",student[i].avg);
    }
    main();
}

void search_student(void)
{
    int roll,i,j;
    printf("Enter the Roll No.: ");
    scanf("%d",&roll);
    for (i = 0; i <= student_count; i++)
    {
        if (student[i].roll_no == roll)
        {
            printf("\nStudents Name is: %s",student[i].name);
            for (j = 0; j < STUDENT_MARKS; j++)
            {
                printf("\nStudent Marks of %d Subject: %d",j+1,student[i].marks[j]);
            }
            printf("\nThe Avarage of the Student is: %.2f",student[i].avg);
        }
        else
        {
            printf("\nStudent's Roll No. Not Found!");
            main();
        }
            
    }
    main();
    
    
}

void avarage_student(void)
{
    int roll,i;
    printf("Enter the Roll No.: ");
    scanf("%d",&roll);
    for (i = 0; i < student_count; i++)
    {
        printf("\nStudent's Avarage Marks are: %.2f",student[i].avg);
    }
    main();
    
    printf("\nStudent Not Found");
}