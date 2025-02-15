#include<iostream>
using namespace std;
void movezeros(int arr[],int n){
	int nonzero=0;
	for(int j=0;j<n;j++){
		if(arr[j]!=0){
			swap(arr[j],arr[nonzero]);
			nonzero++; 
		}
	}

}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[6]={0,1,0,3,12,0};
	movezeros(arr,6);
	print(arr,6);
}
