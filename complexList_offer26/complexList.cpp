#include<iostream>

using namespace std;

struct RandomListNode{
    int label;
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

void CloneNode(RandomListNode* pHead)
{
    RandomListNode* pNode=pHead;
    while(pNode!=NULL)
    {
        RandomListNode* pClone=new RandomListNode(pNode->label);

        //pClone->label=pNode->label;
        pClone->next=pNode->next;
        pClone->random=NULL;
        pNode->next=pClone;
        pNode=pClone->next;
    }
}

void ConnectNode(RandomListNode *pHead)
{
    RandomListNode* pNode=pHead;

    while(pNode!=NULL)
    {
        RandomListNode* pClone=pNode->next;
        if(pNode->random!=NULL)
        {    pClone->random=pNode->random->next;}

        pNode=pClone->next;

    }
}

RandomListNode* Reconnect(RandomListNode *pHead)
{
    RandomListNode *pNode=pHead;
    RandomListNode *pClone=NULL;
    RandomListNode *pCloneHead=NULL;
    if(pNode->random!=NULL)
    {
        pClone=pCloneHead=pNode->next;
        pNode->next=pClone->next;
        pNode=pNode->next;
    }

    while(pNode!=NULL)
    {
        pClone->next=pNode->next;
        pClone=pClone->next;
        pNode->next=pClone->next;
        pNode=pNode->next;
    }
    return pCloneHead;
}

RandomListNode* Clone(RandomListNode* pHead)
{
    if(!pHead) return NULL;
    RandomListNode* pNode=pHead;
    while(pNode!=NULL)
    {
        RandomListNode* pClone=new RandomListNode(pNode->label);

        //pClone->label=pNode->label;
        pClone->next=pNode->next;
        pClone->random=NULL;
        pNode->next=pClone;
        pNode=pClone->next;
    }

    pNode=pHead;
    while(pNode!=NULL)
    {
        RandomListNode* pClone=pNode->next;
        if(pNode->random!=NULL)
        {    pClone->random=pNode->random->next;}

        pNode=pClone->next;

    }

    RandomListNode *pClone;
    RandomListNode *pCloneHead=pHead->next;
    pNode=pHead;


    while(pNode->next)
    {
        pClone=pNode->next;
        pNode->next=pClone->next;
        pNode=pClone;
    }
    return pCloneHead;

}

int main()
{
    cout<<"hello world"<<endl;
    return 0;
}
