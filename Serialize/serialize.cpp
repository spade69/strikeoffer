#include<iostream>
#include<deque>
#include<string.h>
using namespace std;
/**
 *Serialize and Deserialize
 BinaryTree
 *
 *Transform a binaryTree to
 *a char* Array

 * Author:Jason
 Date 2016/0707
 * *****/

struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
    TreeNode(int value):val(value),left(NULL),right(NULL)
    {}

}

char* Serialize(TreeNode* root){
    if(root==NULL){
        char* s=new char[2];
        sprintf(s,"#$");
        return s;
    }

    char* list=new char[10000];
    deque<TreeNode*> deNode;
    deNode.push_back(root);
    TreeNode* node;
    while(!deNode.empty()){
        node=deNode.front();
        if(node==NULL){
            len+=sprintf(list,"#");
        }
        else{
            len+=sprintf(list+len,"%d",node->val);
            deNode.push_back(node->left);
            deNode.push_back(node->right);

        }
        deNode.pop_front();
    }
}


int main(){

    return 0;
}
