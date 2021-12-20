#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            int temp = 4;
            while(j%5!=0)
            {
                int temp2 = j + temp;
                cout<<temp2<<" ";
                j++;
                temp=temp-1;
            }
            cout<<j<<"\n";
            j++;
        }
        else
        {
            while(j%5!=0)
            {
                cout<<j<<" ";
                j++;
            }
            cout<<j<<"\n";
            j++;
        }
    }
	// your code goes here
	return 0;
}
