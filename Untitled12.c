#include<stdio.h>
#include<math.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int f;int pw;
    pw = pow(10,m);
     f = n%pw;
    int arr[m];int s,i;
    int temp=f;
    for(i=m-1;i>=0;i--)
    {
        arr[i]=temp%10;
        temp = temp/10;
    }
    i =0;
    while(i<m)
    {
        s=0;
        for(int j=0;j<m;j++)
        {
          s= s+arr[j];
        }
        if(s==f)
        break;
        else
        arr[i]=s;
        if(i!=2)
        i++;
        else
        i=0;
    }
    if(s==f)
    printf("Generated");
    else
    printf("Cannot be generated");
}
