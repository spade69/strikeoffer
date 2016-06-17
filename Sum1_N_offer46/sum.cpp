#include<iostream>

using namespace std;

/***************************
Sum 1+2+3...+n
 *input: a int variale n
*output: sum
*return :int variale sum

Must not using for / while /if else/switch/case
and * / multiple divide

Method& thinking:


* Author Jason
* Date 2016/06/17
* **********************************/

//Method 1
class temp{
public:
    temp(){++N;Sum+=N;}
    static void reset(){
        N=0;
        Sum=0;
    }
    static int GetSum(){
        return Sum;
    }

private:
    static unsigned int N;
    static unsigned int Sum;
};

//must declare here first, then you can use the method relavant with private variale
unsigned int temp::N=0;
unsigned int temp::Sum=0;


int Sum_Solution1(int n)
{
    temp::reset();
    temp *a=new temp[n];
    delete[] a;
    a=NULL;

    return temp::GetSum();
}

//method 3 ,using recursive
int Sum_Solution3(int n)
{
    int ans=n;
    //using && replace the function of if else
    ans&&(ans+=Sum_Solution3(n-1));
    return ans;

}

int main(){
    int sum=0;
    sum=Sum_Solution1(5);
    cout<<sum<<endl;
    return 0;
}
