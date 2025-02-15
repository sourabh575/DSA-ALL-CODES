#include<iostream>
using namespace std;
void sum(int arr[],int n,int s){
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(arr[i]+arr[j]==s){
				cout<<arr[i]<<"+"<<arr[j]<<"="<<s;
			}
			cout<<endl;
		}
	}
}
int main(){
	int arr[5]={1,2,3,4,5};
	sum(arr,5,6);

}
