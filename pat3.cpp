#include<iostream>
using namespace std;

class Vectors
{
    private:
    int a;
    int b;
    int c;
    public:
    Vectors(){}
    Vectors(int x,int y,int z){a=x;b=y;c=z;}
    Vectors operator + (Vectors const &obj)
    {
        Vectors v;
        v.a = this->a + obj.a;
        v.b = this->b + obj.b;
        v.c = this->c + obj.c;
        return v;
    }
    void show()
    {
        cout<<a<<"i"<<b<<"j"<<c<<"k"<<endl;
    }
    friend Vectors operator - (Vectors &obj1,Vectors &obj2);
};

Vectors operator - (Vectors &obj1,Vectors &obj2)
{        
    Vectors v;
    v.a = obj1.a - obj2.a;
    v.b = obj1.b - obj2.b;
    v.c = obj1.c - obj2.c;
    return v;
}

int main()
{
    int v1_a,v1_b,v1_c;
    cin>>v1_a>>v1_b>>v1_c;
    Vectors v1(v1_a,v1_b,v1_c);
    int v2_a,v2_b,v2_c;
    cin>>v2_a>>v2_b>>v2_c;
    Vectors v2(v2_a,v2_b,v2_c);
    Vectors v3 = v1 + v2;
    Vectors v4 = v1 - v2;
    v3.show();
    v4.show();
}