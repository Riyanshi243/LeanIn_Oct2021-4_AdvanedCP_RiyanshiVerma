#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"enter root data "<<endl;
	cin>>rootData;
	if(rootData==-1)
	{
		return NULL;
	}
	
	BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
	
	queue<BinaryTreeNode<int>*>pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"enter left child of"<< front->data<<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!=-1)
		{
			BinaryTreeNode<int>* child= new BinaryTreeNode<int>(leftChildData);
			front->left=child;
			pendingNodes.push(child);
		}
		
		
		cout<<"enter right child of"<< front->data<<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!=-1)
		{
			BinaryTreeNode<int>* child= new BinaryTreeNode<int>(rightChildData);
			front->right=child;
			pendingNodes.push(child);
		}
	}
	
	return root;
}
int max(int a, int b)
{
    return (a >= b) ? a : b;
}
int find_height(BinaryTreeNode<int>* node)
{
   
    if (node == NULL)
        return 0;
    return 1 + max(find_height(node->left),
                   find_height(node->right));
}
bool isBalanced(BinaryTreeNode<int>* root)
{
    int lh; 
    int rh;

    if (root == NULL)
        return 1;
 
    lh = find_height(root->left);
    rh = find_height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
 
    return 0;
}


int main()
{
	BinaryTreeNode<int>* root=takeInputLevelWise();
	
	if (isBalanced(root))
        cout << "Binary Tree is balanced";
    else
        cout << "Binary Tree is not balanced";
    return 0;
}
