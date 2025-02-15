#include<iostream>
using namespace std;
int main(){
	int temp[10];
	cout<<"size of opeator in array:"<<sizeof(temp)<<endl;
	cout<<"1st:"<<sizeof(*temp)<<endl;
	cout<<"2nd:"<<sizeof(&temp)<<endl;
	int *ptr=&temp[0];
	cout<<"size of opeator in pointer:"<<sizeof(ptr)<<endl;
	cout<<"esmi meh sizeof *ptr printkrbaya raha hu:"<<sizeof(*ptr)<<endl;
	
	cout<<"2n diffrence"<<endl;
	int a[10]={1,2,3,4};
	cout<<&a<<endl;
	int *p=&a[0];
	cout<<&p<<endl;
	
	cout<<"3rd differnce"<<endl;
	int arr[10];
	
	int *p2=&arr[0];
	//error arr=arr+1;
	cout<<p2<<endl;
	p2=p2+1;
	cout<<p2<<endl;
	
	
	
	



	
	
}
	
