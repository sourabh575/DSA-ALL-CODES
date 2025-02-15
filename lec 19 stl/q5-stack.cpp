#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> s;
    s.push("sourabh");
    s.push("love");
    s.push("sakshi");
    cout<<"Top element"<<s.top()<<endl;
    s.pop();
    cout<<"size of stack:"<<s.size()<<endl;
    cout<<"empty or not"<<s.empty()<<endl;
}
