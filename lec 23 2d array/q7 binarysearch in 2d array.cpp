#include<iostream>
using namespace std;
void binarysearch(int arr[][3],int row,int col,int target){
	int s=0;
	int e=row*col-1;
	int mid=s+(e-s)/2;
	while(s<=e){
		int element=arr[mid/col][mid%col];
		if(element==target){
			cout<<"found it";
		}
		if(element<target){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
		int mid=s+(e-s)/2;
	}
	cout<<"not found";

	
}
int main(){
	int arr[3][3]={1,2,3,4,5,6,7,8,9};
	binarysearch(arr,3,3,9);

}
