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
			private:
				ChainNode<T>* current;
		};
		Chain(){first=0;last=0;}
		ChainIterator begin(){return ChainIterator(first);}
		ChainIterator end(){return ChainIterator(0);}
		
		T minimumelement();
		void insertnode(ChainNode<T>* x){
			if(first==0){	first=last=x;}
			else{last->next=x; last=last->next;}
		}
	private:
		ChainNode<T>* first;
		ChainNode<T>* last;
};
/*******************************************/
template <class T>
T Chain<T>::minimumelement(){
	T minimum = first->data;
	ChainIterator i(first);

	for(;i!=(*this).end();i++)
		if(*i<minimum)	minimum=*i;
	return minimum;
}
/*******************************************/
//driver
int main(){
	Chain<int> a;
	for(int i=20;i>10;i--){
		ChainNode<int>* ptr = new ChainNode<int>(i);
		a.insertnode(ptr);
	}
	ChainNode<int>* ptr = new ChainNode<int>(-8);
	a.insertnode(ptr);
	for(int i=10;i>0;i--){
		ChainNode<int>* ptr = new ChainNode<int>(i);
		a.insertnode(ptr);
	}
	cout<<a.minimumelement()<<endl;
}

