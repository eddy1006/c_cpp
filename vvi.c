#include<stdio.h>
#include<math.h>
int sum(int a[],int m)
{   int s =0;
   for(int i=0;i<m;i++)
   {
       s = s+a[i];
   }
   return s;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int f;int pw;
    pw = pow(10,m);
     f = n%pw;
    int arr[m];int s,i,j;
    int temp=f;
    for(i=m-1;i>=0;i--)
    {
        arr[i]=temp%10;
        temp = temp/10;
    }
    i =0;
    while(i<m)
    {
        s=sum(arr,m);
        if(s==f)
        break;
        else
        {
          arr[i]=s;
          if(i==(m-1))
          i=0;
          else
          i++;
        }
    }
    if(s==f)
    printf("Generated");
    else
    printf("Cannot be generated");
}
