#include<iostream>
using namespace std;
int main(){
	int num=5;
	cout<<num<<endl;
	cout<<"address of num is:"<<&num<<endl;
	int *p=&num;
	cout<<*p<<endl;
	//char ch='a';
	//char *ptr=&ch;
	//cout<<*ptr<<endl;
	cout<<"address of num is:"<<p<<endl; 
	double d=4.3;
	double*p2=&d;
	cout<<*p2<<endl;
	cout<<"address of d is:"<<p2<<endl; 
	cout<<"size of integer is:"<< sizeof(num)<<endl;
	cout<<"size of pointer p is:"<<sizeof(p)<<endl;
	cout<<"size of pointer p2 is:"<<sizeof(p2)<<endl;


	}
