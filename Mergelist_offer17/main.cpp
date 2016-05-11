#include <iostream>

using namespace std;
/*?************
Function：合并两个排序的链表，合并后仍是按照递增排序。

输入： 两个递增排序的链表。
输出：一个新递增排序链表。
返回：一个新递增排序链表的头结点

Author:Jason
Version:1.0
Date:2016/05/11

边界：
1. A链表空，B链表非空，or A非空 B空 or 两个链表都为空
2. 只有一个结点

解法1：递归。 因为当我们得到两个链表中值较小的头结点并把它链接到已经合并的链表之后，
两个剩余的节点依然是排序的，因此合并的步骤和之前的步骤是一样的。这就是典型的递归(数学归纳法)
解法2:非递归实现。

3种bug：
1)没有递增
2)鲁棒性，特殊输入如空链表
3)



逻辑框架不用动，解耦! 提高代码重用性
********/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

void PrintList(ListNode *head)
{
    if(head==NULL)
    {
        cout<<"Your List is empyy!"<<endl;
        return;
    }
    ListNode *p=head;
    while(p!=NULL)
    {
        cout<<"Val:"<<p->val<<endl;
        p=p->next;
    }
    cout<<endl;
}

ListNode* CreateList(ListNode *head)
{
    ListNode *p=head;
   // ListNode *head=p;

    ListNode *result;
    for(int i=head->val;i<=9;i+=2)
    {
        ListNode *temp;

        temp=new ListNode(i);


        p->next=temp;
        p=p->next;
    }
    result=head;
    return result;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1==NULL)
        return pHead2;
    else if(pHead2==NULL)
        return pHead1; //如果两个都是空，那肯定就是返回NULL的，已经包含在里面了

    ListNode* pMergeHead=NULL;//不分配内存直接分配NULL有什么问题吗？
    if(pHead1->val>pHead2->val)
    {
        pMergeHead=pHead2;
        pMergeHead->next=Merge(pHead1,pHead2->next);
    }
    else
    {
        pMergeHead=pHead1;
        pMergeHead->next=Merge(pHead1->next,pHead2);
    }

    return pMergeHead;
  //  if(pHead1->next==NULL||pHead2->next==NULL)
    //    return pMergeHead;




}

int main()
{

    ListNode *head=new ListNode(0);
    ListNode *head2=new ListNode(1);
    ListNode *result=CreateList(head);
    ListNode *result2=CreateList(head2);
    ListNode *merResult=NULL;
    PrintList(result);
    PrintList(result2);
    //result=Merge(head);
    merResult=Merge(head,head2);
   // PrintList(emp);
    PrintList(merResult);
    return 0;
}
