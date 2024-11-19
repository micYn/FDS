#include <iostream>
#include <cstdlib>

using namespace std;

template <class T> class Chain;

template <class T> 
class ChainNode{
	friend class Chain<T>;
	public:
		ChainNode(T element = 0,ChainNode<T>* ptr = NULL){data=element;	next=ptr;}
	private:
		T data;
		ChainNode<T>* next;
};
template <class T> 
class Chain{
	public:
		class ChainIterator{
			public:
				ChainIterator(ChainNode<T>* ptr = 0){current=ptr;}
				T& operator *() const{return current->data;}
				T& operator ->() const{return &current->data;}
				ChainIterator& operator ++(){
					current=current->next;
					return *this;
				}
				ChainIterator operator ++(int){
					ChainIterator old = *this;
					current=current->next;
					return old;
				}
				bool operator !=(const ChainIterator right) const{
					return (current!=right.current);
				}
				bool operator ==(const ChainIterator right) const{
					return (current==right.current);
				}
				bool operator <(const ChainIterator right) const{
					return (current<right.current);
				}
			private:
				ChainNode<T>* current;
		};
		Chain(){first=0;last=0;}
		ChainIterator begin(){return ChainIterator(first);}
		ChainIterator end(){return ChainIterator(0);}
		
		int func();

		void insertnode(ChainNode<T>* x){
			if(first==0){	first=last=x;}
			else{last->next=x; last=last->next;}
		}
	private:
		ChainNode<T>* first;
		ChainNode<T>* last;
};
/********************************************************************************/
//用iterator太難搞 索性不用了
//要特別注意linked list元素的順序不代表記憶體順序
//他們在記憶體中是亂的->不能用指標大小於去決定事情 只有用等於或不等於來判斷才會是對的
template <class T>
int Chain<T>::func(){
	ChainNode<T>* current=first;
	int count=0;
	while(current){
		count++;
		current=current->next;
	}
	count=count/5;
	int sum=0;
	ChainNode<T>* current1;
	ChainNode<T>* current2;
	current1=first;
	current2=first->next;
	current2=first->next;
	current2=first->next;
	current2=first->next;
	while(count--){
		sum+=current1->data*current2->data;
		current1=current1->next;
		current2=first->next;
		current2=first->next;
		current2=first->next;
		current2=first->next;
	}
	return sum;
}
/********************************************************************************/		
	
int main(){
	Chain<int> a;
	for(int i=30;i>0;i--){
		ChainNode<int>* ptr = new ChainNode<int>(i);
		a.insertnode(ptr);
	}
	cout<<a.func();
}









	
