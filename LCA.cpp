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

BinaryTreeNode<int> *findLCAUtil(BinaryTreeNode<int>* root, int n1, int n2, bool &v1, bool &v2)
{
    if (root == NULL) return NULL;
    if (root->data == n1)
    {
        v1 = true;
        return root;
    }
    if (root->data == n2)
    {
        v2 = true;
        return root;
    }
    BinaryTreeNode<int> *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
    BinaryTreeNode<int> *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);
    if (left_lca && right_lca)  return root;
    return (left_lca != NULL)? left_lca: right_lca;
}
bool find(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return false;
    if (root->data == k || find(root->left, k) ||  find(root->right, k))
        return true;
    return false;
}

BinaryTreeNode<int> *findLCA(BinaryTreeNode<int> *root, int n1, int n2)
{
    bool v1 = false, v2 = false;
    BinaryTreeNode<int> *lca = findLCAUtil(root, n1, n2, v1, v2);
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;
    return NULL;
}
 
int main()
{
	BinaryTreeNode<int>* root=takeInputLevelWise();
	int a,b;
	cout<<"enter the data of two nodes :";
	cin>>a>>b;
	BinaryTreeNode<int> *lca =  findLCA(root, a, b);
    if (lca != NULL)
       cout << "LCA ( "<<a<<", "<<b<<" ) = " << lca->data;
    else
       cout << "Keys are not present ";
    return 0;
}
