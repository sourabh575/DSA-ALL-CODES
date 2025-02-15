#include<iostream>
using namespace std;
int main(){
	int arr[10]={5,9,8,23};
	cout<<"address of first element:"<<arr<<endl;
	cout<<"address of first element:"<<&arr[0]<<endl;
	int *p=arr;
	cout<<"address of first element:"<<p<<endl;
	cout<<"element at first:" <<*arr<<endl;
	cout<<"*arr+1:"<<*arr+1<<endl;
	cout<<"*(arr+1):"<<*(arr+1)<<endl;
	cout<<"(*arr+1)"<<(*arr+1)<<endl;
	
	
	int i=3;
	cout<<i[arr]<<endl;
	
	cout<<"2n diffrence"<<endl;
	int a[10]={1,2,3,4};
	cout<&a<<endl;
	int *p=&a;
	cout<<&p<<endl;
	
}
