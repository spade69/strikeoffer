#include<iostream>
#include<vector>
using namespace std;
/*******************

Input: an array contains group of numbers
Output:
Return: the num of inverse-pair.

Description:
We need to find the num of inverse-pair.
For example: (2,1) (3,2) and also we should know that
the inverse pair doesn't require two number to be ajacent

First: divide into serveral group. eg: 8-->4-->2-->1
Until only one number in one group.
Second: We begin to merge them. Meanwhile,sort the inverpair that were considered.
Actually:It's a merge sort~

Author: Jason
Date: 2016/06/05
**********************/
int InversePairsCore(int* data,int* copy,int start,int end){
    if(start==end)
    {
        copy[start]=data[start];
        return 0;
    }
    int center=(end-start)/2;
//recursive ,notice data and copy inverse.
//we divide into two part to calculate
    int left=InversePairsCore(copy,data,start,start+center);
    int right=InversePairsCore(copy,data,start+center+1,end);

    // i initialize as the last index of first half
    int i=start+center;
    //j  initialize as the last index of second half
    int j=end;
    int indexCopy=end;
    int count=0;
    //merge:
    while(i>=start&&j>=start+center+1)
    {
        if(data[i]>data[j])
        {
            copy[indexCopy--]=data[i--];
            count+=j-start-center;
        }
        else
        {
            copy[indexCopy--]=data[j--];
        }
    }
    //copy the rest of first half
    for(;i>=start;i--)
    {
        copy[indexCopy--]=data[i];
    }
    //copy the rest of second half
    for(;j>=start+center+1;--j)
    {
        copy[indexCopy--]=data[j];
    }

    return left+right+count;
}

int InversePairs(vector<int> data){
    if(data.empty())
    {
        return 0;
    }
    int len=data.size();
    int* copy=new int[len];
    int* datax=new int[len];
    for(int i=0;i<len;i++)
    {
        datax[i]=data[i];
        copy[i]=data[i];
    }

    int count=InversePairsCore(datax,copy,0,len-1);
    delete[] copy;
    return count;
}


int main(){
    int a[4]={7,5,6,4};
    vector<int> vec(a,a+4);
    int num;
    num=InversePairs(vec);
    cout<<num<<endl;
    return 0;
}
