#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int value):val(value),left(NULL),right(NULL)
    {}
};

int TreeDepth(TreeNode *root){
    if(root==NULL)
        return 0;
    int nleft=TreeDepth(root->left);
    int nright=TreeDepth(root->right);
    return (nleft>nright)?(nleft+1):(nright+1);
}

bool isBalanced(TreeNode* root,int* depth){
    if(root==NULL)
    {
        *depth=0;
        return true;
    }
    int left,right;
    if(isBalanced(root->left,&left)&&isBalanced(root->right,&right)){
        int diff=left-right;
        if(diff>=-1&&diff<=1){
            *depth=1+(left>right?left:right);
			return true;        
		}
        
    }
    return false;
}

bool isBalanced(TreeNode* root){
    int depth=0;
    return isBalanced(root,&depth);
}

int main()
{

    return 0;
}


