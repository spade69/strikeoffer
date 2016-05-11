#include <iostream>
#include"ListNode.h"
using namespace std;



int main()
{
    ListNode *p=new ListNode(1);
    ListNode *head=p;
    ListNode *pHead=head;
    ListNode *toBeDele=new ListNode(0);
    for(int i=0;i<9;i++)
    {
        ListNode *temp;

        if(i==6)
        //toBeDele=temp;
        temp=new ListNode(7);
        else
        temp=new ListNode(i);

        if(i==1)
        p->val=1;

 //        temp=new ListNode(1);
        p->next=temp;
        p=p->next;
    }

    PrintList(head);
    pHead=deleteDuplication(head);
   // deleteNode(head,toBeDele);
    PrintList(pHead);

    return 0;
}
