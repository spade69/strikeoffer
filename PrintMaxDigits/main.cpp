#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;
/*?************
Function：实现打印1到最大的n位数
考虑大数问题
陷阱1： 大数溢出问题
陷阱2： 什么时候判断到了99..99最大的数，应该是第一个字符进位的时候
陷阱3： 打印前面不能有0，即从非0开始打印

输入：n 位
Author:Jason
Version:1.0
Date:2016/04/26

stupid 解法：
void PrintMaxDig(int n)
{
    int number=1;
    int i=0;
    while(i++<n)
    {
        number*=10;
    }

    for(i=1;i<number;i++)
        printf("%d\t",i);
        //cout<<i<<" ";
}
没有考虑到 溢出的情况
还有边界条件。
********/


bool Increment(char* number);
void PrintNumber(char* number);
void PrintMaxDig(int n)
{
    if(n<=0)
        return;

    char *number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0'; //作为字符串的结束

    while(!Increment(number))
    {
        PrintNumber(number);
    }
    delete []number;
}

bool Increment(char* number)
{
    bool isOverflow=false;
    int nTakeOver=0;
    int nLength=strlen(number);
    //字符串 number[0...length-1] = "123456"
    //左边是高位！
    for(int i=nLength-1;i>=0;i--)
    {
        //取实际的数值
        int nSum=number[i]-'0'+nTakeOver;//有进位的话，此处会多加1.
        if(i==nLength-1)
            nSum++;// 刚进入for循环，让

        if(nSum>=10) //如果刚好是9，那就要进位了
        {
            if(i==0) //循环到了0，就是到了最大位数了。
            isOverflow=true;
            else  //否则继续循环下去。
            {
                nSum-=10;
                nTakeOver=1; //进位~
                number[i]='0'+nSum; //对number的修改~
            }
        }
        else
        {
            number[i]='0'+nSum;
            break;
        }

    }
    return isOverflow;
}

void PrintNumber(char* number)
{
    bool isBeginning0=true;
    int nLength=strlen(number);

    for(int i=0;i<nLength;i++)
    {
        //false才打印，就是满足！='0'
        if(isBeginning0&&(number[i]!='0'))
            isBeginning0=false;
        if(!isBeginning0)
            printf("%c",number[i]);
    }
    printf(" ");
}


/*?************
Function：实现打印1到最大的n位数 全排列解法
考虑大数问题
陷阱1： 大数溢出问题
陷阱2： 什么时候判断到了99..99最大的数，应该是第一个字符进位的时候
陷阱3： 打印前面不能有0，即从非0开始打印

输入：n 位
Author:Jason
Version:2.0
Date:2016/04/26

 全排列解法：不需要模拟加法
 n位所有十进制数就是n个从0到9的全排列
 只是打印时，数字排在前面的0我们不打印！

 递归结束条件： 已设置了数字的最后一位.
********/
void PrintToMaxDitgitsRecursively(char* number,int length,int index)
{
    //递归会把前面算出来的作为基础，就是说PrintToMaxDitgitsRecursively(number,4,2)
    //还是会用到PrintToMaxDitgitsRecursively(number,4,3)的结果
    //
    if(index==length-1) //先递归到index==length-1 ，然后出栈，逐个打印
    {
        PrintNumber(number);
        return;
    }

    for(int i=0;i<10;++i)
    {
        number[index+1]=i+'0'; //只能是0~9,在递归执行过程中改变
        //for循环打印所有的number[1...length-1] 打印后面这些位
        //index满足length-1， 就会打印这个循环。然后return，发现length不足，index继续++， 然后return，又要到满足index==length-1才打印
        PrintToMaxDitgitsRecursively(number,length,index+1);//递归实现
    }
}

/*******************
程序总是从0开始加到99..99
所以重要的只是判断是否到了最大的那个位数
前面的
*********************/
void PrintToMaxDitgits(int n)
{
    if(n<=0)
    return;

    char* number=new char[n+1];
    number[n]='\0';

    for(int i=0;i<10;i++)
    {
        number[0]=i+'0'; //改变的是第一位，即最高位的值 从0~9
        //假设n=4 即这个循环是 0999 ,1999,2999,3999...9999 这个最高位
        PrintToMaxDitgitsRecursively(number,n,0);
    }
    delete[] number;
}



//解法 使用枚举新类型

typedef enum
{
t0=0,
t1=1,
t2=2,
t3=3,
t4=4,
t5=5,
t6=6,
t7=7,
t8=8,
t9=9
}t_num;

/*
typedef enum
{
    a,
    b,
    c
}shit;*/

//测试递归
void print_test(int length,int index)
{

    if(index==length-1)
    {
        cout<<"Meet "<<endl;
        return;
    }

    for(int i=0;i<5;++i)
    {

        cout<<i<<" ";
        print_test(length,index+1);
    }
}

int main()
{
    t_num a=t0;

    cout<<a<<" "<<sizeof(a)<<endl;
   //PrintMaxDig(5);
  //PrintToMaxDitgits(4);
    print_test(4,0);
    return 0;
}
