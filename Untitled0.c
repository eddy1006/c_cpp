#include<math.h>
#include<stdio.h>
void main()
{
    int n;int m;
    scanf("%d",&n);
    int a[3];
    a[0]=n;a[1]=(n-1);a[2]=(n-2);
    int i;
    for(i=0;i<3;i++)
    {
        if(a[i]%3!=0)
        continue;
        int c=0;
        int p = 1;
        while(p<a[i])
        {
            c++;
            p=pow(3,c);
        }
        c=c-1;
        int k = pow(3,c);
        int sum=0;
        sum = sum +k;
        printf("%d \t",k);
        while(k>=3)
        {
            if(c>1)
            c--;
            k = pow(3,c);
            sum = sum +k;
            if (sum<a[i])
            {
                printf("%d \t",k);
            }
            if(sum==a[i])
            {
                printf("%d \t \n",k);
                break;
            }
            if(sum>a[i])
            {
                sum = sum -k;
            }
        }
       m = a[i];
       break;
    }
    printf("%d",m);
}
