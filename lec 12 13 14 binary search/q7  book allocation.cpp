#include<iostream>
using namespace std;	
bool isposible(int arr[],int n,int m,int mid){
	int studentcount=1;
	int pagesum=0;
	for(int i=0;i<n;i++){
		if( pagesum + arr[i] <= mid){
			pagesum += arr[i];
		}
		else{
			studentcount++ ;
		    if(studentcount>m ||arr[i]>mid){
			return false;
		    }
		pagesum=arr[i];
	   }
    }
	return true;
}

void allocatebooks(int arr[],int n,int m){
	int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
    	sum=arr[i]+sum;
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
    	if(isposible(arr,n,m,mid)){
    		ans=mid;
    		e=mid-1;
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
		
	}
	cout<<ans;
}


int main(){
	int arr[6]={15,30,60,75,45,20};
	allocatebooks(arr,6,3);

}
