#include"ListNode.h"
using namespace std;


//������һ�����裬����ɾ���Ľڵ�һ���������С�O(1)ʱ�����ƣ�����
//���ǲ��ܱ�����������ȥȷ���Ƿ��ڡ�Ҳ���ǵ�����Ҫȷ���ڵ���������
ListNode* deleteNode(ListNode* pHead,ListNode* pToBeDeleted)
{
    if(!pHead||!pToBeDeleted)
    {
        return NULL;
    }
    //Ҫɾ���Ĳ���β�ڵ�
    if(pToBeDeleted->next!=NULL)
    {
        ListNode* pNext=pToBeDeleted->next;
        pToBeDeleted->val=pNext->val;
        pToBeDeleted->next=pNext->next;

        delete pNext;
        pNext=NULL;
    }
    //�������ж���ڵ㣬ɾ��β�ڵ㡢
    else
    {
        ListNode* pNode=pHead;
        while(pNode->next!=pToBeDeleted)
        {
            pNode=pNode->next;
        }

        pNode->next=NULL;
        delete pToBeDeleted;
        pToBeDeleted=NULL;
    }
}

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

ListNode* deleteDuplication(ListNode* pHead)
{
    if(!pHead)
    {
        return NULL;
    }

    ListNode* first = new ListNode(-1);//����һ��trick

    first->next = pHead;

    ListNode *p = pHead;

    ListNode* last =first;//last ��first��ͬһ��ָ����

    while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val)
            {
                int val = p->val;//val������ͬ��ֵ
                while (p != NULL&&p->val == val)
                    p = p->next;

                last->next = p;
                cout<<"last->next"<<last->next->val<<endl;;
                 cout<<"first->next"<<first->next->val<<endl;;
            }
            else
            {
                last = p;//�˴��ı��� lastָ��ָ��ĵ�ַ�ˡ���last�ı�󣬶�last->next������
                //����Ӱ��first->next .����ֻ����һ��ʼfirst last��ָ��ͬһ����ַ��ʱ�򣬶�last->next
                //�ĸı��Ǹ�first->nextӰ��һ����
                p = p->next;
            }
        }
        return first->next;
}

/**************
//������ȱ��

ListNode* deleteDuplication(ListNode* pHead)
{
    int times=0;
    int length=0;
    int flag=0;
    ListNode *oHead=pHead;
    ListNode *p=pHead;
    ListNode *pBegin=pHead;
    ListNode *pEnd=pHead;
    //����Ϊ��
    if(!pHead)
    {
        return NULL;
    }

    //ֻ������β�ڵ��ǰһ��
    while(p->next)
    {
        //2->2->2 ͷ����ʼ��ͬ��
        if(pHead->val==pHead->next->val)
           {

            pBegin=pHead;
            flag=1;
           }

        if(p->val<p->next->val)
        {
            //ֻ�ڻ�û����֮ǰ��ֵ��һ����ʼ�����Ͳ���ֵ�ˣ�����Ҳ����Ҫ�Ƚ�
            //p->next->next�ˡ�
            if(times==0)
            pBegin=p;
        }
        if(p->val==p->next->val)
        {
            times++;

        }
        //normal
        if(times>0&&(p->val!=p->next->val))
        {

            pEnd=p->next;
            //ListNode *tmp=pBegin;
            //ɾ�������ǲ��룬����Ҫ�ܺ����Ԫ��
            pBegin->next=pEnd;
            times=0;
            if(pBegin==pHead&&flag==1) //01123Ҳ���ϣ� pBegin==pHead��
            //���������Ϊ��ȥ��2->2->2->3->4��ȥŶ�ǻ���
                pHead=pEnd;
        }

        length++;
        p=p->next;
    }
    //ѭ������������ 1->2->3->4->4->4 β����ͬ������Ϳ϶���end<begin!
    if(pEnd<pBegin&&times>0)
    {
        pBegin->next=NULL;
        times=0;
    }

    //���ڵ�pHead��
    //ɾ��������������� 2->2->2->2->2����
    if((times>0)&&(pHead->val==pEnd->val))
    {

        delete pHead;
        pHead=NULL;
        //return pHead;
    }

   // cout<<"begin and end: "<<endl;
    //cout<<pBegin->val<<endl;
    //cout<<pEnd->val<<endl;
    return pHead;
}*/
