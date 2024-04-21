#include<iostream>
#include<vector>
using namespace std;
#define cols 3
#define rows 2
void prints(const char *c_str,const int length){
    for(int i=0;i<length;i++){
        cout<<c_str[i];
    }
}

void prints(const char (*sentence)[cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<sentence[i][j];
        }
        cout<<" ";
    }
}
int main(){
    char s[rows][cols] = {
        {'a','b','c'},
        {'d','e','f'}
    };

    char v1[] = {'g','h','i'};

    prints(s);
    prints(v1,3);

}
