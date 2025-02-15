#include<iostream>
using namespace std;
int getPivot(int arr[],int n){
	int s=0,e=n-1;
	int mid=s+(e-s)/2;

	 if (arr[s] <= arr[e]) {
        return s ;
    }
	while(s<e){
		if(arr[mid]>=arr[0]){
			s=mid+1;
		}
		else{
			e=mid;
		}
		mid=s+(e-s)/2;
	}
	return s;
}
int main(){
	int arr[5]={3,8,10,17,1};
	cout<<"Index of pivot element is:"<<getPivot(arr,5)<<endl;
}

