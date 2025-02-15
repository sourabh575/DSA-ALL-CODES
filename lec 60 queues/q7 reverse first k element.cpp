#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> reversefirstkelement(queue<int>&q,int k){
    stack<int> s;
    for(int i=0;i<k;i++){
        int x=q.front();
        q.pop();
        s.push(x);
    }
    while(!s.empty()){
        int y=s.top();
        s.pop();
        q.push(y);
    }
    int t=q.size()-k;
    while(t--){
        int z=q.front();
        q.pop();
        q.push(z);
    }

    return q;
}

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reversefirstkelement(q,3);
    for(int i=0;i<5;i++){
        cout<<q.front()<<" ";
        q.pop();
     }
}
