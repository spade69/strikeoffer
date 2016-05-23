#include<isotream>
#include<deque>
#include<iterator>
#include<vector>
using namespace std;

/*************************
*
Function: Print Binary Tree from top to bottom.
Input: One Binary Tree
Output:Print A sequence;
Return : A sequence store in vector<int>

Authot: Jason
Version: 1.0
Date:2016/5/15


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

vector<int> PrintFromTopToBottom(TreeNode *root){
    vector<int> result;//it's ok,it's empty
    deque<int> deNode;
    TreeNode* tmp=root;

    if(root==NULL)
        return result;

    deNode.push_back(root->val);

  //  while(tmp->left!=NULL&&tmp->right!=NULL)
    while(!deNode.empty())
     {
         //every time we set the front's element as tmp, than we store its
         //left and right . and pop them using FIFO
        tmp=deNode.front();
        deNode.pop_front();

        cout<<tmp->val<<endl;
        result.push_back(tmp->val);

        if(tmp->left)
        {
        //result.push_back(tmp->left->val);
            deNode.push_back(tmp->left->val);
         }
         if(tmp->right)
        {
        //result.push_back(tmp->right->val);
            deNode.push_back(tmp->right->val);
        }

    }

    return result;
}

int main(){

    return 0;
}

