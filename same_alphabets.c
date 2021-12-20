#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check(char* s,int i)
{ 
    int count = 0;
    for(int j=i-1;j>=0;j--)
    {
        if(s[j]==s[i])
        {
            count++;
            break;
        }
    }
    if(count==0)
    return 1;
    else
    return 0;
}

int main(void)
{
    char s1[10]; 
    char s2[10];
    scanf("%s",s1);
    scanf("%s",s2);
    printf("%s %s",s1,s2);
    int len1 = sizeof(s1)/sizeof(s1[0]);
    int len2 = sizeof(s2)/sizeof(s2[0]);
    char* str1 = (char*)malloc(len1*sizeof(char));
    char* str2 = (char*)malloc(len2*sizeof(char));
    int j=0;
    for(int i=0;i<len1;i++)
    {
        if(j==len1)
        break;
        while(j<len1)
        {
           if(check(s1,j))
           {
               str1[i]=s1[j];
               break;
           }
           else{
               j++;
               continue;
           }
        }
    }
    j=0;
    for(int i=0;i<len2;i++)
    {
        if(j==len2)
        break;
        while(j<len2)
        {
           if(check(s2,j))
           {
               str2[i]=s2[j];
               break;
           }
           else{
               j++;
               continue;
           }
        }
    }
    printf("%s %s",*s1,*s2);
    int counter=0;
    int i =0;
    while(str1[i]!='\0')
    {
        j=0;
        while(str2[j]!='\0')
        {
            if(str1[i]==str2[j])
            {
            counter++;
            break;
            }
            j++;
        }
        i++;
    }
    printf("%d",counter);
    return 0;
}