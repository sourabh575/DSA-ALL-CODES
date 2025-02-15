#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextsmallerelement(vector<int>arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]=s.top();
        s.push(i);
    }
    return ans;


}
vector<int> prevsmallerelement(vector<int>arr,int n){
        stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int largerectanglearea(vector<int>& height){
    int n=height.size();

    vector<int> next(n);
    next=nextsmallerelement(height,n);

    vector<int> prev(n);
    prev=prevsmallerelement(height,n);

    int area=-10;
    for(int i=0;i<n;i++){
        int l=height[i];

        if(next[i]==-1){
            next[i]=n;
        }
         int b=next[i]-prev[i]-1;
        int newarea=l*b;
        area=max(area,newarea);
    }
    return area;

}


int main(){
    vector<int>height={2,1,5,6,2,3};
    cout<<"The largest area is:"<<largerectanglearea(height)<<endl;

}
