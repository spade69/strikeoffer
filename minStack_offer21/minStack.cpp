#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
class minExtraction{

    public:
   //as for m_min:judge the size().if it's empty or top value bigger than the then push
 //as for m_data , push with no doubt.
    void push(int value){
        m_data.push(value);
        if(m_min.size()==0||value<m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
//pop two of them,because one min correspongding to one .1<-->1
    void pop(){
        assert(m_data.size()>0&&m_min.size()>0);
        m_data.pop();
        m_min.pop();
    }
//just return m_data
    int top(){
        assert(m_data.size()>0&&m_min.size()>0);
        return m_data.top();

    }
// min value
    int min(){
        assert(m_data.size()>0&&m_min.size()>0);
        return m_min.top();

    }

private:
    stack<int> m_data;
    stack<int> m_min;
};

int main()
{
    minExtraction stackx;
    int minx;
    stackx.push(3);
    stackx.push(4);
    stackx.push(0);
    stackx.pop();
    minx=stackx.min();
    cout<<minx<<endl;

    return 0;
}
