
#include <stdio.h>
#include<string.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    char str[16];
    printf("Enter a binary number(max 16 bit)\n");
    scanf("%s",str);
    int sum=0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum = sum + pow(2,strlen(str)-i-1)*(str[i] - '0');
    }
    printf("The number in decimal is:\n");
    printf("%d",sum);
    return 0;
}