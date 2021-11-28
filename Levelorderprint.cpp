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
void printLevelOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) return;
 
    queue<BinaryTreeNode<int> *> q;
 
    q.push(root);
 
    while (q.empty() == false)
    {
        
        int nodeCount = q.size();
 
        while (nodeCount > 0)
        {
            BinaryTreeNode<int> *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

int main()
{
	BinaryTreeNode<int>* root=takeInputLevelWise();
	
    printLevelOrder(root);
    return 0;
}
