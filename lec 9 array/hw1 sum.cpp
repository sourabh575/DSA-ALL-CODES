 #include<iostream>
using namespace std;
void sum(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
	}
	cout<<sum;
}


int main(){
	int arr[5]={1,2, 3, 4, 5};
	int n=5;
	sum(arr,5);

	
}
