#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int stall[],int n,int k,int mid){
	int cowcount=1;
	int lastpos=stall[0];
	for(int i=0;i<n;i++){
		if(stall[i]-lastpos>=mid){
			cowcount++;
			if (cowcount==k){
				return true;
			}
			lastpos=stall[i];
		}
	}
	return false;
}
int aggressivecow(int stall[],int n,int k){
	sort(stall,stall+n);
	int s=0;
	int maxi=-1;
	for(int i=0;i<n;i++){
		maxi=max(maxi,stall[i]);
	}
	int e=maxi;
	int ans=-1;
	int mid=s+(e-s)/2;
	while(s<=e){
		if(isPossible(stall,n,k,mid)){
			ans=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
	
}
int main(){
	int stalls[5]={4,2,1,3,6};
	cout<<aggressivecow(stalls,5,2);
}

