#include<iostream>
#include<vector>
using namespace std;

/*************************
*
Function: Find the path that sum equals to x value .
Input: One binary tree and  value x.
Output:Print all paths of this binary tree that equals to sum x.
Return : A 2-dimension vector that store the paths.<--> vector<vectot<int> >


Authot: Jason
Version: 1.0
Date:2016/5/16


************************/
bool visited[100];

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):
				val(x),left(NULL),right(NULL){
	}

};

void findpath(TreeNode* root,int expectNumber,vector<vector<int> >& paths,vector<int>& tmp,int& currentSum)
{

    //bool result=false;
    currentSum+=root->val;
    tmp.push_back(root->val);
    bool isexpect=(root->left==NULL)&&(root->right==NULL)&&(currentSum==expectNumber);
    if(isexpect)
    {
      //  result=true;
        paths.push_back(tmp);
        vector<int>::iterator iter=tmp.begin();
        for(;iter!=tmp.end();iter++)
        {
            cout<<*iter;

        }
        cout<<endl;

    }

    if(root->left!=NULL)
        findpath(root->left,expectNumber,paths,tmp,currentSum);
    if(root->right!=NULL)
        findpath(root->right,expectNumber,paths,tmp,currentSum);
    //if it doesn't satisfy
    currentSum-=root->val;
    tmp.pop_back();

}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber){

    int currentSum=0;
    vector<vector<int> > paths;
    vector<int> tmp;
    if(root==NULL)
        return paths;

    findpath(root,expectNumber,paths,tmp,currentSum);

    return paths;
}

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
    TreeNode* pNode=new TreeNode(2);
    int a[5]={1,2,3,4,5};//6,7,8,9,10};
    vector<vector<int> > path;
    pNode=recurCreateTree(a,0,4);
    PrintTree(pNode);
    path=FindPath(pNode,6);
    vector<int>::iterator iter=path[0].begin();
    for(;iter!=path[0].end();iter++)
        cout<<*iter<<" ";

    return 0;
}


