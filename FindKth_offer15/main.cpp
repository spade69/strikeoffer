#include <iostream>

using namespace std;
/*?************
Function：输入

输入：一个链表


输出：该链表的倒数第k个节点。
返回：void

Author:Jason
Version:1.0
Date:2016/05/08

边界： 1.判断节点数目 n<k?
2. 链表是否为空
3. k不能为0，没有倒数第0个

解法1： 遍历链表两次， 第一次先得到链表的长度n，
然后根据n， n-k+1 就是我们要找的倒数第k个节点！
解法2： 只需遍历一次，使用两个指针(or迭代器)，第一次指针遍历到第k个位置时，
然后才让第2个指针开始遍历，两者同时开始遍历直到
 P1 : k-1  P2: n-(k-1) !
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

class findKth {
public:



    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

        if(pListHead==NULL||k==0)//链表不能为空，其次k不能为0
            return NULL;

        ListNode* Head=pListHead;
        ListNode* Behind=NULL;


        for(int i=0;i<k-1;i++)
        {
            if(Head->next!=NULL) //不能
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
