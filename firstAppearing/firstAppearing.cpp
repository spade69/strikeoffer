#include<iostream>
#include<string>
#include<sstream>
using namespace std;
/*First Appearence once char in current stringstream
 *
 * Author :Jason
 * Date: 2016/6/26
 * */


int record[256]={0};
vector<char> vec;

void Insert(char ch){
    vec.push_back(ch);
    record[ch] ++;
}

char FirstAppearingOnce(){
    char now;//store the result
    int size=vec.size();

    for(int i=0;i<size;i++){
        if(record[vec[i]]==1){
            return vec[i];
        }
    
    }
    return '#';
}

int main(){

    return 0;
}
