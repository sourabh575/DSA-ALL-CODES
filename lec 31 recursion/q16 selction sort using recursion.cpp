#include<iostream>
using namespace std;
void selectionsort(int *arr,int i,int n){
	//base case
	if(i==n-1||i==n){
		return;
	}
	int minidx=i;
	for(int j=i+1;j<n;j++){
		if(arr[j]<arr[minidx]){
			minidx=j;
		}	
	}
	swap(arr[minidx],arr[i]);
	
	//recusrive relation
	selectionsort(arr,i+1,n);
	
}

int main(){
	int arr[6]={64,2,11,12,24,15};
	selectionsort(arr,0,6);
	for(int k=0;k<6;k++){
		cout<<arr[k]<<" ";
	}
	
}
