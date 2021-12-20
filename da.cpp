// A simple inorder traversal based C++ program
// to find k-th smallest element in a BST.
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

// Function to find k'th largest element in BST
// Here count denotes the number of nodes processed so far
Node* kthSmallest(Node* root, int& k)
{
	if (root == NULL)
		return NULL;

	Node* left = kthSmallest(root->left, k);

	if (left != NULL)
		return left;

	k--;
	if (k == 0)
		return root;

	return kthSmallest(root->right, k);
}

void printKthSmallest(Node* root, int k)
{
	// maintain index to count number of nodes processed so far
	int count = 0;
	Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->data;
}

int main()
{
	Node* root = NULL;
    int n;
    cout<<"Enter the no of elements"<<endl;
    cin>>n;
	int keys[n];
    cout<<"Enter the elements :"<<endl;
    for(int i=0;i<n;i++)
    cin>>keys[i];

	for (int x : keys)
		root = insert(root, x);
    cout<<"Enter the value of k:";
	int k;
    cin>>k;
	printKthSmallest(root, k);
	return 0;
}
