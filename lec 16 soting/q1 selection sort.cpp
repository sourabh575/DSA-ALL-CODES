#include<iostream>
#include<vector>
using namespace std;
void selectionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int minidx=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minidx]){
				minidx=j;
			}
		}
		swap(arr[minidx],arr[i]);
	}
	cout<<"sorted array:";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[5]={64,25,12,22,11};
	selectionSort(arr,5);
	
	
}
