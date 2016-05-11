#include <iostream>

using namespace std;

/*?************
Function��ʵ�ֳ˷����㣬�����Ǵ�������

���룺double �����ĵ����� exponent ָ��
Author:Jason
Version:1.0
Date:2016/04/26

stupid �ⷨ��
for(int i=1;i<=exponent;++i)
{
    result*=base;
}
û���ǵ�����or0�����

�߽磺
********/
bool g_InvalidInput=false;

bool equalx(double num1,double num2)
{
    if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
        return true;
    else
        return false;
}
//version Ч�ʲ����ߵİ汾
/*
double PowerWithUnsignedExponent(double base, int exponent)
{
    double result=1.0;//when exponent == 0 ,it directly return 1
    for(int i=1;i<=exponent;++i)
        result*=base;
    return result;
}*/

//��Ч�汾��
double PowerWithUnsignedExponent(double base, int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return base;//������0 ���Ǹ�����

    double result=PowerWithUnsignedExponent(base,exponent>>1);//when exponent == 0 ,it directly return 1
    result*=result; ///

    if(exponent&0x1==1)//������Ҫ���һ��base��
        result*=base;

    return result;
}


double Power(double base, int exponent) {
    g_InvalidInput=false;
    //0 ����ȡ������
    if(equalx(base,0.0)&&exponent<0)
    {
        g_InvalidInput=true;
        return 0.0;
    }
    //�����ֵ���,ָ���Ǹ�������� ���ǵ����޹�Ӱ��
    unsigned int absExponent=(unsigned int)(exponent);
    //ǿ������ת��������ȫ�ı����ֵ��
    if(exponent<0)
        absExponent=(unsigned int)(-exponent);
//�˴��Ѹ�ָ��or��ָ���������ˣ�����ȡ����ֵ
    double result=PowerWithUnsignedExponent(base,absExponent);
//����Ǹ��ľ�ȡһ�ε�������~
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
