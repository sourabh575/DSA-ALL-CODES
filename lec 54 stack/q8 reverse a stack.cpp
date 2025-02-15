#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>s,int x){
    //baase case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num=s.top();
    s.pop();

    //recursive call
    solve(s,x);

    s.push(num);

}

stack<int> insertatbottom(stack<int>s,int x){
    solve(s,x);
    return s;

}

void reversestack(stack<int>s){
    //base case
    if(s.empty()){
        return;
    }

    int num=s.top();
    s.pop();

    //recursive call
    reversestack(s);
    insertatbottom(s,num);


}

int main(){
    stack<int>s;
    s.push(9);
    s.push(7);
    s.push(4);
    s.push(3);
    cout<<endl;
    reversestack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


}
