#include<iostream>
using namespace std;
int peakmountain(int *arr,int s,int e){
	while(s<e){
		int mid=(s+e)/2;
		if(arr[mid]<arr[mid+1]){
			return peakmountain(arr,mid+1,e);
		}
		else{
			return peakmountain(arr,s,mid);
		}
		return s;
	}
	
}

int main(){
	int arr[6]={2,3,77,6,3};
	cout<<"peak value is:"<<peakmountain(arr,0,5);
}
