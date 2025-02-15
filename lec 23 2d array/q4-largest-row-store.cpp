#include<iostream>
#include<climits>

using namespace std;
void largestrowsum(int arr[][4],int i,int j){
	int maxi=INT_MIN;
	int rowidx=-1;
	
	for(int i=0;i<3;i++){
		int count=0;
		for(int j=0;j<4;j++){
			count=count+arr[i][j];
		}
		//cout<<"sum of "<<i<<" row is:"<<count<<endl;
		if(count>maxi){
			maxi=count;
			rowidx=i;
		}
	}
	cout<<"max sum of row is:"<<maxi<<endl;
	cout<<"row no.  is:"<<rowidx;
}
int main(){
	int arr[3][4]={{1,2000,3,4},{5,5,5,50},{6,5,6,5}};
	largestrowsum(arr,3,4);
}
