#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED
#include<iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    //参数列表的赋值形式。
    ListNode(int x):val(x),next(NULL){}
};
ListNode* deleteNode(ListNode* pHead,ListNode* pToBeDeleted);
void PrintList(ListNode *head);
ListNode* deleteDuplication(ListNode* pHead);

#endif // LISTNODE_H_INCLUDED
