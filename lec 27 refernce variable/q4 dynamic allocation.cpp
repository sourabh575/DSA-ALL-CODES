#include<iostream>
using namespace std;
int getsum(int *arr,int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
	}
	return sum;
	
}
int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	
	//variable size array
	int *arr = new int[n];
	
	cout<<"taking input in array:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	} 
	cout<<"sum is:"<<getsum(arr,n);
	
	

}
