#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

vector<int> v;
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

void pre_traverse(struct node* head)
{
    if(head!=NULL){
    printf("%d ",head->data);
    pre_traverse(head->ptr1);
    pre_traverse(head->ptr2);}
}

void post_traverse(struct node* head)
{
    if(head!=NULL)
    {
        post_traverse(head->ptr1);
        post_traverse(head->ptr2);
        printf("%d ",head->data);
    }
}

void inorder_traverse(struct node* head)
{
    if(head!=NULL)
    {
       inorder_traverse(head->ptr1);
       printf("%d ",head->data);
       v.push_back(head->data);
       inorder_traverse(head->ptr2);
    }
}

int isBST(struct node* root)
{
    static struct node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->ptr1))
        return 0;
        if(prev!=NULL && prev->data > root->data)
        return 0;
        
        prev = root;
        return isBST(root->ptr2);
    }
    else 
    {
        return 1;
    }
       
}
bool search(struct node* root,int num)
{
    if(root!=NULL)
    {
        if(root->data == num)
        return true;
        if(num>root->data)
        return search(root->ptr2,num);
        else
        return search(root->ptr1,num);
    }
    return false;
}
bool iterativeSearch(struct node* root,int num)
{
    while(root!=NULL)
    {
        if(root->data == num)
        return true;
        if(num>root->data)
        root = root->ptr2;
        else
        root = root->ptr1;
    }
    return false;
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
int main(void)
{
    struct node* root;
    struct node* c1;
    struct node* c2;
    struct node* c11;
    struct node* c12;
    struct node* c21;
    struct node* c22;
    struct node* t;
    root = createnode(7);
    c1 = createnode(5);
    c2 = createnode(9);
    c11 = createnode(1);
    c12 =createnode(6);
    c21 =createnode(8);
    c22 = createnode(10);
    root->ptr1 = c1;
    root->ptr2 = c2;
    c1->ptr1 = c11;
    c1->ptr2 = c12;
    c2->ptr1 = c21;
    c2->ptr2 = c22;
    pre_traverse(root);
    printf("\n");
    post_traverse(root);
    printf("\n");
    inorder_traverse(root);
    printf("\n");
    printf("%d",isBST(root));
    printf("\n");
    for(int i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
    if(iterativeSearch(root,15))
    printf("Yes its present");
    else 
    printf("No its not there ");
    insertion(root,3);
    inorder_traverse(root);
    return 0;
}
