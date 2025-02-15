#include<iostream>
using namespace std;
int main(){
	int i=5;
	int *t=&i;
	(*t)++;
	cout<<*t<<endl;
	cout<<"before t=t+1:"<<t<<endl;
	t=t+1;
	cout<<"after t=t+1:"<<t<<endl;

}
