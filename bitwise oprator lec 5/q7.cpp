#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number";
	cin>>n;
	bool isprime=1;
	for(int i=2;i<n;i++){
		if(n%2==0){
			isprime=0;
			break;
		}

	}
	if(isprime==0){
		cout<<"not a prime no"<<endl;
		
	}
	else{
		cout<<"is a prime no"<<endl;
	}
	
	
	
}
