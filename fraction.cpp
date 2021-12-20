#include<iostream>
using namespace std;

struct Fraction 
{
    int n;
    int m;
};

int main()
{
    Fraction* f1 = (Fraction*)malloc(sizeof(Fraction));
    Fraction* f2 = (Fraction*)malloc(sizeof(Fraction));
    Fraction* f3 = (Fraction*)malloc(sizeof(Fraction));
    cin>>f1->n;
    cin>>f1->m;
    cin>>f2->n;
    cin>>f2->m;
    f3->n = (f1->n*f2->m) + (f2->n*f1->m);
    f3->m = f1->m * f2->m;
    cout<<f3->n<<"/"<<f3->m;
}