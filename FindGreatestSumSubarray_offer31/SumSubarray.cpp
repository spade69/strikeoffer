#include<iostream>
#include<vector>
using namespace std;

/***************
 *要懂得转变思路
 一般判断最大值，都应该将max初始化为一个很小的值例如int的最小值0x80000000

 找出一个数组的连续的子数组的最大值
 必须是if(max<sum) 这种判断才对
 因为你更新的是max。每次sum都会增加,不增加就不更新

Date:2016/5/28
Author:Jason
 * ***************/
int FindGreatestSumOfSubArray(vector<int>& array){

    if(array.empty())
    {
        cout<<"Your array is empty!"<<endl;
        return 0;
    }

    vector<int>::iterator iter=array.begin();
    int sum=0;
    int tmp=0;
    int max=0x80000000;//int型的最小值：-2147483648
    for(;iter!=array.end();iter++){
        if(sum<=0)
        {

            sum=*iter;


        }

        else{
        sum+=*iter;
        }

        if(sum>max){
            max=sum;
        }

    }//for
    return max;
}



int main(){
    int a[8]={1,-2,3,10,-4,7,2,-5};
    int b[5]={-2,-8,-1,-5,-9};
    vector<int> arr(b,b+5);
  //  vector<int> arr(a,a+8);

    int max=0;
    //max=FindGreatestSumOfSubArray(arr);
    max=XFindGreatSubArray(arr);
    cout<<"max:"<<max<<endl;
    return 0;
}
