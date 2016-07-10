#include<iostream>

/*
 *Binary Tree
 * return the Kth Node in a binary tree
 * Author Jason
 * Date 2016/7/10
 * **/
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

int count=0;
TreeNode* KthNode(TreeNode* pRoot,unsigned int k)
{
    if(pRoot){
        TreeNode* ret=KthNode(pRoot->left,k);
        if(ret) return ret;
        if(k==++count) return pRoot;
        ret=KthNode(pRoot->right,k);
        if(ret) return ret;
    }

    return NULL;
}

int main(){

    return 0;
}
