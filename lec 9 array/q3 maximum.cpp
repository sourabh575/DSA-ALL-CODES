#include<iostream>
using namespace std;
int getmax(int num[],int size){
	int maxi=INT_MIN;
	for(int i=0;i<size;i++){
		maxi = max(maxi,num[i]);
		//if(num[i]>max){
		//	max=num[i];
		}

	return maxi;
}
int getmin(int num[],int size){
	int min=INT_MAX;
	for(int i=0;i<size;i++){
		if(num[i]<min){
			min=num[i];
		}
	}
	return min;
}

int main(){
	int size;
	cin>>size;
	int num[100];
	for(int i=0;i<size;i++){
		cin>>num[i];
	}
	cout<<"Maximum value is:"<<getmax(num,size)<<endl;
	cout<<"Minimum value is:"<<getmin(num,size)<<endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*method 1
	int arr[5]={1,2,3,5,7};
	int max=0;
	int n=5;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	cout<<max;*/
	


