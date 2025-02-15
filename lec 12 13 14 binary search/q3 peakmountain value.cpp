#include<iostream>
using namespace std;
int peakindexmountainarray(int arr[],int n){
	int s=0;
	int e=n-1;
	int mid=(s+e)/2;
	while(s<e){
		if(arr[mid]<arr[mid+1]){
			s=mid+1;
		}
		else{
			e=mid;
		}
		mid=(s+e)/2;
	}
	return s;
}
int main(){
	int arr[5]={3,4,5,6,1};
	cout<<"index of peak value of 6 is:"<<peakindexmountainarray(arr,5);
	
}
