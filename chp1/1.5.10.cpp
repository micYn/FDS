#include <iostream>
using namespace std;
//Recursive Function
int Ackermann(int m,int n){
	if(m==0&&n!=0)	return (n+1);
	else if(m!=0&&n==0)	return Ackermann(m-1,1);
	else	return Ackermann(m-1,Ackermann(m,n-1));
}

//Nonrecursive Algorithm
int Ackermann (int m, int n) // Pseudocode
{
	// Assume that there are two stacks available to us. stack2 can be thought of as result
	// stack where results are pushed for future use. This program can be written with one
	// stack but we use two stacks for clarity.
	Initialize stack1 and stack2;
	push m and n into stack1;
	do {
		pop n and m from stack1;
		if (n is a special symbol) n = pop from stack2;
		// This means that the result has been stored in the result stack
		if (m=0) push (n+1) onto stack2;
		else if (n=0)
			push m−1 and 1 onto stack1;
		else {
			push m−1 and special symbol onto stack1;
			push m and n−1 onto stack1;
		}
	} while (stack1 is not empty);

	result = pop from stack2;
	return result;
}
