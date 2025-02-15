#include<iostream>
using namespace std;
int getmax(int *arr,int n){
	int max=-1;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
int main(){
	int arr[10]={1,2,5,6,98,2,8,555,78};
	cout<<getmax(arr,10);
	
}
