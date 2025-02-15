/*#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
	int mid=(s+e)/2;
	
	int len1=mid-s+1; 
	int len2=e-mid;
	
	int *first=new int[len1];
	int *second=new int[len2];
	
	//copy values;
	int mainarrayindex=s;
	for(int i=0;i<len1;i++){
		first[i]=arr[mainarrayindex++];
	}
	mainarrayindex=mid+1;
	for(int i=0;i<len2;i++){
		second[i]=arr[mainarrayindex++];
	}
	
	//merge 2 sorted array
	int index1=0;
	int index2=0;
	mainarrayindex=s;
	
	while(index1<len1 && index2<len2){
		if(first[index1]<second[index2]){
			arr[mainarrayindex++]=first[index1++];
			
		}
		
		else{
			arr[mainarrayindex++]=second[index2++];
		}
	}
	while(index1<len1){
		arr[mainarrayindex++]=first[index1++];
	}
	while(index2<len2){
		arr[mainarrayindex++]=second[index2++];
	}	
}*/

// void mergesort(int *arr,int s,int e){
// 	//base case
// 	if(s>=e){
// 		return;
// 	}
// 	int mid=(s+e)/2;
	
// 	//left part sort krna hai
// 	mergesort(arr,s,mid);
	
// 	//right part sort krna hai
// 	mergesort(arr,mid+1,e);
	
// 	//merge
// 	merge(arr,s,e);
// }

// int main(){
// 	int arr[7]={38,27,43,3,9,82,10};
// 	mergesort(arr,0,6);
// 	for(int i=0;i<7;i++){
// 		cout<<arr[i]<<" ";
// 	}
// }
// //better version
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int s,int e){
     int mid = s + (e - s) / 2;

    int i = s;
    int j = mid + 1;
    
    int n = mid;
    int m = e;
    
    vector<int>temp;
  
    
    while(i<=n && j<=m){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i<=n){
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j<=m){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+s] = temp[idx];
    }
}

void mergesort(vector<int>& arr,int s,int e){
    if(s>=e){
        return;
    }
   int mid = s + (e - s) / 2;
    //left part
    mergesort(arr,s,mid);
    
    //right part
    mergesort(arr,mid+1,e);
    
    merge(arr,s,e);
}
	



int main(){
	vector<int>arr={38,27,43,3,9,82,10};
	mergesort(arr,0,6);
	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}
};
