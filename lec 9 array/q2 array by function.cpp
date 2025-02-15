#include<iostream>
using namespace std;
void printarray(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}


int main(){
	int third[15]={2,7};
	int n=15;
	printarray(third,15);
	int fourth[10]={5};
	printarray(fourth,10); 
}

