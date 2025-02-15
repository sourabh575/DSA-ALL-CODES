#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	for(int i=1;i<=n;i++){
		//print first triangle
		int space=n-i;
		while(space){
			cout<<" ";
			space--;
		}
		//print second triangle
		for(int j=1;j<=i;j++){
		cout<<j;
				
		}
		//print third triangle
		int start=i-1;
		while(start){
			cout<<start;
			start--;
		}
		cout<<endl;
	}
	 
	
	
	
	
	
	
	
	
}
