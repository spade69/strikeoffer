#include <iostream>

using namespace std;
/*?************
Function：实现链表的反向

输入：一个链表
输出：该链表的反向排序
返回：该链表的反向排序

Author:Jason
Version:1.0
Date:2016/05/11

边界： 1.判断节点数目 1 or 2？
2. 链表是否为空
3.

解法1： 调整链表指针的方向。需要保存指针。h->i->j 保存j 和 h。 3个指针
分别指向： 当前遍历的节点、它的前结点、后结点

3种bug：
1)输入链表头指针为NULL或整个链表只有一个结点时、
2)反转后的链表出现断裂
3)返回的反转之后的头结点不是原来的尾结点。



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



ListNode* ReverseList(ListNode* pHead) {
        ListNode* curr=pHead;
        ListNode* prev=NULL;
        //ListNode* p=NULL;
        ListNode* rHead=NULL;
        if(pHead==NULL)
            return NULL;
        if(pHead->next==NULL)
            return pHead;

        while(curr!=NULL){
        ListNode* p=curr->next;//p存放下一个节点
        if(p==NULL)
            rHead=curr;

        curr->next=prev;
        prev=curr;//记录上一次的当前节点
        curr=p;//上一次的下一个节点作为当前节点
        }

        return rHead;
    }


int main()
{
    //cout << "Hello world!" << endl;
    ListNode *p=new ListNode(1);
    ListNode *head=p;
    ListNode *result;
    ListNode *emp=new ListNode(1);

    for(int i=0;i<9;i++)
    {
        ListNode *temp;

        if(i==6)
        //toBeDele=temp;
        temp=new ListNode(7);
        else
        temp=new ListNode(i);


        p->next=temp;
        p=p->next;
    }

    PrintList(head);

    result=ReverseList(head);

    PrintList(emp);

    return 0;
}
