#include<iostream>
/**
 *
 * Basic operation of Binary Tree
 * Author Jason
 * Date 2016/7/10
 * */
using namespace std;
struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL)
    {}
};



//Create binary tree using an array
//a[] -->
TreeNode* recurCreateTree(int *p,int start,int end)
{
    if(start>end)
        return NULL;

    int mid=start+(end-start)/2;
    TreeNode *pNode=new TreeNode(p[mid]);

    pNode->left=recurCreateTree(p,start,mid-1);
    pNode->right=recurCreateTree(p,mid+1,end);

    return pNode;
}

//Print Tree
void PrintTree(TreeNode *T)
{
    if(T!=NULL){
        PrintTree(T->left);
        cout<<T->val<<"-->"<<endl;
        PrintTree(T->right);
    }
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


