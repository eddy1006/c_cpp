#include<iostream>
using namespace std;

class Multiply
{
    private:
    int num;
    public:
    Multiply(int n){ num=n;}
    Multiply operator *(Multiply &obj)
    {
        cout<<this->num<<endl;
        int res = num * obj.num;   
        return res;
    }
    void print()
    {
        cout<<num;
    }
};

int main(void)
{
    Multiply n1(5);
    Multiply n2(4);
    Multiply  result( n1*n2);  //similar to Multiply result = n1*n2;
    result.print();
}