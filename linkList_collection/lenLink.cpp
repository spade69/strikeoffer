#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

//return the lenA of circle
 int EntryNodeOfLoop(ListNode* pHead)
    {
		//ListNode *p=pHead;
        int lenA=0;
        int x=0;
        int l=0;
        ListNode *fast=pHead;
        ListNode *slow=pHead;
        ListNode *p=pHead;
        while(fast->next!=NULL&&fast->next->next!=NULL&&slow->next!=NULL){
            fast=fast->next->next;
            l+=2;
            slow=slow->next;
            x++;
            if(fast==slow){//first time meets
                lenA=l-x;
                break;
            }
        }
        int tmp=lenA;
        /*
        while(tmp>0){
            p++;
            tmp--;
        }*/
        if(lenA>0)
        return lenA;
        else
        return 0;
    }
