#include<iostream>
#include<deque>
#include<iterator>
#include<vector>
using namespace std;

/*************************
*
Function: Print Binary Tree Hierachy and from left to right!.
Similarly to PrintNodeByLevel.

Input: One Binary Tree
Output:Print A sequence;
Return : A sequence store in vector<int>

Authot: Jason
Version: 1.0
Date:2016/7/4


************************/

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL) {}
};

vector<int> reverse(vector<int> vec){
    vector<int> result;
    for(int i=vec.size();i>=0;i--){
        result.push_back(vec[i]);
    }
    return result;
}

vector<vector<int> > Print(TreeNode* pRoot){
    vector<vector<int> > result;//store the value
    vector<int> temp;
    deque<TreeNode*> deNode;//store the address

    int toPop=1;
    int toBePrint=0;
    int level=1;

    if(root==NULL)
        return result;

    deNode.push_back(pRoot);

    while(!deNode.empty()){
        //You figure out the left and right according to the front()!
        //and every time,front element will be pop,need to write down in your paper when thinking!
        TreeNode* node=deNode.front();
        deNode.pop_front();
        toPop--;//indicate the number you need to pop;
        //cout<<tmp-val<<endl;
        temp.push_back(node->val);


        if(node->left){
            deNode.push_back(node->left);
            toBePrint++;
        }

        if(node->right){
            deNode.push_back(node->right);
            toBePrint++;
        }

        if(toPop==0){//do it every level
            if(level%2==0)
                temp=reverse(temp);
            result.push_back(temp);
            vector<int>().swap(temp);//clear temp
            toPop=toBePrint;
            toBePrint=0;
            level++;
        }


    }
    return result;
}


