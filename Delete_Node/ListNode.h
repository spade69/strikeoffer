#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED
#include<iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    //�����б�ĸ�ֵ��ʽ��
    ListNode(int x):val(x),next(NULL){}
};
ListNode* deleteNode(ListNode* pHead,ListNode* pToBeDeleted);
void PrintList(ListNode *head);
ListNode* deleteDuplication(ListNode* pHead);

#endif // LISTNODE_H_INCLUDED
