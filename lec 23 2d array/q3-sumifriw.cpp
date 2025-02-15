#include<iostream>
using namespace std;
void rowsum(int arr[][4],int i,int j){
	for(int i=0;i<3;i++){
		int count=0;
		for(int j=0;j<4;j++){
			count=count+arr[i][j];
		}
		cout<<"sum of "<<i<<" row is:"<<count<<endl;
	}
}
int main(){
	int arr[3][4]={{1,2,3,4},{5,5,5,5},{6,5,6,5}};
	rowsum(arr,3,4);
}
