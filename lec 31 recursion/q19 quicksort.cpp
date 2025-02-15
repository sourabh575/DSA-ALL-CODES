#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
	int count=0;
	int pivot=arr[s];
	for(int i=s+1;i<=e;i++){
		if(arr[i]<=pivot){
			count++;
		}
	}
	
	//pivot placed at right postion
	int pivotindex=s+count;
	swap(arr[pivotindex],arr[s]);
	
	//left and right wala par smbhal lete h
	int i=s,j=e;
	
	while(i<pivotindex && j>pivotindex){
		while(arr[i]<pivot){
			i++;
		}

		while(arr[j]>pivot){
			j--;
		}
		
		if(i<pivotindex && j>pivotindex){
			swap(arr[i++],arr[j--]);
		}
	}
	return pivotindex;
}

void quicksort(int *arr,int s,int e){
	//base case
	if(s>=e){
		return ;
	}
	int p=partition(arr,s,e);
	
	//left bale part ko
	quicksort(arr,s,p-1);
	
	//right bale part ko
	quicksort(arr,p+1,e);
}


int main(){
	int arr[6]={8,5,3,1,2,4};
	int n=6;
	
	quicksort(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		
	}
	
	
}
