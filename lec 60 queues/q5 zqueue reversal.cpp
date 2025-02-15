#include<iostream>
#include<queue>
using namespace std;
void reversequeue(queue<int>q){
//base case
if(q.empty()){
    return;
}s
int x=q.front()
q.pop();

reversequeue(q);
insertatbottom(q,x);
}


int main(){
    queue <int> q;
    q.push(4);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(5);
    q.push(6);
    reversequeue(q);

}
