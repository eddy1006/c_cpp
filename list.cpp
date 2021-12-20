#include<iostream>
using namespace std;

class list{
    public:
    int data;
    list* ptr;
};
list* fill_list(int n)
{
    list* head;list* p;
    for(int i=1;i<=n;i++)
    {
       if(i==1)
       {
           list* node = new list;
           head = node;
           cout<<"Enter element"<<endl;
           cin>>node->data;
           node->ptr = NULL;
       }
       else 
       {
           list* node = new list;
           cout<<"Enter element"<<endl;
           cin>>node->data;
           node->ptr = NULL;
           p = head;
           while(p->ptr!=NULL)
           {
               p = p->ptr;
           }
           p->ptr = node;
       }
    }
    return head;
}
void print_list(list* key)
{
   list* p = key;
   while(p->ptr!=NULL)
   {
       cout<<p->data<<"-->";
       p = p->ptr;
   }
   cout<<p->data;
}
void insert_list(list*key,int n)
{
    list* p = key;
    for(int i=1;i<n-1;i++)
    {
        p = p->ptr;
    }
    list* node = new list;
    cout<<"Enter element"<<endl;
    cin>>node->data;
    node->ptr = p->ptr;
    p->ptr = node;

}
int main(void)
{
    list* key;
       key = fill_list(5);
        print_list(key);
        insert_list(key,1);
        print_list(key);
        return 0;
}