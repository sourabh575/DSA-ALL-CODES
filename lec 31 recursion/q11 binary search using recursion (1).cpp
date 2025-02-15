#include<iostream>
using namespace std;
void print(int arr[],int s,int e){
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool binarysearch(int *arr,int s,int e,int key){
    print(arr,s,e);
    //base case
    if(s>e){
        return false;
    }
    int mid=(s+e)/2;
    
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]<key){
        return binarysearch(arr,mid+1,e,key);
    }
    else{
        return binarysearch(arr,s,mid-1,key);
    }
}

int main(){
    int arr[6]={4,8,12,14,15,20};
    int key = 22 ;
    int ans=binarysearch(arr,0,5,key);
    if(ans){
        cout<<"key is found";
    }
    else{
        cout<<"not found";
    }
}
