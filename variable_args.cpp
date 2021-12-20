// program to illustrate variable no of arguments to be passed in a function 
#include<stdio.h>
#include<stdarg.h>

int sum(int n,...)  // n stores the no of arguments passed , it is compulsory in the syntax and it is followed by three dots
{
    int s=0;
    va_list valis;     // creating a variable list 
    va_start(valis,n);  // starting the list
    for(int i=1;i<=n;i++)
    {
        s = s + va_arg(valis,int);  // accesssing every argument using va_arg
    }
    return s;
}

int main(void)
{
    printf("%d ",sum(3,10,15,20));
    printf("%d",sum(5,10,15,20,5,25));   // first argument is the no of arguments to be passed after this 
    return 0;
}