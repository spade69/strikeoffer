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
struct TreeLinkNode{
    int val;
    struct TreeLink* left;
    struct TreeLink* right;
    struct TreeLink* parent;
    TreeLinkNode(int x):val(x),left(NULL),right(NULL),parent(NULL){
    }
}

TreeLinkNode* GetNext(TreeLinkNode* pNode){
    if(pNode==NULL)
        return NULL;

    //mid order . If right's Node 's leftchild is not empty,then must travseral to left is NULL
    if(pNode->right!=NULL){
        pNode=pNode->right;
        while(pNode->left!=NULL)
        {
            pNode=pNode->left;

        }
        return pNode;
    }
//right is NULL,then go to find the parent!
//parent's left!
    while(pNode->parent!=NULL){
        TreeLinkNode *pRoot=pNode->parent;
        if(pRoot->left==pNode)
            return pRoot;
        pNode=pNode->parent;
    }
    return NULL;
}

int main(){

    return 0;
}


