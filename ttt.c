#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char str[100];
        int count =0;
        scanf("%s",&str);
        int j=0;
        while(str[j]!='\0')
        {
           if(j == 0)
           {
               if(str[j]!=str[j+1]){
                count++;}
               j=j+2;
           }
           else if(str[j]!=str[j-1] && str[j]!=str[j-2])
           {
               count++;
               j++;
           }
           else
            j++;
        }
        printf("%d",count);
    }
	return 0;
}

