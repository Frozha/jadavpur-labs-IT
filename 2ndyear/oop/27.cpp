#include<iostream>

using namespace std;

class queue{
	private:
		int *data;
		int front, rear;
		const int length;
		
	public:
		queue(const int size):length(size){
			data = new int[size];
			front = 0;
			rear = 0;
		}
		
		void add(const int &element){
			if((front+1)%length!=rear%length){
				data[front%length] = element;
				front=(front+1)%length;		
			}
		}
		
		int remove(){
			if(rear%length!=front%length){
				int temp = data[rear%length];
				rear = (rear+1)%length;
				return temp;
			}
      else{
        return 0;
      }
		}
		
		void display() const{
			int r = rear;
			while (r!=front){
				cout<<data[r]<<" ";
				r++;
				r=r%length;
			}
		}
		
		~queue(){
			delete data;
		}
};

int main(){
	queue a(10);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	
	cout<<"removed element : "<<a.remove();
	
	cout<<"\nQueue : ";
	a.display();
	cout<<"\n  front^";
}
