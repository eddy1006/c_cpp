#include<iostream>
using namespace std;

int req_height;int sum=0;
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

int iterativeSearch(struct node* root,int num)
{
    int h=0;
    while(root!=NULL)
    {
        if(root->data == num)
        return h;
        if(num>root->data){
        root = root->ptr2;h++;}
        else{
        root = root->ptr1;h++;}
    }
    return h;
}

int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->ptr1);
        int rheight = height(node->ptr2);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
/* Print nodes at a current level */
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->ptr1, level-1);
        printCurrentLevel(root->ptr2, level-1);
    }
}
/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
    int h = height(root);
    for (int i=1; i<=h; i++)
        printCurrentLevel(root, i);
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
    req_height = height(root) - (iterativeSearch(root,x));
    printLevelOrder(root);
}