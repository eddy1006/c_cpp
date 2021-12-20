#include<stdio.h>
main()
{
   int a;
   scanf("%d",&a);
   int i;int s=0;int c=0;int t;
   for(i=10;s<a ;i=i*10)
   {
       t=(a%i)-c;
       c=a%i;
       if(i>10)
        t=t/(i/10);
       s=s+(t*t*t);
   }
       if (s==a && (a%i)==a)
        printf("adam");
       else
        printf("not adam");
}
