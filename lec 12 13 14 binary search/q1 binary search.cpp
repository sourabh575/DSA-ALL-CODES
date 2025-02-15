#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
	int start=0;
	int end=size-1;
	int mid=(start+end)/2;
	while(start<=end){
		if(arr[mid]==key){
			return mid; 
		}
		if(arr[mid]<key){
			start=mid+1;
			
		}
		else{
			end=mid-1;
		}
		
	    int mid=(start+end)/2;
		
	   
	}
	return -1;
}


int main(){
	int even[6]={2,4,6,8,10,12};
	int odd[5]={2,5,7,9,11};
	int evenIndex=binarysearch(even,6,10);
	cout<<"index of 10 is:"<<evenIndex<<endl;
	int oddIndex=binarysearch(odd,5,14);
	cout<<"index of 14 is:"<<oddIndex<<endl;
	
}

