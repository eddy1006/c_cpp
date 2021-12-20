#include<stdio.h>
 int main()
{
    int n;int m;
    scanf("%d",&n);
    int a[n];int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[n];
    if (m>=n)
        printf("m should be less than n ");
    else
    {
        for(i=m;i<n;i++)
        {
            b[i]=a[i-m];

        }
        for(j=0;j<m;j++)
        {
           if(m%2==0)
            b[j]=a[j+m+1];
           else
            b[j]=a[j+m+2];
        }
        for(k=0;k<n;k++)
        {
            printf("%d",b[k]);
        }
    }
    return 0;
}



