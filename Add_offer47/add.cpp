#include<iostream>
using namespace std;

int Add(int num1,int num2)
{
    int carry=num2;
    int result;
    int tmp=num1;
    bool judge=true;
    while(judge!=0){
        //int tmp;
        result=tmp^carry;
        carry=(tmp&carry)<<1;
        judge=tmp&carry;
        tmp=result;
    }
    result=result^carry;
    return result;
}

int Addx(int num1,int num2)
{
    int sum,carry;
    do
    {
        sum=num1+num2;
        carry=(num1&num2)<<1;
        num1=sum;
        num2=carry;
    }
    while(num2!=0);

    return num1;
}

int main(){

    return 0;
}
