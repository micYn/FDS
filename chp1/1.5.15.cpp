#include <iostream>
using namespace std;
void Tower_of_Hanoi(int disknum,char A,char B,char C){
	if(disknum==1)	cout<<"Moving disk 1 from "<<A<<" to "<<C<<".\n";
	else{
		Tower_of_Hanoi(disknum-1,A,C,B);
		cout<<"Moving disk "<<disknum<<" from "<<A<<" to "<<C<<".\n";
		Tower_of_Hanoi(disknum-1,B,A,C);
	}
}
int main(){
	Tower_of_Hanoi(6,'A','B','C');
	
	return 0;
}
