#include<iostream>
using namespace std;
int limbstairs(int n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	int sum=limbstairs(n-1)+limbstairs(n-2);
	return sum;
}

int main(){
	int n;
	cin>>n;
	cout<<limbstairs(n);
}
