#include <bits/stdc++.h>
using namespace std;
 

void insertion_sort(int a[],int n,int sorted){
    if(n == sorted ){
       return;
    }
    for(int i = sorted+1; i>0;i--){
        if(a[i]< a[i-1]){
            int temp = a[i];
            a[i] =a[i-1];
            a[i-1] = temp;
        }
    }
    insertion_sort(a,n,sorted+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[5];
    for(int i = 0;i<5;i++)
    cin>>a[i];
    insertion_sort(a,4,0);
     for(int i = 0; i<sizeof(a)/sizeof(int); i++)
        cout<<a[i];
    return 0;
}