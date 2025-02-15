#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>inputstack,int count,int size){
  //base case
  if(count==size/2){
    inputstack.pop();
    return ;
  }
  int num=inputstack.top();
  inputstack.pop();

  //recursive call
  solve(inputstack,count+1,size);

  inputstack.push(num);


}



void deletemiddle(stack<int>s,int size){
    int count=0;
    solve(s,count,size);


}


int main(){
    stack <int >s;
    s.push(3);
    s.push(5);
    s.push(9);
    s.push(2);
    s.push(4);
    int size=s.size();

    deletemiddle(s,size);






}
