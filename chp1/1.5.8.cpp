#include <iostream>
using namespace std;
int binomial(int n,int m){
	if(m==0||n==m)	return 1;
	else{
		return binomial(n-1,m)+binomial(n-1,m-1) ;
	}
}
/*
	Time required = (2 * binomial(n,m) - 1)* t where t is the time required for executing
the binomial function once.
	Space required = c * (binomial(n,m) -1) where c is the stack space required for
storing the context. ( binomial(n-1,m)會先算出來之後,空間就可以拿來算binomial(n-1,m-1) ,因此不用*2 )

*/
	
