#include<iostream>
using namespace std;

/***************8
Author: Jason
Date: 2016/06/05
**********************/


struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int value):
        val(value),next(NULL){}
};

//Common node point to the same next node!
//they look like shape: "Y"
//We find the common node from end ,begin our search at last index of the link
//We need a stack to store!
ListNode* FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2)
{

   ListNode *p1=pHead1;
   ListNode *p2=pHead2;
   ListNode *plong=pHead1;
   ListNode *pshort=pHead2;
   ListNode *result=NULL;
   int len1=0;
   int len2=0;
   int diff=0;
   //if two list one is NULL then,does't satisfy.
    if(pHead1==NULL||pHead2==NULL)
        return NULL;

    while(p1!=NULL)
    {
        p1=p1->next;
        len1++;
    }

    while(p2!=NULL)
    {
        p2=p2->next;
        len2++;
    }
    if(len1<len2){
        diff=len2-len1;
        plong=pHead2;
        pshort=pHead1;
    }
//normal:
    diff=len1-len2;

    for(int i=0;i<diff;i++){
        plong=plong->next;
    }

    while(plong!=NULL&&pshort!=NULL&&(plong!=pshort)){
        plong=plong->next;
        pshort=pshort->next;
    }
    result=plong;

    return result;
}


int main(){

    return 0;
}




