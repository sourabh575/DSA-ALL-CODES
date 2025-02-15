#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr,int n){
	for(int i=1;i<n;i++){
		//for round 1 to n-1
		bool swapped=false;
		
		for(int j=0;j<n-i;j++){
			
			//processing element till n-1 th index
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		if(swapped==false){
			//already sorted
			break;
		}		
	}
	for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
	}
	
}
int main(){
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(1);
	bubbleSort(arr,5);

}
