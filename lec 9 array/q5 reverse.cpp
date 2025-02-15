#include<iostream>
using namespace std;
	void reverse(int arr[],int n){
		int start=0;
		int end=n-1;
		while(start<=end){
			swap(arr[start],arr[end]);
			start++;
			end--;
			
		}
	}
	void printarray(int arr[],int n){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		
		}
			cout<<endl;
	}
	int main(){
	
		
	
	int arr[5]={5,6,4,8,9};
	int brr[5]={4,6,8,2,3};
	reverse(arr,5);
	reverse(brr,5);
	printarray(arr,5);
	printarray(brr,6);
	
}
  


















































