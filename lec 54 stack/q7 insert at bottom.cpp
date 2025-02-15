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




int main(){
    stack<int>s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);



}
