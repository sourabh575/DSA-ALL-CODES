#include<iostream>
using namespace std;
int getsum(int *arr,int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+i[arr];
	}
	return sum;	
}
int main(){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<"sum of array is:"<<getsum(arr,10)<<endl;
	cout<<"sum of array is after arr+3:"<<getsum(arr+3,7);
}
