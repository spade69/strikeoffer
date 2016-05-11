#include <iostream>
#include<vector>

using namespace std;
/*?************
Function��1.ʵ�ֵ�������˳��ʹ������λ��ż��ǰ��~
2.����֤������������ż����ż��֮������λ�ò��䡣

���룺һ��vector����
�����һ��vector���飬��Ҫ���ź���
���أ�void

Author:Jason
Version:1.0
Date:2016/05/08

�ⷨ1�� ����������һ��ż���Ͱ����к��������ǰ�ƶ�һλ��Ȼ�������������ż��
�ⷨ2�� ����ż��������ǰ�� �ͽ���

��չ�ԣ� ����� ���� ��ǰ�� �Ǹ����ں��档 ���߱�3��������ǰ�棬���ܵ��ں���
Ҫ�ı�����жϱ�׼��

�߼���ܲ��ö�������! ��ߴ���������
********/
class Solution {
public:
    void reOrderArray(vector<int> &arrayx) {
        vector<int>::size_type length=arrayx.size();
        if(arrayx.empty()||arrayx.size()==0)//�߽������ж�
                return;
        vector<int>::iterator pBegin=arrayx.begin();
        vector<int>::iterator p=arrayx.begin();
        vector<int> storex;
        vector<int> storey;


        int countx=0;

        while(pBegin!=arrayx.end())
        {
            //����ƶ�pBegin ֱ��ָ������,storex ������
            if((*pBegin)&0x1!=0)
                storex.push_back(*pBegin);

            //��ǰ�ƶ�pEnd��ֱ��ָ��ż����storey��ż��
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
        if(arrayx.empty()||arrayx.size()==0)//�߽������ж�
                return;
        vector<int>::iterator pBegin=arrayx.begin();
        vector<int>::iterator pEnd=arrayx.end();

        while(pBegin<pEnd)
        {
            //����ƶ�pBegin ֱ��ָ��ż��
            while(pBegin<pEnd&&!func(*pBegin))
                pBegin++;

            //��ǰ�ƶ�pEnd��ֱ��ָ������
            while(pBegin<pEnd&&func(*pBegin))
                pEnd--;
            //���ż��������ǰ��,�ͽ���
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
    //����������������
        reOrderX(arrayx,isEven);// ��������Ϊ��������������
}
*/

int main()
{
 //   cout << "Hello world!" << endl;
    int a[]={1,2,3,4,5,6};
    vector<int> v1(a,a+6);
    vector<int>::iterator p=v1.begin();

    Solution reOrder;//=new Solution(); new ���ص���һ��ָ������ָ�룡
   reOrder.reOrderArray(v1);
    while(p!=v1.end())
    {
        cout<<*p<<endl;
        p++;
    }

    return 0;
}
