#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class IsPop{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV){
        bool bPossible=false;
        vector<int>::iterator iter1=pushV.begin();
        vector<int>::iterator iter2=popV.begin();

        if(!pushV.empty()&&!popV.empty())
        {
            while(iter2!=popV.end())
            {
                while(stackData.empty()||stackData.top()!=*iter2)
                {
                    if(iter1==pushV.end())
                        break;
                    stackData.push(*iter1);
                    iter1++;
                }

                if(stackData.top()!=*iter2)
                    break;
                stackData.pop();
                iter2++;
            }

            if(stackData.empty()&&iter2==popV.end())
                bPossible=true;
        }
	    return bPossible;
    }
private:
    stack<int> stackData;

};

int main()
{
    bool result=false;
    IsPop pOrder;
    int a[5]={1,2,3,4,5};
    int b[5]={4,5,3,1,2};
    vector<int> v1(a,a+5);
    vector<int> v2(b,b+5);
    result=pOrder.IsPopOrder(v1,v2);
    cout<<result<<endl;
    return 0;
}
