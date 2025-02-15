#include<iostream>
using namespace std;
//object like macro defination
#define pi 3.14
int main(){
	int r;
	cout<<"enter a radius:";
	cin>>r;
	double area=pi*r*r;
	cout<<"area of circle:"<<area<<endl;
}
