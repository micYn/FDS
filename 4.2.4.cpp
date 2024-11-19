#include <iostream>
using namespace std;
class Chain;
class ChainNode{
	friend Chain;
	friend ostream& operator <<(ostream& os,const Chain& c);
	public:
		ChainNode(int element=10,ChainNode* ptr=NULL){
			data = element;
			next = ptr;
		}
	private:
		int data;
		ChainNode* next;
};
class Chain{
	public:
		Chain():first(NULL){}
		void pushnode(ChainNode* x); //insertback
		void deletenode(ChainNode* y,ChainNode* x);
		void mergechain(Chain& c1,Chain& c2);
		friend ostream& operator <<(ostream& os,const Chain& c);
	private:
		ChainNode* first;
};
void Chain::pushnode(ChainNode* x){
	if(first==NULL){
		first = new ChainNode(x->data,NULL);
	}
	else{
		ChainNode* current = first;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next = new ChainNode(x->data,NULL);
	}
}
void Chain::deletenode(ChainNode* y,ChainNode* x){
	if(y==NULL){
		first = first->next;
		delete x;
	}
	else{
		y->next = x->next;
		delete x;
	}
}
void Chain::mergechain(Chain& c1,Chain& c2){
	ChainNode* temp1 = c1.first;
	ChainNode* temp2 = c2.first;
	while(temp1!=NULL&&temp2!=NULL){
		pushnode(temp1);
		c1.deletenode(0,temp1);
		pushnode(temp2);
		c2.deletenode(0,temp2);
		temp1=c1.first;
		temp2=c2.first;
	}
	for(;temp1!=NULL;){
		pushnode(temp1);
		c1.deletenode(0,temp1);
		temp1=c1.first;
	}
	for(;temp2!=NULL;){
		pushnode(temp2);
		c2.deletenode(0,temp2);
		temp2=c2.first;
	}
		
}
		
ostream& operator <<(ostream& os,const Chain& c){
	if(c.first==NULL){
		os<<"empty"<<endl;
		return os;
	}
	ChainNode* current = c.first;
	while(current!=NULL){
		os<<current->data<<" ";
		current=current->next;
	}
	os<<endl;
	return os;
}
int main(){
	Chain x,y,z;
	for(int i=0;i<=20;i++){
		ChainNode* temp = new ChainNode(i,NULL);
		if(i%2==0)	x.pushnode(temp);
		else	y.pushnode(temp);
	}
	cout<<"x: "<<x<<"y: "<<y;
	z.mergechain(x,y);
	cout<<"x: "<<x<<"y: "<<y<<"z: "<<z;
	
	return 0;
}
	
	
