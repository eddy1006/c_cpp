#include<stdio.h>
void main()
{
    int k;
    printf("Enter the no of NGO's ");
    scanf("%d",&k);
    int m;
    printf("Enter the no of applicants");
    scanf("%d",&m);
    int a[m];
    int b[k];int i; int p; int t;int w;
    int c; int d; int ctr;int sum=0;int e;int z;
    printf("Enter the NOA values filled by each applicant");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(w=0;w<k;w++)
    {
        for (p=0;p<m;p++)
        {
            for(t=0;t<=w;t++)
            {
                if(b[t]==a[p])
                 break;
            }
            if(b[t]==a[p])
             continue;
            else
            {
                b[w]=a[p];
                break;
            }
        }
    }
    for(z=0;z<k;z++)
    {
        if(b[z]!=0)
         continue;
        for(c=0;c<m;c++)
        {
            ctr=0;
            for(d=0;d<m;d++)
            {
                if(c==d)
                 continue;
                if(a[d]==a[c])
                 ctr++;
            }
        }
            if(ctr>(a[c]+1))
             b[z]=a[c];

    }
    for(e=0;e<k;e++)
    {
        sum=sum+(b[e]+1);
    }
 printf("total no of applicants %d",sum);
 }
