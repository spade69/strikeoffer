#include<iostream>
#include<list>
using namespace std;


/********
 *Two method
 one using loop list
 another from mathmatic
 * Author Jason
 * Date 2016/6/17
 * ********************/

int LastRemaining_list(unsigned int n,unsigned int m)
{
    if(n<1||m<1)
        return -1;
    list<int> q;
    for(int i=0;i<n;i++){
        q.push_back(i);
    }
    list<int>::iterator iter=q.begin();
    while(q.size()>1){
        for(int i=1;i<m;++i)
        {
            iter++;
            if(iter==q.end())
                iter=q.begin();
        }

        list<int>::iterator next=iter+1;
        //when next is end,then next should point to begin(),because it's  a loop
        if(next==q.end())
            next=q.begin();
        q.erase(iter);//pos can be iterator
        iter=next;
    }

}

int LastRemaining_Solution(unsigned int n,unsigned int m)
{

    if(n<1||m<1)
        return -1;
    int last=0;
    //link list loop instead of recurrsive
    //f(n,m)=(f(n-1,m)+m)%i
    //so i must from 2 to n,when you get 2,then you get 3
    //etc... until n
    for(int i=2;i<=n;i++)
    {
        last=(last+m)%i;
    }
    return last;
}

int main(){
    return 0;
}
