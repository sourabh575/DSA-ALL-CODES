#include<iostream>
using namespace std;
int main(){
	int num=5;
	int *p=&num;
	cout<<"copying a pointer:"<<endl;
	int *q=p;
	cout<<p<<"-"<<q<<endl;
	cout<<*p<<"-"<<*q<<endl;
	
	
}
	
