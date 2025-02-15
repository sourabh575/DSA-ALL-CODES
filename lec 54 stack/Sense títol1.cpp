#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<long long> printfirstnegativeinteger(long long int A[],long long int N,long long int k){
    deque<long long int>dq;
    vector<long long>ans;

    //processing first window of k size
    for(int i=0;i<k;i++){
        if(A[i]<k){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    //processing for remaining windows
    for(int i=k;i<N;i++){
        //REMOVAL
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        //addition
        if(A[i]<0){
            dq.push_back(i);
        }
        if(dq.size()>0){
        ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }

    }
    return ans;


}

int main(){
    long long int A[5]={-8,2,3,-6,10};
    long long int K=;
    long long int N=5;
    vector<long long int>result=printfirstnegativeinteger(A,N,K);
    for(int i=0;i<4;i++){
        cout<<result[i]<<" ";
    }


}

