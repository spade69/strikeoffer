#include <iostream>

using namespace std;
/*?************
Function���ϲ���������������ϲ������ǰ��յ�������

���룺 �����������������
�����һ���µ�����������
���أ�һ���µ������������ͷ���

Author:Jason
Version:1.0
Date:2016/05/11

�߽磺
1. A����գ�B����ǿգ�or A�ǿ� B�� or ��������Ϊ��
2. ֻ��һ�����

�ⷨ1���ݹ顣 ��Ϊ�����ǵõ�����������ֵ��С��ͷ��㲢�������ӵ��Ѿ��ϲ�������֮��
����ʣ��Ľڵ���Ȼ������ģ���˺ϲ��Ĳ����֮ǰ�Ĳ�����һ���ġ�����ǵ��͵ĵݹ�(��ѧ���ɷ�)
�ⷨ2:�ǵݹ�ʵ�֡�

3��bug��
1)û�е���
2)³���ԣ����������������
3)



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
        return pHead1; //����������ǿգ��ǿ϶����Ƿ���NULL�ģ��Ѿ�������������

    ListNode* pMergeHead=NULL;//�������ڴ�ֱ�ӷ���NULL��ʲô������
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
