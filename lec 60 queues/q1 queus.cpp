#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);

    q.push(5);

    q.push(7);

    q.push(10);

    q.push(12);

    cout<<"size of queue is:"<<q.size()<<endl;

    q.pop();
    cout<<"after pop:"<<q.front()<<endl;
    q.pop();
    cout<<"after pop:"<<q.front()<<endl;
    cout<<"size of queue is:"<<q.size()<<endl;
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }



}
