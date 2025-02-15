#include<iostream>
using namespace std;
void print(int *arr,int n){
	cout<<"size of array is:"<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

bool linearsearch(int *arr,int key,int n){
	print(arr,n);
	
	if(n==0){
		return false;
	}
	if(arr[0]==key){
		return true;	
	}
	
	bool remainingpart=linearsearch(arr+1,key,n-1);
	return remainingpart;
	
	
}

int main(){
	int arr[5]={3,1,2,4,5};
	int key=4;
	int n=5;
	cout<<"key is:"<<key<<endl;
	bool ans=linearsearch(arr,key,n);
	if(ans){
		cout<<"found it"<<endl;
	}
	else{
		cout<<"not found";
	}
}
