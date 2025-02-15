#include<iostream>
using namespace std;
int main(){
	int i=5;
	int* p=&i;
	int **p2=&p;
	cout<<"value of i:"<<i<<endl;
	cout<<"value of *p:"<<*p<<endl;
	cout<<"value of **P:"<<**p2<<endl;
	cout<<"printing p:"<<&i<<endl;
	cout<<"printing p:"<<p<<endl;
	cout<<"printing p:"<<*p2<<endl;
	cout<<"adress of p:"<<&p<<endl;
	cout<<"adress of p:"<<p2<<endl;
	cout<<"adress of p2:"<<&p2<<endl;

	
	
	
	
	
	
}
