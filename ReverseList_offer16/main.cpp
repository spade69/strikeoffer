#include <iostream>

using namespace std;
/*?************
Function��ʵ������ķ���

���룺һ������
�����������ķ�������
���أ�������ķ�������

Author:Jason
Version:1.0
Date:2016/05/11

�߽磺 1.�жϽڵ���Ŀ 1 or 2��
2. �����Ƿ�Ϊ��
3.

�ⷨ1�� ��������ָ��ķ�����Ҫ����ָ�롣h->i->j ����j �� h�� 3��ָ��
�ֱ�ָ�� ��ǰ�����Ľڵ㡢����ǰ��㡢����

3��bug��
1)��������ͷָ��ΪNULL����������ֻ��һ�����ʱ��
2)��ת���������ֶ���
3)���صķ�ת֮���ͷ��㲻��ԭ����β��㡣



�߼���ܲ��ö�������! ��ߴ���������
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
        ListNode* p=curr->next;//p�����һ���ڵ�
        if(p==NULL)
            rHead=curr;

        curr->next=prev;
        prev=curr;//��¼��һ�εĵ�ǰ�ڵ�
        curr=p;//��һ�ε���һ���ڵ���Ϊ��ǰ�ڵ�
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
