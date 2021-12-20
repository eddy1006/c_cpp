#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int x=0;x<=t;x++)
	{
	    int n,m;
	    scanf("%d",&n);
	    printf("\n");
	    scanf("%d",&m)
	    int pos=0;int neg=0;
	    int a[n][m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            scanf("%d",&a[i][j]);
	            printf("\n");
	            if(a[i][j]>0)
	            pos++;
	            else
	            neg++;
	        }
	    }
	    int temp;
	    if(pos>neg)
	    {
	        temp = pos-neg;
	        printf("%d",temp);
	    }
	    else
	    {
	        temp = neg-pos;
	        printf("%d",temp);
	    }
	}
	return 0;
}
