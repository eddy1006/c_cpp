#include<iostream>
using namespace std;

struct node
{
    char data;
    node* next;
    node* prev;
};

struct stack
{
    node* top = NULL;
};

node* create_node(char d)
{
    node* node = (struct node*)malloc(sizeof(node));
    node->data = d;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void push_back(stack* st,char ch)
{
   if((*st).top==NULL)
   {
     node* node = create_node(ch);
     (*st).top = node;
   }
   else
   {
       node* node = create_node(ch);
       (*st).top->next = node;
       node->prev = (*st).top;
       (*st).top = (*st).top->next;
   }
}

char pop_out(stack* st)
{
    char re = (*st).top->data;
    (*st).top = (*st).top->prev;
    return re;
}
int main()
{
    stack stack;
    string something;
    cin>>something;
    int j=0;
    while(j<something.length())
    {
        char d = something[j];
        j++;
        push_back(&stack,d);
    }
    while(stack.top!=NULL)
    {
        char dd = pop_out(&stack);
        cout<<dd;
    }
}