#include<stdio.h>
int main()
{
    int diff;
    scanf("%d",&diff);
    int x ,y;
    int t = diff/9;
    x = t; y = 0;
    while(x - y == t)
    {
        if(((x*10+y)-(y*10+x))==diff)
        break;
        x++;
        y++;
    }
    if(y == 0)
    {
        printf("0%d %d",(y*10+x),(x*10+y));
    }
    else
    {
     printf("%d %d",(y*10+x),(x*10+y));
    }
}
