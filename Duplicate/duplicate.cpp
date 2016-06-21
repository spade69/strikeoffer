#include<iostream>
using namespace std;
#define MAX 999999
//Parameters:
//  numbers: an array of integers
//  length: the length of array numbers
//  duplication:the duplicated number in the array number
//Return value:
//true if the input is valid, and there are some duplication otherwise false
//Author: Jason
//Date: 2016/06/21

//numbers[] i from 0-> n-1. Positive number
bool duplicate(int numbers[],int length,int* duplication)
{
    if(length<1)
        return false;
    int hash[MAX]={0};//less than MAX,because array must assign memory first
    for(int i=0;i<length;i++)
    {
        if(numbers[i]>=length||numbers[i]<0)
        {
            *duplication=-1;
            return false;
        }
        hash[numbers[i]]++;
    }

    for(int i=0;i<length;i++)
    {
        if(hash[i]>1)
        {
            *duplication=i;//i represent the numbers[]'s value
            break;
        }
    }

    return true;

}

//method x
bool duplicateX(int numbers[],int length,int *duplication)
{
    for(int i=0;i<length;i++){

        int j=numbers[i]%length;
        numbers[j]+=length;
        if(numbers[j]>=(2*length)){

            *duplication=numbers[j]%length;
            return true;
        }
        return false;
    }
}

int main()
{
    //int numbers[7]={2,3,1,0,2,5,3};
    int numbers[5]={2,1,3,0,4};
    int len=5;
    int* duplication=new int;
    bool result=false;
    result=duplicate(numbers,len,duplication);
    if(result)
    cout<<*duplication<<endl;
    cout<<result;
    return 0;
}
