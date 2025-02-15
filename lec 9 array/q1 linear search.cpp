#include<iostream>
using namespace std;
bool search(int arr[],int size,int key){
	for(int i=0;i<size;i++){
		if(arr[i]==key){
			return 1;
		}
	}
	return 0;
}
int main(){
	int arr[10]={4,6,5,2,9,63,45,552,566,6};
	int key;
	cout<<"enter a key:";
	cin>>key;
	bool found=search(arr,10,key);
	if(found){
		cout<<"key is present"<<endl;
	}
	else{
		cout<<"key is absent";
	}
	
}
