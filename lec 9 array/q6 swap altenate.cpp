#include<iostream>
using namespace std;
void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		
	}
	cout<<endl;
}
void swapalternate(int arr[],int size){
	for(int i=0;i<size;i+=2){
		if(i=i+1<size){
		    swap(arr[i],arr[i+1]);
		}
		
	}
}
	

int main(){		
	
	int odd[5]={1,5,6,8,4};
	int even[6]={1,2,3,4,5,6};
	swapalternate(odd,5);
	printarray(odd,5);
	swapalternate(even,6);
    printarray(even,6);
    
	
}
