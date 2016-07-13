#include<iostream>
#include<queue>
using namespace std;
/*
 * Heap
 *
 * Date 2016/7/13
From nowcode

 * */

priority_queue<int,vector<int>,less<int> > p;
priority_queue<int,vector<int>,greater<int> > q;

void Insert(int num){
    if(p.empty()||num<=p.top())
    {
        p.push(num);
        cout<<"p:"<<p.top()<<endl;
    }
    else {
        q.push(num);
        cout<<"q:"<<q.top()<<endl;
    }
    if(p.size()==q.size()+2) {
        q.push(p.top());
        p.pop();

        cout<<"p.top()"<<p.top()<<endl;
    }
    if(p.size()+1==q.size()) {
        p.push(q.top());
        q.pop();

        cout<<"q.top()"<<q.top()<<endl;
    }
}

double GetMedian(){
    return p.size()==q.size()?(p.top()+q.top())/2.0:p.top();
}

int main(){
    //p.push(2);
    //p.push(3);
    //using Insert to enqueue,and it will decide which heap to store the data.
    Insert(6);//we should use insert to push ,because it's a data stream!
    Insert(5);
    Insert(3);
    Insert(4);
    Insert(7);
    double result=GetMedian();
    cout<<"result: "<<result<<endl;
    return 0;
}


