#include<iostream>

using namespace std;

/*********
 *Ugly number
Date: 2016/6/1
Author:Jason
 *
 *Method 1:
 * clear
 but not smart,doesn't consider
 about the efficency

 * *********************/
bool IsUgly(int number){
    while(number%2==0)
        number=number/2;
    while(number%3==0)
        number=number/3;
    while(number%5==0)
        number=number/5;

    return (number==1)?true:false;
}

int GetUgly1(int index){
    //边界，never forget！
    if(index<=0)
        return 0;
    int uglyfound=0;
    int num=0;
        while(uglyfound<index){
                num++;
            if(IsUgly(num))
                uglyfound++;

        }
        return num;

}

/*
 *Method 2:
 * clear
 *
 * Using array store the sorted ugly number
 * Generating this array :1 2 3 2*2 5 3*2 ...
 * So every ugly num must be the
 * *********************/
int Min(int num1,int num2,int num3){

    int min=0;
    min=(num1<num2)?num1:num2;

    min=(min<num3)?min:num3;

    return min;
}

/***********
 *You can not avoid the index,uglynumber's index increase must step by step
 but we march using comparison between 2*
 * *****************/
int XgetUgly(int index){
    if(index<=0)
        return 0;
    int *UglyNumbers=new int[index];
    UglyNumbers[0]=1;//first element is 1
    int nextUglyIndex=1;

    int *pMultiply2=UglyNumbers;
    int *pMultiply3=UglyNumbers;
    int *pMultiply5=UglyNumbers;

    while(nextUglyIndex<index){

        int min=Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
       //because we compare between *p2 *p3 *p5 so it's possible
       //we step in more than you can imagine,10 20 50? it's possible

        UglyNumbers[nextUglyIndex]=min;//we only step in min

        while(*pMultiply2*2<=UglyNumbers[nextUglyIndex])
            ++pMultiply2;
        while(*pMultiply3*3<=UglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5*5<=UglyNumbers[nextUglyIndex])
            ++pMultiply5;

        ++nextUglyIndex;

    }
  int ugly=UglyNumbers[nextUglyIndex-1];
        delete UglyNumbers;//release the memory
        return ugly;

}


int main()
{

    return 0;
}
