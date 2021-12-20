#include <bits/stdc++.h>
using namespace std;

void sum_triangle(int* a,int n){
    if(n==1){
       cout<<a[0]<<"\n";
       return;
    }
    int arr[n-1];
    for(int i =0;i<n-1;i++){
        arr[i] = a[i] + a[i+1];
    }
    sum_triangle(arr,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = 5;
    sum_triangle(a,n);
    return 0;
}