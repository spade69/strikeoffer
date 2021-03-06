#include<iostream>
#include<stdio.h>
using namespace std;

/**************
 *Count the times of "1"
 from 1~N
 Two method :
1. Alogorithm: judge n%10==1 ,when n>=10
    otherwise n=n/10. and loop from 1~N
O(n*logn) Because we need to judge every bit of this number
2. Algorithm:using recursion. Because we find the law of the occurence of
'1'.
 *
 * Date: 2016/5/29
 * Author: Jason
 * *****************/

int mNumberof1(int n){

    int number=0;
    for(int i=1;i<=n;i++){
        number+=mCoreNumberof1(i);
    }
    return number;
}

int mCoreNumberof1(int n){
    int number=0;
    while(n){
        if(n%10==1)
            number++;
        n=n/10;
    }
    return number;
}
i
/*******Method 2****
 *Using sprintf convert a int to char[]
 * ************/

int NumberOf1Between1AndN(int n){
    if(n<=0)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);

    return NumberOf1(strN);
}

int PowerBase10(int n){
    int reuslt=1;
    for(int i=0;i<n;++i){
        result*=10;
    }
    return result;
}


//去掉最高位做递归，递归的次数和位数相同。
//
int NumberOf1(const char* strN){
    if(!strN||*strN<'0'||*strN>'9'||*strN=='\0')
        return 0;
    int first=*strN-'0';
    unsigned int length=static_cast<unsigned int>(strlen(strN));

    if(length==1&&first==0)
        return 0;
    if(length==1&&first>0)
        return 1;
    //assume strN "21345"
    //numFirstDigit 10000~19999 的第一个位中的数目
    int numFirstDigit=0;
    if(first>1)
        numFirstDigit=PowerBase10(length-1);
    else if(first==1)
        numFirstDigit=atoi(strN+1)+1;

    //Numbers of 1346~21345
    //1xxxx 2xxxx出现一样的会。4位时：1xxx x1xx xx1x xxx1 (xxx<==> 10^3)
    int numOtherDigits=first*(length-1)*PowerBase10(length-2);
    //Numbers of 1~1345
    int numRecursive=NumberOf1(strN+1);

    return numFirstDigit+numOtherDigits+numRecursive;
}

/*************
 *Leetcode easiest method 3:
 n= [a b]

 For example, we focus on 百分位
1) >=2 : 31456 (a/10+1)*100
2) ==1 : 31156 (a%10+1)*100+(b+1)
3) ==0 :30156  a/10
a/10 <==> (a+8)/10
当百分位为2，补8会产生进位位，效果等同于(a/10+1)
 * *****************/

int countDigitOne(int n){
    int ones=0;
    for(int m=1;m<=n;m*=10){
        int a=n/m,b=n%m;
        ones+=(a+8)/10*m+(a%10==1)*(b+1)
    }
    return ones;
}

int main(){

    return 0;
}
