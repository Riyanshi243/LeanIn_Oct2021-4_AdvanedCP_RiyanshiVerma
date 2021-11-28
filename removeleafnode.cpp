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
void inorder(BinaryTreeNode<int>* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
 
BinaryTreeNode<int>* leafDelete(BinaryTreeNode<int>* root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
 
    root->left = leafDelete(root->left);
    root->right = leafDelete(root->right);
 
    return root;
}
 
int main()
{
	BinaryTreeNode<int>* root=takeInputLevelWise();
	cout << "Inorder before Deleting the leaf Nodes" << endl;
    inorder(root);
    cout << endl;
    leafDelete(root);
    cout << "Inorder after Deleting the leaf Nodes" << endl;
    inorder(root);
    return 0;
}
