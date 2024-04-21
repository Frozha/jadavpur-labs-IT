#include<iostream>
using namespace std;
#define size_a 20
#define size_b 20

void str_swap_ref(char (&a)[size_a],char (&b)[size_b]){
	char temp[size_a];
	cout<<"\nswap by ref.\n";
	for(int i=0;(i<size_a);i++){
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}

}

void str_swap_noref(char (*a),char (*b)){
	char temp[size_a];
        cout<<"\nswap by value.\n";
        for(int i=0;(i<size_a);i++){
                temp[i] = *(a+i);
                *(a+i) = *(b+i);
                *(b+i) = temp[i];
        }

}
int main(){
	char a[size_a]="hello world";
	char b[size_b]="goodbye world";
	cout<<"a = "<<a<<" b = "<<b;
 	str_swap_ref(a,b);
        cout<<"a = "<<a<<" b = "<<b;
	str_swap_noref(a,b);
	cout<<"a = "<<a<<" b = "<<b;
	return 0;
}

