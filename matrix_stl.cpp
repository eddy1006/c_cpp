#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
bool isEven(int i)
{
    if(i%2==0)
    return true;
    else
    return false;
}
int main()
{
    int rows,cols;
    cin>>rows>>cols;
    vector<vector<int>> matrix;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>matrix[i][j];
        }
    }
    int choice;
    cin>>choice;
    int row_oper;
    cin>>row_oper;
    if(choice==1)
    {
        vector<int> vec;
        for(int j=0;j<cols;j++)
        {
            cin>>vec[j];
        }
        vector<vector<int>>::iterator it = matrix.begin();
        matrix.insert(it+row_oper-1,vec);
       for(int i=0;i<rows+1;i++)
       {
        for(int j=0;j<cols;j++)
        {
            cout<<matrix[i][j];
        }
       }
    }
    else if(choice==2)
    {
        vector<vector<int>>::iterator it = matrix.begin();
        matrix.erase(it+row_oper-1);
       for(int i=0;i<rows-1;i++)
       {
        for(int j=0;j<cols;j++)
        {
            cout<<matrix[i][j];
        }
       }
    }
    else if(choice==3)
    {
        int sum;
        for(int x=0;x<cols;x++)
        sum = sum+ matrix[row_oper-1][x];
        cout<<sum;
    }
    else
    {
        vector<vector<int>>::iterator itr = *(matrix.begin()+row_oper-1)->begin()
        int counter=count_if(it,it+cols,isEven(*it));
        cout<<counter;
    }
}