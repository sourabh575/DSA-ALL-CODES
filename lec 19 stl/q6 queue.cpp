#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("sourabh");
    q.push("love");
    q.push("sakshi");
    cout<<"before pop size:"<<q.size()<<endl;
    cout<<"first element"<<q.front()<<endl;
    q.pop();
    cout<<"after pop size:"<<q.size()<<endl;
    cout<<"first element: "<<q.front()<<endl;
    
    
}
