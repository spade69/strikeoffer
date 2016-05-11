#include"ListNode.h"
using namespace std;


//这里有一个假设，就是删除的节点一定在链表当中。O(1)时间限制，所以
//我们不能遍历整个链表去确定是否在。也就是调用者要确保节点在链表当中
ListNode* deleteNode(ListNode* pHead,ListNode* pToBeDeleted)
{
    if(!pHead||!pToBeDeleted)
    {
        return NULL;
    }
    //要删除的不是尾节点
    if(pToBeDeleted->next!=NULL)
    {
        ListNode* pNext=pToBeDeleted->next;
        pToBeDeleted->val=pNext->val;
        pToBeDeleted->next=pNext->next;

        delete pNext;
        pNext=NULL;
    }
    //链表中有多个节点，删除尾节点、
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

    ListNode* first = new ListNode(-1);//设置一个trick

    first->next = pHead;

    ListNode *p = pHead;

    ListNode* last =first;//last 和first是同一个指针了

    while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val)
            {
                int val = p->val;//val代表相同的值
                while (p != NULL&&p->val == val)
                    p = p->next;

                last->next = p;
                cout<<"last->next"<<last->next->val<<endl;;
                 cout<<"first->next"<<first->next->val<<endl;;
            }
            else
            {
                last = p;//此处改变了 last指针指向的地址了。当last改变后，对last->next操作将
                //不再影响first->next .所以只有在一开始first last都指向同一个地址的时候，对last->next
                //的改变是跟first->next影响一样。
                p = p->next;
            }
        }
        return first->next;
}

/**************
//程序有缺陷

ListNode* deleteDuplication(ListNode* pHead)
{
    int times=0;
    int length=0;
    int flag=0;
    ListNode *oHead=pHead;
    ListNode *p=pHead;
    ListNode *pBegin=pHead;
    ListNode *pEnd=pHead;
    //链表为空
    if(!pHead)
    {
        return NULL;
    }

    //只遍历到尾节点的前一个
    while(p->next)
    {
        //2->2->2 头部开始相同的
        if(pHead->val==pHead->next->val)
           {

            pBegin=pHead;
            flag=1;
           }

        if(p->val<p->next->val)
        {
            //只在还没计数之前赋值，一旦开始计数就不赋值了，这样也不需要比较
            //p->next->next了。
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
            //删除，不是插入，不需要管后面的元素
            pBegin->next=pEnd;
            times=0;
            if(pBegin==pHead&&flag==1) //01123也符合， pBegin==pHead，
            //但是这个是为了去掉2->2->2->3->4的去哦们回来
                pHead=pEnd;
        }

        length++;
        p=p->next;
    }
    //循环完整个链表， 1->2->3->4->4->4 尾部相同的情况就肯定是end<begin!
    if(pEnd<pBegin&&times>0)
    {
        pBegin->next=NULL;
        times=0;
    }

    //现在的pHead是
    //删除整个链表，如果是 2->2->2->2->2这种
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
