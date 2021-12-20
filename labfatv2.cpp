#include<iostream>
using namespace std;

struct node
{
   int data;
   struct node* ptr1;
   struct node* ptr2;
};
struct node* createnode(int value)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->ptr1 = NULL;
    ptr->ptr2 = NULL;
    return ptr;
}
void insertion(struct node* root,int n)
{  
    struct node* prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(root->data > n )
        root = root->ptr1;
        else
        root = root->ptr2;
    }
    struct node* ptr = createnode(n);
    if(prev->data >n){
    prev->ptr1 = ptr;
    ptr->data = n;}
    else{
        prev->ptr2 = ptr;
        ptr->data = n;
    }
}
int depth(node *root, int x)
{
    if (root == NULL)
    {
        return -1;
    }
    int dist = -1;

    if ((root->data == x)|| (dist = depth(root->ptr1, x)) >= 0|| (dist = depth(root->ptr2, x)) >= 0)
        return dist + 1;
    return dist;
}
int main()
{
    int n;node*root;
    cout<<"Enter the no of elements in the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        if(j==0)
        root = createnode(a[j]);
        else
        insertion(root,a[j]);
    }
    int x;
    cout<<"Enter the value of x:";
    cin>>x;
    int keydepth;
    keydepth = depth(root, x);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (depth(root, a[i]) == keydepth)
        {
            sum = sum + a[i];
        }
    }
    cout << "The sum of all the elements in the same level as the node entered is" << endl;
    cout << sum;
}