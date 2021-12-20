#include <iostream>
using namespace std;
int* createarray(int n)
{
    int* a = new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    return a;
}
void printarray(int* a,int n)
{
    for(int i =0;i<n;i++)
    cout<<a[i]<<" ";
}
void rotation(int* a,int n)
{
    for(int i=0;i<n-1;i++)
	    {
	        int temp = a[i];
	        a[i]= a[i+1];
	        a[i+1] = temp;
	    }
}
int main() {
	int t;
	cin>>t;
    while(t>0){
	    int n,d;
	    cin>>n>>d;
	    int* a;
	    a = createarray(n);
	    if(d>n)
	    d = d-n;
	    for(int j=1;j<=d;j++){
	      rotation(a,n);
	    }
	    printarray(a,n);
	    cout<<endl;
	    t--;
	}
	return 0;
}
