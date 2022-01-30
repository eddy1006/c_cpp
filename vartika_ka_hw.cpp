// C++ program to print BST in given range
#include<bits/stdc++.h>
using namespace std;
 
/* A Binary Tree node */
struct familyMember{
    string name;
    string sex;
    int age;
    int aadhar;
};

class TNode
{
    public:
    struct familyMember data;
    TNode* left;
    TNode* right;
};
 
TNode* newNode(struct familyMember data);
 
void sortArray(struct familyMember* arr){
    for(int i=0;i<6;i++){
        for(int j=i+1;j<7;j++){
            if(arr[j].age < arr[i].age){
                struct familyMember temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

}

/* A function that constructs Balanced
Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(struct familyMember arr[],
                        int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1);
 
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);
 
    return root;
}
 
/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
TNode* newNode(struct familyMember data)
{
    TNode* node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
/* A utility function to print
preorder traversal of BST */
void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data.age << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void searchInBst(TNode* node, int key)
{
    TNode* tmp = node;
    if (tmp) {
        if (key > tmp->data.age) {
            searchInBst(tmp->left, key);
            cout << tmp->data.age << endl;
            searchInBst(tmp->right, key);
        } else {
            searchInBst(tmp->left, key);
        }
    }
}
 
// Driver Code
int main()
{
    struct familyMember members[8];
    for(int i=0;i<8;i++){
        printf("Enter the details of member number %d \n",i+1);
        cout<<"Enter name\n";
        cin>>members[i].name;
        cout<<"Enter age\n";
        cin>>members[i].age;
        cout<<"Enter sex\n";
        cin>>members[i].sex;
        cout<<"Enter aadhar number\n";
        cin>>members[i].aadhar;
    }
    sortArray(members);
    for(int i=0;i<7;i++){
        cout<<members[i].age<<" ";
    }
    cout<<"\n";
    /* Convert List to BST */
    TNode *root = sortedArrayToBST(members, 0, 7);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    cout<<endl;
    searchInBst(root,18);
    return 0;
}
 