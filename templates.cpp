#include<iostream>
using namespace std;

template <class T1=int, class T2=float>
class Eddy 
{
    public:
    T1 * a1;
    T2 * a2;
    int size;

    Eddy(int x)
    {
        size = x;
        a1 = new T1[size];
        a2 = new T2[size];
    }
    void display()
    {
        for(int i=0;i<size;i++)
        cout<<a1[i]<<" "<<a2[i]<<endl;
    }

};

int main(void)
{
    Eddy<int>obj(3);
    obj.a1[0] = 4;
    obj.a1[1] = 3;
    obj.a1[2] = 2;
    obj.a2[0] = 4.5;
    obj.a2[1] = 3.2;
    obj.a2[2] = 2.1;
    obj.display();
    return 0;

}
