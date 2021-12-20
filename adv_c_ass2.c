question-1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct vaccination
{
    char *name;
    char *flag;
    char *reg_no;
};
struct vaccination* users; 

int main(int argc, char const *argv[])
{
    int counter = 0;
    printf("Enter the number of people:\n");
    scanf("%d", &counter);
    users = (struct vaccination*)malloc(sizeof(struct vaccination)*counter);
    for (int i = 0; i < counter; i++)
    {
        users[i].name = (char*)malloc(sizeof(users[i].name)*10);
        users[i].flag = (char*)malloc(sizeof(users[i].flag)*3);
        users[i].reg_no = (char*)malloc(sizeof(users[i].reg_no)*5);
        printf("Enter the details of the person %d:\n",i+1);
        printf("Enter the name:\n");
        scanf("%s", users[i].name);
        printf("Have you got vaccinated?(Yes/No):\n");
        scanf("%s",users[i].flag);

        if(strcmp(users[i].flag,"Yes") == 0)
        {
            printf("Enter your register number:\n");
            scanf("%s",users[i].reg_no);
        }
        else
        {
            strcpy(users[i].reg_no, "None");
        }
    }
    printf("The details of users are:\n");
    for (int i = 0; i < counter; i++)
    {
        printf("|%s\t|%s\t|%s\t|\n",users[i].name,users[i].flag,users[i].reg_no);
    }
    return 0;
}

question-2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct UserName
{
    char *FirstName;
    char *MiddleName;
    char *LastName;
};
struct UserName* users; 

int main(int argc, char const *argv[])
{
    
    int counter = 0;
    char flag[3];
    printf("Enter the number of people:\n");
    scanf("%d", &counter);
    users = (struct UserName*)malloc(sizeof(struct UserName)*counter);
    for (int i = 0; i < counter; i++)
    {
        users[i].FirstName = (char*)malloc(sizeof(users[i].FirstName)*10);
        users[i].LastName = (char*)malloc(sizeof(users[i].LastName)*10);
        printf("Enter the details of the person %d:\n",i+1);
        printf("Enter your firstname:\n");
        scanf("%s", users[i].FirstName);
        printf("Enter your LastName:\n");
        scanf("%s",users[i].LastName);
        printf("Do you have a middlename? if yes enter Yes else enter No:\n");
        scanf("%s",flag);
        
        if(strcmp(flag,"Yes") == 0)
        {
            users[i].MiddleName = (char*)malloc(sizeof(users[i].MiddleName)*10);
            printf("Enter your Middle Name:\n");
            scanf("%s",users[i].MiddleName);
        }
        else{
            users[i].MiddleName = NULL;
        }
    }
    printf("The details of users are:\n");
    for (int i = 0; i < counter; i++)
    {
        printf("|%s\t|%s\t|%s\t|\n",users[i].FirstName,users[i].MiddleName,users[i].LastName);
    }
    return 0;
}

question-3

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct WeekDay
{
    char *WeekDay;
    float *arr;
};
struct WeekDay* value;

int main(int argc, char const *argv[])
{
    int counter;
    char WeekDay[10];
    printf("Enter the number of days:\n");
    scanf("%d",&counter);
    value = (struct WeekDay*)malloc(counter*sizeof(struct WeekDay));
    for (int i = 0; i < counter; i++)
    {
        printf("Enter the WeekDay:\n");
        value[i].WeekDay = (char*)malloc(counter*sizeof(char));
        scanf("%s",value[i].WeekDay);
        value[i].arr = (float*)malloc(strlen(WeekDay)*sizeof(float));
        printf("Enter the numbers:\n");
        for (int j = 0; j < strlen(WeekDay)-1; j++)
            scanf("%f",&value[i].arr[j]);
    }
    return 0;
}

question-4

#include <stdio.h>

int two(int number);
int three(int number);
int four(int number);
int five(int number);
int six(int number);
int seven(int number);
void odd(int (*ftpr_array[])(int number), int number);
void even(int (*ftpr_array[])(int number), int number);

int (*fptr_array_odd[3])(int number) = {three, five, seven};
int (*fptr_array_even[3])(int number) = {two, four, six};

int two(int number)
{
    int flag;
    if (number % 2 == 0)
        flag = 1;
    else
        flag = 0;
    return flag;
}
int three(int number)
{
    int flag;
    if (number % 3 == 0)
        flag = 1;
    else
        flag = 0;
    return flag;
}
int four(int number)
{
    int flag;
    if (number % 4 == 0)
        flag = 1;
    else
        flag = 0;
    return flag;
}
int five(int number)
{
    int flag;
    if (number % 5 == 0)
        flag = 1;
    else
        flag = 0;
    return flag;
}
int six(int number)
{
    int flag;
    if (number % 6 == 0)
        flag = 1;
    else
        flag = 0;
    return flag;
}

int seven(int number)
{
    int flag;
    if (number % 7 == 0)
        flag = 1;
    else
        flag = 0;
    return flag;
}

void odd(int (*ftpr_array[])(int number), int number)
{
    int arr[3];
    printf("Odd: The following number %d is divisible by:\n", number);
    for (int i = 0; i < 3; i++)
    {
        if (ftpr_array[i](number) == 1)
        {
            arr[i] = 2 * i + 3;
            printf("%d\n", arr[i]);
        }
    }
}

void even(int (*ftpr_array[])(int i), int number)
{
    int arr[3];
    printf("Even: The following number %d is divisible by:\n", number);
    for (int i = 0; i < 3; i++)
    {
        if (ftpr_array[i](number) == 1)
        {
            arr[i] = 2 * i + 2;
            printf("%d\n", arr[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int number;
    printf("Enter a number:\n");
    scanf("%d", &number);
    odd(fptr_array_odd, number);
    even(fptr_array_even, number);
    return 0;
}


question-5

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Info
{
    char name[15];
    char employee_id[5];
    char phno[10];
};
struct Info* employees;

int main(int argc, char const *argv[])
{
    int counter = 0;
    printf("Enter the number of employees:\n");
    scanf("%d",&counter);
    employees = (struct Info*)malloc(counter*sizeof(struct Info));
    for (int i = 0; i < counter ; i++)
    {
        printf("Enter name of the employee %d\n",i+1);
        scanf("%s",employees[i].name);
        printf("Enter employee_id of employee %d\n",i+1);
        scanf("%s",employees[i].employee_id);
        printf("Enter phone number of employee %d\n",i+1);
        scanf("%s",employees[i].phno);
    }
    for (int i = 0; i < counter; i++)
    {
        float size1 = (float)sizeof(employees[i]);
        float size2 = (float)strlen(employees[i].phno)*100;
        float percentage = size2/size1; 
        printf("Employee %d has size of phone number-->%d-->%f %\n",i+1,strlen(employees[i].phno),percentage);
    }
    return 0;
}

question-6

#include <stdio.h>
#include <stdlib.h>

union choice
{
    int percentage;
    char division[10];
};

struct Information
{
    char name[10];
    char qualification[10];
    int flag;
    union choice choose;
};

struct Information* users;



int main(int argc, char const *argv[])
{
    int counter;
    printf("Enter number of users");
    scanf("%d",&counter);
    users = (struct Information*)malloc(sizeof(struct Information)*counter);
    for (int i = 0; i < counter; i++)
    {
        int flag;
        printf("Enter name of user %d\n",i+1);
        scanf("%s",users[i].name);
        printf("Enter qualification of the user %d\n",i+1);
        scanf("%s",users[i].qualification);
        printf("Enter percentage or division to enter percentage enter 0 else enter 1 for division\n");
        scanf("%d",&flag);
        users[i].flag = flag;
        if(flag == 0)
        {
            printf("Enter the percentage of user %d\n",i+1);
            scanf("%d",&users[i].choose.percentage);
        }
        else
        {
            printf("Enter the division of user %d\n",i+1);
            scanf("%s",users[i].choose.division);
        }
    }
    for (int i = 0; i < counter; i++)
    {
        printf("USER%d:\n",i+1);
        printf("%s\n",users[i].name);
        printf("%s\n",users[i].qualification);
        if(users[i].flag == 1)
            printf("%s\n",users[i].choose.division);
        else
            printf("%d\n",users[i].choose.percentage);
        printf("\n");
    }
    
    return 0;
}

question-7

#include<stdio.h>

int multi(int x,int y);
int addit(int x,int y);
int modulo(int x,int y);
int divi(int x,int y);
void printval(int (*fptr_arr[4])(int x,int y),int choice);

int (*fptr_arr[4])(int x,int y) = {multi,addit,modulo,divi};


int multi(int x,int y)
{
    return x*y;
}
int addit(int x,int y)
{
    return x+y;
}
int modulo(int x,int y)
{
    return x%y;
}
int divi(int x,int y)
{
    return x/y;
}

void printval(int (*fptr_arr[4])(int x,int y),int choice)
{
    int x,y;
    printf("Enter two numbers:\n");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("%d",fptr_arr[choice](x,y));
}

int main(int argc, char const *argv[])
{
    int choice;
    printf("Enter 0 for multiplication\nEnter 1 for addition\nEnter 2 for modulo\nEnter 3 for division\n");
    scanf("%d",&choice);
    if (choice > 3)
        printf("Please Enter a choice b/w 0-3");
    else
        printval(fptr_arr, choice);
    return 0;
}

question-8

#include <stdio.h>
#include<string.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    char str[16];
    printf("Enter a binary number(max 16 bit)\n")
    scanf("%s",str);
    int sum=0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum = sum + pow(2,strlen(str)-i-1)*(str[i] - '0');
    }
    printf("The number in decimal is:\n")
    printf("%d",sum);
    return 0;
}