#include<iostream>
using namespace std;
void saysdigit(int n,string *arr){
	
	//base case
	if(n==0)
	return ;
	
	//processing
	int digit=n%10;
	n=n/10;
	
	//recursive relation
	saysdigit(n,arr);
	
	cout<<arr[digit]<<" ";
}

int main(){
	string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int n;
	cout<<"enter a number:";
	cin>>n;
	saysdigit(n,arr);
}




