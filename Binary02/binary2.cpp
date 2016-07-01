include<iostream>
using namespace std;
/**
 *Binary tree
 *A node has left right and parent pointer
 *Given a binary tree and a node in it.
 *Find and return the next node at the order
 *midOrder traversal
 *eg : left->root->right
 *
 *Author Jason
 Date 2016/7/1
 * */
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){}
};


bool isSymmetrical(TreeNode* pRoot)
{
    //empty tree
    if(!pRoot)
        return true;
    return isSymmetrical(pRoot->left,pRoot->right);
}

bool isSymmetrical(TreeNode* left,TreeNode* right)
{
    //contains only one root node
    if(!left&&!right)
        return true;
    //one subtree is empty another isn't
    if(!left||!right)
        return false;

    return left->val==right->val&&isSymmetrical(left->left,right->right)&&
        isSymmetrical(left->right,right->left);
}


int main(){

    return 0;
}
