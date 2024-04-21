#include<iostream>
using namespace std;

class stack{
	private:
		int *buffer, top;
		const int max_indx;
		
	public:
		stack(const int size):max_indx(size-1){
			buffer = new int[size];
			top=0;
		}
		
		int pop(){
			if(top == 0){
				
				return 0;
			}
			else{
				int temp = buffer[top-1];
				buffer[top-1]=0;
				top--;
				return temp;
			}
		}
		
		void push(const int &a){
			if(top<max_indx){
				buffer[top] = a;
				top++;
			}
		}
		
		void display() const{
			for(int i=top-1;i>=0;i--){
				cout<<buffer[i]<<endl;
			}
		}
		
};

int main(){
	stack a(10);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	
	cout<<"popped element : "<<a.pop();
	
	cout<<endl<<"stack :-\n";
	a.display();
	
}
