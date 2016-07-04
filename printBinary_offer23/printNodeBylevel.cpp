/*
 * Print Node By level
 * using queue
 * similar to print From top 2 Bottom
 *
 * */

#include<iostream>
using namespace std;

void PrintNodeByLevel(Node *root){
    int parentSize=1,childSize=0;
    Node *temp;
    queue<Node *> q;
    q.push(root);
    do
    {
        temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
            childSize++;
        }
        if(temp->right!=NULL){
            q.push(temp->right);
            childSize++;
        }

        parentSize--;
        if(parentSize==0){
            parentSize=childSize;
            childSize=0;

        }
    }while(!q.empty());
}
