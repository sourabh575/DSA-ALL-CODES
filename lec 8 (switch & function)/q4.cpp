#include<iostream>
using namespace std;
//void ->ye koi bhi output return nhi krta hai only print krta hai
//function signature 
void printcounting(int n){
	for(int i=1;i<=n;i++){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	printcounting(n);
	return 0;
}
