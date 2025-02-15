#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number";
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(i+j==10){
				break;
			}
			cout<<i<<" "<<j<<endl;
		}
	}
}

