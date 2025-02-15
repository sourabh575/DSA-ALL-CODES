#include<iostream>
using namespace std;
	void update(int *p){
		p=p+1;
		cout<<"inside update:"<<p<<endl;
	}
	void element(int *p){
		*p=*p+1;
	}
	int main(){
	int value=5;
	int *p=&value;
	cout<<"before address:"<<p<<endl;
	update(p);
	cout<<"after address:"<<p<<endl;
	
	cout<<"value"<<endl;
	cout<<"before value:"<<*p<<endl;
	element(p);
	cout<<"after value:"<<*p<<endl;
	
	

	
	
	
	
}
