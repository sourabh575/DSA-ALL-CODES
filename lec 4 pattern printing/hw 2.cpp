#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	for(int i=0;i<n;i++){
		int space=n-i;
		while (space){
			cout<<"*";
			space--;
		}
		for(int j=0;j<=i;j++){
			cout<<" ";	
	}
		cout<<endl;
		
	}
	
}
