#include<iostream>
#include<stack>
using namespace std;

int main(){

    //creation of stack
    stack<int> s;
//insert a value
    s.push(5);
    s.push(9);
    s.push(4);
    s.push(3);

    s.pop();
    s.pop();

    cout<<"top element is:"<<s.top()<<endl;
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    cout<<"size of stack is:"<<s.size()<<endl;




    return 0;

}




