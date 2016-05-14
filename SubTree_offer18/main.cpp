#include<iostream>
using namespace std;

/*************************
*
Function: Judge if Tree B is subtree of Tree A.
Input: Two Binary Tree.
Output:Nothing
Return : True or False

Authot: Jason
Version: 1.0
Date:2016/5/12


************************/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):
				val(x),left(NULL),right(NULL){
	}
   
};

//To match Tree1 and Tree2 when find two Root node are equals.
bool DoesTree1HaveTree2(TreeNode* pRoot1,TreeNode* pRoot2){
	
	if(pRoot2==NULL)
		return true;
	if(pRoot1==NULL)
		return false;
	
	if(pRoot1->val!=pRoot2->val)
		return false;
	
	return DoesTree1HaveTree2(pRoot1->left,pRoot2->left)&&DoesTree1HaveTree2(pRoot1->right,pRoot2->right);

}

// To match the root, until we find a root that are equals, or ALl can't match
// We are searching the tree1's node using just pRoot2 's root node.
bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2){
	bool result=false;

	if(pRoot1!=NULL&&pRoot2!=NULL)
	{
		if(pRoot1->val==pRoot2->val)
			result=DoesTree1HaveTree2(pRoot1,pRoot2);
		if(!result)
			result=HasSubtree(pRoot1->left,pRoot2);
		if(!result)
			result=HasSubtree(pRoot1->right,pRoot2);
		
	}

	return result;
}

TreeNode* AddNode(TreeNode *origin,int x)
{
	TreeNode *s=new TreeNode(x);
	
	
	if(x<origin->val)
	{
		origin->left=AddNode(origin->left,x);
	}

	else if(x>origin->val) 
	{
		origin->right=AddNode(origin->right,x);
	}
	return origin;
}

void PrintTree(TreeNode* T)
{
	if(T!=NULL)
	{
		PrintTree(T->left);
		cout<<T->val<<"-->"<<endl;
		PrintTree(T->right);	
	}
}

int main()
{
	TreeNode *root1=new TreeNode(1);
	TreeNode *root2=new TreeNode(2);
	TreeNode *p=root1;
//	root1->left=root2;
	for(int i=0;i<5;i++)
	{
		int t;
		cin>>t;
		p=AddNode(root1,t);
		
	}
	PrintTree(p);
	return 0;
}

