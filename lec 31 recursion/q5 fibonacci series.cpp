#include<iostream>
using namespace std;
int fibonacci(int n){
	//base case
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	//processing
	int sum=fibonacci(n-1)+fibonacci(n-2);
	//recursive relation
	return sum;
}

int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	cout<<fibonacci(n);
	
}
