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
void allPairs(BinaryTreeNode<int> *node, int tar)
{
  vector<BinaryTreeNode<int>*> LeftList;
  vector<BinaryTreeNode<int>*> RightList; 
  BinaryTreeNode<int> *curr_left = node;
  BinaryTreeNode<int> *curr_right = node;
 
  while (curr_left != NULL || curr_right != NULL || LeftList.size() > 0 && RightList.size() > 0)
  {
    while (curr_left != NULL)
    {
      LeftList.push_back(curr_left);
      curr_left = curr_left -> left;
    }
    while (curr_right != NULL)
    {
      RightList.push_back(curr_right);
      curr_right = curr_right -> right;
    }
    BinaryTreeNode<int> *LeftNode =
          LeftList[LeftList.size() - 1];
    BinaryTreeNode<int> *RightNode =
          RightList[RightList.size() - 1];
 
    int leftVal = LeftNode -> data;
    int rightVal = RightNode -> data;
    if (leftVal >= rightVal)
      break;
    if (leftVal + rightVal < tar)
    {
      LeftList.pop_back();
      curr_left = LeftNode -> right;
    }
    else if (leftVal + rightVal > tar)
    {
      RightList.pop_back();
      curr_right = RightNode -> left;
    }
    else
    {
      cout << LeftNode -> data << " " <<
              RightNode -> data << endl;
 
      RightList.pop_back();
      LeftList.pop_back();
      curr_left = LeftNode -> right;
      curr_right = RightNode -> left;
    }
  }
}
 
int numNodes(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	return 1+numNodes(root->left)+numNodes(root->right);
}
int main()
{
	BinaryTreeNode<int>* root=takeInputLevelWise();
	int n;
    cout<<"enter the sum value: ";
    cin>>n;
    allPairs(root, n);
    return 0;
}
