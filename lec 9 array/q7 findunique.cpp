#include<iostream>
using namespace std;
int findunique(int *arr,int size){
	int ans=0;
	for(int i=0;i<size;i++){
		ans=ans^arr[i];
	}
	return ans;
}
int main(){
	int arr[5]={1,1,2,2,9};
	int answer=findunique(arr,5);
	cout<<answer;
	
}
