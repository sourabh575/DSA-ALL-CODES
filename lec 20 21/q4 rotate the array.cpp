#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>&v,int n,int k){
	vector<int>temp(n);
	for(int i=0;i<n;i++){
		temp [(i+k)%n]=v[i];
	}
	v=temp;
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}
int main(){
	vector<int>v;
	v.push_back(-1);
	v.push_back(100);
	v.push_back(3);
	v.push_back(99);
	v.push_back(15);
	rotate(v,5,3);
	return 0;
	
	
}
