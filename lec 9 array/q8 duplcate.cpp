#include<iostream>
using namespace std;
void finduplicate(int arr[],int size){
	int ans=0;
	for(int i=0;i<size;i++){
		ans=ans^arr[i];
	}
	for(int i=1;i<size;i++){
		ans=ans^i;
	}
	cout<<ans;
}


int main(){
	int arr[5]={12,3,2,5,3};
	finduplicate(arr,5);
}
