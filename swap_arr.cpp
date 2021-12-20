#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
float area(int a,int b,int c)
{
     float p = (a+b+c)/2.0;
     return (p*(p-a)*(p-b)*(p-c));
}
void swap(int* a, int* b)
{
   
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
void sort_by_area(triangle* tr, int n) {
	for(int i=0;i<n-1;i++)
    {
        float s_min = area(tr[i].a,tr[i].b,tr[i].c);
       
        int index =i;
        for(int j=i+1;j<n;j++)
        {
             float s_temp = area(tr[j].a,tr[j].b,tr[j].c);
            if(s_temp<s_min)
            {
                s_min = s_temp;
                index = j;
            }
        }
        swap(&tr[i].a,&tr[index].a);
        swap(&tr[i].b,&tr[index].b);
        swap(&tr[i].c,&tr[index].c);
    }
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr =(triangle*)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}