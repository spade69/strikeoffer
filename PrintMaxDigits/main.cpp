#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;
/*?************
Function��ʵ�ִ�ӡ1������nλ��
���Ǵ�������
����1�� �����������
����2�� ʲôʱ���жϵ���99..99��������Ӧ���ǵ�һ���ַ���λ��ʱ��
����3�� ��ӡǰ�治����0�����ӷ�0��ʼ��ӡ

���룺n λ
Author:Jason
Version:1.0
Date:2016/04/26

stupid �ⷨ��
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
û�п��ǵ� ��������
���б߽�������
********/


bool Increment(char* number);
void PrintNumber(char* number);
void PrintMaxDig(int n)
{
    if(n<=0)
        return;

    char *number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0'; //��Ϊ�ַ����Ľ���

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
    //�ַ��� number[0...length-1] = "123456"
    //����Ǹ�λ��
    for(int i=nLength-1;i>=0;i--)
    {
        //ȡʵ�ʵ���ֵ
        int nSum=number[i]-'0'+nTakeOver;//�н�λ�Ļ����˴�����1.
        if(i==nLength-1)
            nSum++;// �ս���forѭ������

        if(nSum>=10) //����պ���9���Ǿ�Ҫ��λ��
        {
            if(i==0) //ѭ������0�����ǵ������λ���ˡ�
            isOverflow=true;
            else  //�������ѭ����ȥ��
            {
                nSum-=10;
                nTakeOver=1; //��λ~
                number[i]='0'+nSum; //��number���޸�~
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
        //false�Ŵ�ӡ���������㣡='0'
        if(isBeginning0&&(number[i]!='0'))
            isBeginning0=false;
        if(!isBeginning0)
            printf("%c",number[i]);
    }
    printf(" ");
}


/*?************
Function��ʵ�ִ�ӡ1������nλ�� ȫ���нⷨ
���Ǵ�������
����1�� �����������
����2�� ʲôʱ���жϵ���99..99��������Ӧ���ǵ�һ���ַ���λ��ʱ��
����3�� ��ӡǰ�治����0�����ӷ�0��ʼ��ӡ

���룺n λ
Author:Jason
Version:2.0
Date:2016/04/26

 ȫ���нⷨ������Ҫģ��ӷ�
 nλ����ʮ����������n����0��9��ȫ����
 ֻ�Ǵ�ӡʱ����������ǰ���0���ǲ���ӡ��

 �ݹ���������� �����������ֵ����һλ.
********/
void PrintToMaxDitgitsRecursively(char* number,int length,int index)
{
    //�ݹ���ǰ�����������Ϊ����������˵PrintToMaxDitgitsRecursively(number,4,2)
    //���ǻ��õ�PrintToMaxDitgitsRecursively(number,4,3)�Ľ��
    //
    if(index==length-1) //�ȵݹ鵽index==length-1 ��Ȼ���ջ�������ӡ
    {
        PrintNumber(number);
        return;
    }

    for(int i=0;i<10;++i)
    {
        number[index+1]=i+'0'; //ֻ����0~9,�ڵݹ�ִ�й����иı�
        //forѭ����ӡ���е�number[1...length-1] ��ӡ������Щλ
        //index����length-1�� �ͻ��ӡ���ѭ����Ȼ��return������length���㣬index����++�� Ȼ��return����Ҫ������index==length-1�Ŵ�ӡ
        PrintToMaxDitgitsRecursively(number,length,index+1);//�ݹ�ʵ��
    }
}

/*******************
�������Ǵ�0��ʼ�ӵ�99..99
������Ҫ��ֻ���ж��Ƿ��������Ǹ�λ��
ǰ���
*********************/
void PrintToMaxDitgits(int n)
{
    if(n<=0)
    return;

    char* number=new char[n+1];
    number[n]='\0';

    for(int i=0;i<10;i++)
    {
        number[0]=i+'0'; //�ı���ǵ�һλ�������λ��ֵ ��0~9
        //����n=4 �����ѭ���� 0999 ,1999,2999,3999...9999 ������λ
        PrintToMaxDitgitsRecursively(number,n,0);
    }
    delete[] number;
}



//�ⷨ ʹ��ö��������

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

//���Եݹ�
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
