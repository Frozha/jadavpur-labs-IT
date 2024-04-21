#include<string>
#include<iostream>
using namespace std;

class number{
    public:
        number(char* num) : length{strlen(num)} , arr{new int[strlen(num)+1]}{
            for(int i=length-1,j=0;i>=0;i--,j++){
                arr[j]=(int)num[i]-(int)'0';
            }
            arr[length]=0;
        };

        number(int len) : length{len},arr{new int[len+1]}{
            for(int i=0;i<=length;i++){
                arr[i] = 0;
            }
        };

        void display(){
            printf("\n");
            for(int i=length-1;i>=0;i--){
                printf("%d",arr[i]);
            }
            printf("\n");
        }

        number add(number num1,number num2){
            if(num1.length>=num2.length){
                number sum(num1.length);
                for(int i=0;i<num1.length;i++){
                    sum.arr[i]=num1.arr[i];
                }
                for(int j=0;j<num2.length;j++){
                    sum.arr[j]+=num2.arr[j];
                }
                for(int k=0;k<sum.length;k++){
                    if(sum.arr[k]>9){
                        sum.arr[k+1]+=sum.arr[k]/10;
                        sum.arr[k]=sum.arr[k]%10;
                    }
                }
                if(sum.arr[sum.length]!=0){
                    sum.length++;
                }
                return sum;
            }
            add(num2,num1);
        }

    private:
        int* arr;
        int length;
        int strlen(char* str){
            int i=0,l=0;
            while(str[i]!='\0'){
                i++;l++;
            }
            return l;
        }
};

int main(){
    cout<<"Enter 2 large numbers to add them -\n1. ";
    char a[100],b[100];
    gets(a);
    cout<<"2. ";
    cin>>b;
    number num1(a);
    number num2(b);
    number sum{sum.add(num1,num2)};
    sum.display();
}