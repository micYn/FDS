#include <iostream>
using namespace std;
class Complex{
	public:
		Complex();
		Complex(int i,int j);
		friend Complex operator +(const Complex& c1,const Complex& c2);
		friend Complex operator *(const Complex& c1,const Complex& c2);
		friend ostream& operator <<(ostream& os,const Complex& c);
		friend istream& operator >>(istream& is,Complex& c);
	private:
		int real;
		int imag;
};
Complex::Complex():real(0),imag(0){}
Complex::Complex(int i,int j):real(i),imag(j){}
Complex operator +(const Complex& c1,const Complex& c2){
	Complex temp;
	temp.real = c1.real+c2.real;
	temp.imag = c1.imag+c2.imag;
	return temp;
}
Complex operator *(const Complex& c1,const Complex& c2){
	Complex temp;
	temp.real = c1.real*c2.real-c1.imag*c2.imag;
	temp.imag = c1.real*c2.imag+c2.real*c1.imag;
	return temp;
}
ostream& operator <<(ostream& os,const Complex& c){
	os<<c.real<<" + "<<c.imag<<"j ";
	return os;
}
istream& operator >>(istream& is,Complex& c){
	int tempreal,tempimag;
	is>>tempreal>>tempimag;
	c.real = tempreal;
	c.imag = tempimag;
	return is;
}
int main(){
	Complex A,B,C,D;
	cin>>A>>B;
	C = A+B;
	D = A*B;
	cout<<A<<endl<<B<<endl<<C<<endl<<D<<endl;
	return 0;
}
	
