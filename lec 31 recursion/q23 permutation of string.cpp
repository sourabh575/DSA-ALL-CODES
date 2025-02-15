#include<iostream>
#include<vector>
using namespace std;
void solve(string& nums,vector<string>& ans,int index){
	//base case
	if(index>=nums.size()){
		ans.push_back(nums);
		return;
	}
	for(int j=index;j<nums.size();j++){
		swap(nums[index],nums[j]);
		solve(nums,ans,index+1);
		//backtrack
		swap(nums[index],nums[j]);
		
	}
}

vector<string> permute(string& nums){
	vector<string> ans;
	int index=0;
	 solve(nums, ans, index);
	

	return ans;
}



int main(){
    string nums="abc";
	vector<string> result=permute(nums);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	
	
	
}
