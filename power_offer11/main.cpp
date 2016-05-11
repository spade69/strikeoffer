#include <iostream>

using namespace std;

/*?************
Function：实现乘方运算，不考虑大数问题

输入：double 基本的底数， exponent 指数
Author:Jason
Version:1.0
Date:2016/04/26

stupid 解法：
for(int i=1;i<=exponent;++i)
{
    result*=base;
}
没考虑到负数or0的情况

边界：
********/
bool g_InvalidInput=false;

bool equalx(double num1,double num2)
{
    if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
        return true;
    else
        return false;
}
//version 效率不够高的版本
/*
double PowerWithUnsignedExponent(double base, int exponent)
{
    double result=1.0;//when exponent == 0 ,it directly return 1
    for(int i=1;i<=exponent;++i)
        result*=base;
    return result;
}*/

//高效版本：
double PowerWithUnsignedExponent(double base, int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return base;//不管是0 还是负数、

    double result=PowerWithUnsignedExponent(base,exponent>>1);//when exponent == 0 ,it directly return 1
    result*=result; ///

    if(exponent&0x1==1)//奇数就要多乘一个base！
        result*=base;

    return result;
}


double Power(double base, int exponent) {
    g_InvalidInput=false;
    //0 不能取倒数！
    if(equalx(base,0.0)&&exponent<0)
    {
        g_InvalidInput=true;
        return 0.0;
    }
    //求绝对值解决,指数是负的情况。 但是底数无关影响
    unsigned int absExponent=(unsigned int)(exponent);
    //强制类型转换，会完全改变这个值吗？
    if(exponent<0)
        absExponent=(unsigned int)(-exponent);
//此处把负指数or正指数都计算了，负的取绝对值
    double result=PowerWithUnsignedExponent(base,absExponent);
//如果是负的就取一次倒数就行~
    if(exponent<0)
        result=1.0/result;

    return result;
}

int main()
{
    cout << "Hello world!" << endl;
    double result;
    result=Power(-5,-13);
    cout<<result<<endl;
    return 0;
}
