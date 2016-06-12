#include<iostream>
#include<vector>
using namespace std;

    /**********
    divide into two subarray
    acrroding to the first bit that is 1.
    Final result equals to this two different num1^num2
    Author Jason
    Date:2016/6/11
    ****************/
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if(data.empty()||data.size()<2)
            return;
        int len=data.size();
        int index=0;
        int result=data[0];
        for(int i=1;i<len;i++){
            result=data[i]^result;
        }
        //find the index of 1
        while(((result&1)==0)&&index<8*sizeof(int)){
            result=result>>1;
            index++;
        }

        *num1=0,*num2=0;
        for(int j=0;j<len;j++){
            int tmp=data[j]>>index;
            if(tmp&1){
                *num1^=data[j];
            }
            else{
                *num2^=data[j];
            }
        }
    }

int main(){

    return 0;
}

