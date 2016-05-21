#include<iostream>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){
    }
};


TreeNode* recurCreateTree(int *p,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }


        int mid=start+(end-start)/2;
        TreeNode *pNode=new TreeNode(p[mid]);

        pNode->left=recurCreateTree(p,start,mid-1);
        pNode->right=recurCreateTree(p,mid+1,end);

        return pNode;


}


void ConvertNode(TreeNode* pNode,TreeNode** pLastNodeInList)
{

    if(pNode==NULL)
        return;

    //These codes are the true processing code. And quals to the number of
    //nodes in the binary tree. it means that you will recurse evrry node in the tree.
    //first, processing left subtree of root,it will recurse until reach the
    //condition that pNode->left==NULL, then we processing ,times equals to the times
    //you recurse "ConvertNode(pCurrent->left,pLastNodeInList)"
    //and then you recurse the right part
    TreeNode* pCurrent=pNode;
    if(pNode->left!=NULL)
    {
        cout<<"leftconvert"<<" "<<endl;
        ConvertNode(pCurrent->left,pLastNodeInList) ;
    }

    pCurrent->left=*pLastNodeInList;
    if(*pLastNodeInList!=NULL)
        (*pLastNodeInList)->right=pCurrent;

    *pLastNodeInList=pCurrent;
    cout<<"process"<<pCurrent->val<<".."<<endl;

    if(pNode->right!=NULL)
    {

        cout<<"right_convert:"<<pNode->val<<".."<<endl;
        ConvertNode(pCurrent->right,pLastNodeInList);
    }
}

TreeNode* Convert(TreeNode* pRoot)
{
    TreeNode *pLastNodeInList=NULL;
    ConvertNode(pRoot,&pLastNodeInList);

    //pLastNodeInList means that last node of this linklist
    //we need to return the head node
    TreeNode* pHead=pLastNodeInList;
    while(pHead!=NULL&&pHead->left!=NULL)
        pHead=pHead->left;

    return pHead;
}


int main()
{
    TreeNode* pNode=new TreeNode(2);
    TreeNode* result;
    int a[7]={4,6,8,10,12,14,16};//6,7,8,9,10};
    pNode=recurCreateTree(a,0,6);
    result=Convert(pNode);

    return 0;
}

