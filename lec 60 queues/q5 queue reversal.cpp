#include<iostream>
#include<queue>
#include<stack>
using namespace std;


int main(){
    queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.front()<<" " ;
        int x=q.front();
        s.push(x);
        q.pop();
    }
    cout<<endl;
    while(!s.empty()){
        int y=s.top();
        q.push(y);
        s.pop();
    }
     while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();

     }


}
