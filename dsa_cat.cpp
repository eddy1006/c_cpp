#include<iostream>
#include<vector>
using namespace std;
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create_node(int n)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->left=ptr->right = NULL;
    return ptr;
}
struct node* left_child(struct node* ptr)
{
    int data;
    cout<<"Enter the data \n";
    cin>>data;
    ptr->left = create_node(data);
    return ptr->left;
}
struct node* right_child(struct node* ptr)
{
    int data;
    cout<<"Enter the data \n";
    cin>>data;
    ptr->right = create_node(data);
    return ptr->right;
}
int isBST(struct node* root)
{
    static struct node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        return 0;
        if(prev!=NULL && prev->data > root->data)
        return 0;
        
        prev = root;
        return isBST(root->right);
    }
    else 
    {
        return 1;
    }
}
int main()
{
    int d;
    cout<<"Enter the head node \n";
    cin>>d;
   struct node* head = create_node(d);
   struct node* prev = NULL;
   struct node* current = head;
   vector<struct node*> vec;
   
   while(true)
   {
       cout<<"Currently working on:"<<current->data<<"\n";
       int choice;
       cout<<"To enter left node press 1 , to enter right node press 2, to go to previous node press 0 , to exit press -1 \n ";
       cin>>choice;
       if(choice==1 and current->left==NULL){
       prev = current;
       vec.push_back(prev);
       current = left_child(prev);
       }
       else if(choice==1 and current->left!=NULL)
       {
           cout<<"Already exists \n";
       }
       else if(choice==2 and current->right==NULL){
       prev = current;
       vec.push_back(prev);
       current = right_child(prev);
       }
       else if(choice==2 and current->right!= NULL)
       {
           cout<<"Already exists \n";
       }
       else if(choice==0 and current!= head){
       current = prev;
       vec.pop_back();
       prev = vec[vec.size()-1];}
       else if(choice==0 and current == head)
       cout<<"No previous node \n";
       else
       break;
   }
   struct node* temp = head->left;
   while(!(temp->right == NULL and temp->left == NULL ))
   isBST(head);
}