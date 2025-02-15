#include<iostream>
#include<stack>
using namespace std;

int findminimumcost(string str){
    //odd condition
    stack<int>s;
    if(str.length()%2==1){
        return -1;
    }
 //even condition
 for(int i=0;i<str.length();i++){
    char ch=str[i];

    if(ch=='{')
        s.push(ch);

     else{
        //ch is closed brace
        if(!s.empty()&&!s.top()=='{ '){
            s.pop();
        }
        else{
            s.push(ch);
         }
     }

}
     int a=0,b=0;
     while(!s.empty()){
        if(s.top()=='{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
     }
     int ans=(a+1)/2+(b+1)/2;
     return ans;


 }






int main(){
    string s="}}}{{{";
    cout<<"minimum valid string is:"<<findminimumcost(s)<<endl;



}
