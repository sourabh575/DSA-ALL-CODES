#include<iostream>
using namespace std;
int getsum(int *arr,int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return arr[0];
	}
	int remainingpart=getsum(arr+1,n-1);
	int sum=arr[0]+remainingpart;
	return sum;
	
	
}

int main(){
	int arr[5]={2,4,6,8,10};
	cout<<"sum is:"<<getsum(arr,5)<<endl;
	
}
