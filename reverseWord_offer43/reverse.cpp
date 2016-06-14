#include<iostream>
#include<string>
#include<string.h>
using namespace std;

/***************************
*Reverse a sentence. But not change the order of each word.
*input: a string
*output:
*return :a reverse sentence
Method& thinking:
Reverse hold sentence first
and then reverse each word . we scan the space

* Author Jason
* Date 2016/06/12
* **********************************/


void Reverse(char* b,char* e)
{
    if(b==NULL||e==NULL)
        return;

    while(b<e)
    {
        char t=*b;
       *b=*e;//assign *e to *b then b++
        *e=t;//assign t to *e then e--
        b++,e--;
    }
}

string ReverseSentence(string str){
    string s;
    if(str.length()<1)
        return s;
    int len=str.length();//len is not including '\0'!!

   // char p[100];
   // strcpy(p,str.c_str());

    char *p=&str[0];
    //char* p=&str[0];
    char* b=p;
    char* e=p;
    //reverse the whole sentence

    Reverse(b,b+len-1);
    b=e=&str[0];//recover
    //cout<<str<<endl; //.uoy kcuf i

    while(*e!='\0'){
        if(*b==' '){
            b++;
            e++;
        }
        else if(*e==' '||*(e+1)=='\0'){
            if(*(e+1)=='\0'){//handle the special string "word" only one word.
                Reverse(b,e);
                break;
            }

            Reverse(b,--e);//first e=e-1,then we assign e to reverse,and it will change in this process
            //because it can be only one char like "i" then b=e-1
            b=++e;//no matter where, it will step up until *b==' '
        }
        else{
            e++;
        }
    }
    return str;
}

int main(){
    string b("fuck");
    string a("i fuck you.");
    string re=ReverseSentence(a);
    string rb=ReverseSentence(b);
    cout<<re<<endl;
    cout<<rb<<endl;
    return 0;
}
