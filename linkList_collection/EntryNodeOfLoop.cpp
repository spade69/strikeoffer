struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* EntryNodeOfLoop(ListNode *pHead)
{
    if(pHead==NULL||pHead->next==NULL)
        return NULL;
    ListNode *front=pHead;
    ListNode *behind=pHead->next;
    while(behind){
        front->next=NULL;
        front=behind;
        behind=behind->next;
    }
    return front;
}
