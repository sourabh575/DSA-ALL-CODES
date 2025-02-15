#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
string firstnonrepeating(string A){
    unordered_map<char,int>count;
    queue<int>q;
    string ans="";
    for(int i=0;i<A.length();i++){
        char ch=A[i];

        //increase count
        count[ch]++;

        //queue meh push krdo
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()]>1){
                //repeating character
                q.pop();
            }
            else{
                //non repeaing
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
            ans.push_back('#');
    }
    return ans;

}

int main(){
    string A="aabc";
    //string result=firstnonrepeating(A);
   cout<<firstnonrepeating(A);

}
