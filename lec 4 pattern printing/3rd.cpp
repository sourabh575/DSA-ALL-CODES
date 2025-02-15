#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<"*"<<" " ;
		}
		cout<<"\n";
	}*/
	int i=1;

	while(i<=n){
		int j=1;
		while(j<=n){
			int p=n-j+1;
			cout<<p<<" ";
			j++;
	    }
		i++;
		cout<<endl;
	}





}
