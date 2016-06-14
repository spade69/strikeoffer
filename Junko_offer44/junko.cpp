#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsContinuous(vector<int> numbers)
{
    int len=numbers.size();
    if(numbers.empty()||len!=5)//!=5 or <1?
        return false;

    int count=0;
    int m=0;

    sort(numbers.begin(),numbers.end());

  //if((numbers[len-1]-numbers[0])>4)  6-0 >6 ,must consider the two 0 affect
    //    return false;

    for(int i=0;i<len;i++){
        if(numbers[i]==0)
            count++;
    }

    int small=count;//0 must sort at front,then we only need to compare those after them
    int big=small+1;
    while(big<len)
    {
        if(numbers[small]==numbers[big])
            return false;

            m+=numbers[big]-numbers[small]-1;

        small=big;
        big++;
    }

    return (m>count)?false:true;
}

int main(){
    int a[5]={0,3,2,6,4};
    vector<int> vec(a,a+5);
    bool result;
    result=IsContinuous(vec);
    cout<<result<<endl;
    return 0;
}
