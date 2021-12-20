#include<stdio.h>
#include<string.h>
int main(void) //12E345-67
{
    char tag[9];int s=0;char ch;
    scanf("%s",tag);
    ch = tag[2];
    int num1 = ((int)(tag[0])-48) + ((int)(tag[1])-48);
    int num2 = ((int)(tag[3])-48) + ((int)(tag[4])-48);
    int num3 = ((int)(tag[4])-48) + ((int)(tag[5])-48);
    int num4 = ((int)(tag[7])-48) + ((int)(tag[8])-48);
    if(((num1%2)!=0 || (num2%2)!=0 || (num3%2)!=0 || (num4%2)!=0 ) && (ch=='A'||ch=='E' || ch=='I'|| ch=='O'|| ch=='U' ))
    {
        printf("Arrest");
    }
    else 
    {
        printf("Not Arrest");
    }
}