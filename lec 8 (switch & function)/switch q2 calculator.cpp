#include<iostream>
using namespace std;
int main(){
	int a;
	cout<<"enter the number a:"<<endl;
	cin>>a;
	int b;
	cout<<"enter the number b:"<<endl;
	cin>>b;
	char op;
	cout<<"enter the operation you want to perform"<<endl;
	cin>>op;
	switch(op){
		case '+':cout<<(a+b)<<endl;break;
		case '-':cout<<(a-b)<<endl;
		break;
		case '*':cout<<(a*b)<<endl;
		break;
		case '/':cout<<(a/b)<<endl;
		break;
		case '%':cout<<(a%b)<<endl;
		break;
		default:cout<<"please enter a valid operation";
		break;
	}
}
