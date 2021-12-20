// program not working
#include<iostream>
#include<list>
#include<map>
using namespace std;
map<int,int> mapping;
class  Graph
{
   private:
   int v;
   list<int> *l;
   public:
   Graph(int v)
   {
       this->v = v;
       l = new list<int>[v];
   }
   void addVertices(int *arr)
   {
       for(int i=0;i<v;i++)
       {
           mapping.insert({*arr+i,i});
       }
   }
   void addEdge(int x,int y)
   {
       l[mapping[x]].push_back(y);
       l[mapping[y]].push_back(y);
   }
   void printGraph()
   {
       for(int i=0;i<v;i++)
       {
           for( int nbr:l[i])
           {
               cout<<nbr<<",";
           }
           cout<<endl;
       }   
   }
};

int main(void)
{
    Graph g(6);
    int* a = new int[6];
    a[0] = 4;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 7;
    a[5] = 5;
    g.addVertices(a);
    g.addEdge(4,1);
    g.addEdge(4,3);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,7);
    g.addEdge(5,2);
    g.addEdge(7,3);
    g.printGraph();
}