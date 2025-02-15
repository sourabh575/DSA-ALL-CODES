#include<iostream>
using namespace std;
bool ispresent(int arr[][4],int target ,int i,int j){
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j]==target){
				return 1;
			}
			
		}
	}
	return 0;
}
int main(){
	int arr[3][4]={{1,2,3,4},{5,5,5,5},{6,5,6,5}};
	int target;
	cin>>target;
	if(ispresent(arr,target,3,4)){
		cout<<"found"<<endl;
		
	}
	else{
		cout<<"not found";
	}
}
	
	
