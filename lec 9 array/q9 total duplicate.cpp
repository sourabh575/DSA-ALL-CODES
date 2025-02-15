#include<iostream>
using namespace std;
void findduplicate(int arr[],int brr[],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i]==brr[j]){
				cout<<arr[i]<<" ";
				brr[j]=INT_MIN;
				break;
		    }	
			
		}
	}
}


int main(){
    int arr[3]={2,3,3};
    int brr[2]={3,2};
    findduplicate(arr,brr,3,2);
}
