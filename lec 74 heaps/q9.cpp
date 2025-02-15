#include<iostream>
#include<vector>
#include<algorthim>
using namespace std;
int getkthlargest(vector<int> &arr){
    int n=arr.size();
    vector<int> sumstore;

    for(int i=0;i<n;i++){
            int sum=0;
        for(int j=i;j<n;j++){
            sum+= arr[j];
            sumstore.push_back(sum);

        }
    }
    sort(sumstore.begin(),sumstore.end());
    return sumstore[sumstore.size()-k];

}



int main(){
    vector<int>arr={1,2,3,4,5};
    int k=2;
    int n=5;

    cout<<"The "<<k<<" th largest element is:"<<getkthlargest(arr,k);


}
