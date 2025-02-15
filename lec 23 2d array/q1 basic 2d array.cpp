#include<iostream>
using namespace std;
int main(){
	//int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int arr[3][4]={{1,2,3,4},{5,5,5,5},{6,5,6,5}};
	//for(int i=0;i<3;i++){
	//	for(int j=0;j<4;j++){
	//		cin>>arr[i][j];
	//	}
	//}
	cout<<"output"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
