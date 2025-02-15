#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int nextsmallerelement(int *arr,int n){
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
int prevsmallerelement(int *arr,int n){
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

int largerectanglearea(int *height,int m){
   // int n=height.size();

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
int maxarea(vector<vector<int> >M[max][max],int n,int m){
    int area=largerectanglearea(M[0],m);

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            //row update
            if(M[i][j]!=0)
            M[i][j]=M[i][j]+M[i-1][j];
            else
                M[i][j]=0;
        }
        area=max(area,largestrectanglearea(M[i],m);

    }
    return area;

}

int main(){
    vector<vector<int> >M={{0,1,1,0}{1,1,1,1}{1,1,1,1}{1,1,0,0}};
    cout<<"largest rectangle area by 1's":<<maxarea(M,4,4);


}

