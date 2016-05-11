#include <iostream>
#include<vector>

using namespace std;
/*?************
Function：1.实现调整数组顺序，使得奇数位于偶数前面~
2.并保证奇数和奇数，偶数和偶数之间的相对位置不变。

输入：一个vector数组
输出：一个vector数组，按要求排好序
返回：void

Author:Jason
Version:1.0
Date:2016/05/08

解法1： 遍历，遇到一个偶数就把所有后面的数往前移动一位，然后在最后放入这个偶数
解法2： 遇到偶数在奇数前面 就交换

扩展性： 如果是 负数 在前面 非负数在后面。 或者被3整除的在前面，不能的在后面
要改变的是判断标准！

逻辑框架不用动，解耦! 提高代码重用性
********/
class Solution {
public:
    void reOrderArray(vector<int> &arrayx) {
        vector<int>::size_type length=arrayx.size();
        if(arrayx.empty()||arrayx.size()==0)//边界条件判断
                return;
        vector<int>::iterator pBegin=arrayx.begin();
        vector<int>::iterator p=arrayx.begin();
        vector<int> storex;
        vector<int> storey;


        int countx=0;

        while(pBegin!=arrayx.end())
        {
            //向后移动pBegin 直到指向奇数,storex 存奇数
            if((*pBegin)&0x1!=0)
                storex.push_back(*pBegin);

            //向前移动pEnd，直到指向偶数，storey存偶数
             else
                storey.push_back(*pBegin);


            pBegin++;
        }

        vector<int>::iterator p1=storex.begin();
        vector<int>::iterator p2=storey.begin();


        while(p!=arrayx.end())
        {
            while(p1!=storex.end())
            {
                *p=*p1;
                p++;
                p1++;
            }

            while(p2!=storey.end())
            {
                *p=*p2;
                p++;
                p2++;
            }

        }
    }
};

/*
class Solution {
public:

    void reOrderArray(vector<int> &arrayx);
    void reOrderX(vector<int> &arrayx,bool (*func)(int))
    {
        vector<int>::size_type length=arrayx.size();
        if(arrayx.empty()||arrayx.size()==0)//边界条件判断
                return;
        vector<int>::iterator pBegin=arrayx.begin();
        vector<int>::iterator pEnd=arrayx.end();

        while(pBegin<pEnd)
        {
            //向后移动pBegin 直到指向偶数
            while(pBegin<pEnd&&!func(*pBegin))
                pBegin++;

            //向前移动pEnd，直到指向奇数
            while(pBegin<pEnd&&func(*pBegin))
                pEnd--;
            //如果偶数在奇数前面,就交换
            if(pBegin<pEnd)
            {
                int temp=*pBegin;
                *pBegin=*pEnd;
                *pEnd=temp;
            }
        }
    }

    bool isEven(int n)
    {
        return (n&1)==0;
    }


};

//typedef bool (Solution::*funz)(int);

void Solution::reOrderArray(vector<int> &arrayx)
{
    //在类作用域里面了
        reOrderX(arrayx,isEven);// 函数名作为参数，函数名是
}
*/

int main()
{
 //   cout << "Hello world!" << endl;
    int a[]={1,2,3,4,5,6};
    vector<int> v1(a,a+6);
    vector<int>::iterator p=v1.begin();

    Solution reOrder;//=new Solution(); new 返回的是一个指向对象的指针！
   reOrder.reOrderArray(v1);
    while(p!=v1.end())
    {
        cout<<*p<<endl;
        p++;
    }

    return 0;
}
