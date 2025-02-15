 #include<iostream>
using namespace std;
void update(int arr[],int n){
	cout<<endl<<"printing the array in update function"<<endl;
	arr[0]=125;
	for(int i=0;i<=3;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[3]={1,2,3};
	int n=3;
	update(arr,3);
	cout<<endl<<"printing the array in main function"<<endl;
	for(int i=0;i<=3;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
}
