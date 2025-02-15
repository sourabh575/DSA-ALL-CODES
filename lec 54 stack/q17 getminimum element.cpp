#include<iostream>
#include<stack>
using namespace std;
class specialstack{
    stack<int>s;
    int mini;

public:
    void push(int data){
        //first element
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else{
            if(data<mini){
                s.push(2*data-mini);
                mini=data;
            }
            else{
                s.push(data);
            }
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int curr=s.top();
        s.pop();
        if(curr>mini){
            return curr;
        }
        else{
            int prevmin=mini;
            int val=2*mini-curr;
            mini=val;
            return prevmin;
        }
    }
    int top(){
        if(s.empty())
            return -1;

            int curr=s.top();
            if(curr<mini){
                return mini;
            }
            else{
                return curr;
            }
        }

        bool isempty(){
            return s.empty();

        }
        int getmin(){
            if(s.empty())
                return -1;

            return mini;
        }



};

int main(){
    specialstack s;
    s.push(5);
    cout<<s.top()<<endl;
    s.push(3);
    cout<<s.top()<<endl;
    s.push(8);
    cout<<s.top()<<endl;
    s.push(2);
    cout<<s.top()<<endl;
    s.push(4);
    cout<<s.top()<<endl;

    s.pop();
    cout<<"minimum element is:"<<s.getmin()<<endl;
    s.pop();
    cout<<"minimum element is:"<<s.getmin()<<endl;



}
