#include<iostream>
using namespace std;
bool issorted(int *arr,int n){
	
	//base case
	if(n==0||n==1){
		return true;
	}
	if(arr[0]>arr[1]){
		return false;
		
	}
	else{
		bool remainingpart=issorted(arr+1,n-1);
		return remainingpart;
	}

	
}


int main(){
	int arr[10]={2,5,6,7,9,12,14,16,22,22};
	bool ans=issorted(arr,10);
	if(ans==true){
		cout<<"array is sorted"<<endl;
	}
	if(ans==false){
		cout<<"array is not sorted"<<endl;
	}
	
	
	
}
