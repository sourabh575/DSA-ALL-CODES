#include<iostream>
using namespace std;

void solve(int nums[],int output[],int index,int &ans[][]){
	//base case
	if(index>=nums.size()){
		ans[index]=output;
	}
	
	//exclude
	solve(nums,output,index+1,ans);
	
	//include
	int element=nums[index];
	int output[index]=element ;
	solve(nums,output,index+1,ans);
	
}	
	

int subsets(int &nums){
	int ans[][];
	int output[];
	int index=0;
	solve(nums,output,index,ans);
	return ans;
}

int main(){
	int nums[3]={1,2,3};
	
	cout<<subsets(nums)<<" ";
	
	
}
