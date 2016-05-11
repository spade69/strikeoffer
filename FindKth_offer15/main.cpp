#include <iostream>

using namespace std;
/*?************
Function������

���룺һ������


�����������ĵ�����k���ڵ㡣
���أ�void

Author:Jason
Version:1.0
Date:2016/05/08

�߽磺 1.�жϽڵ���Ŀ n<k?
2. �����Ƿ�Ϊ��
3. k����Ϊ0��û�е�����0��

�ⷨ1�� �����������Σ� ��һ���ȵõ�����ĳ���n��
Ȼ�����n�� n-k+1 ��������Ҫ�ҵĵ�����k���ڵ㣡
�ⷨ2�� ֻ�����һ�Σ�ʹ������ָ��(or������)����һ��ָ���������k��λ��ʱ��
Ȼ����õ�2��ָ�뿪ʼ����������ͬʱ��ʼ����ֱ��
 P1 : k-1  P2: n-(k-1) !
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

class findKth {
public:



    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

        if(pListHead==NULL||k==0)//������Ϊ�գ����k����Ϊ0
            return NULL;

        ListNode* Head=pListHead;
        ListNode* Behind=NULL;


        for(int i=0;i<k-1;i++)
        {
            if(Head->next!=NULL) //����
            Head=Head->next;
            else
            {
                return NULL;
            }
        }

        Behind=pListHead;

        while(Head->next!=NULL)
        {
             Head=Head->next;
             Behind=Behind->next;
        }

        return Behind;
    }
};

int main()
{
    findKth findK;
    ListNode *p=new ListNode(1);
    ListNode *head=p;
    ListNode *result;

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
    result=findK.FindKthToTail(head,3);

    PrintList(result);

    return 0;
}
