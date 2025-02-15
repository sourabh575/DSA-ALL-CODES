#include<iostream> 
#include<set>
using namespace std;

int main(){
    set<int>s;

    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(5);

    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<"after erase:"<<endl;
    set<int>::iterator it=s.begin();
    it++;

    s.erase(s.begin());
    for(auto i:s){
        cout<<i<<endl;
    }

    cout<<"6 is present or not:"<<s.count(6)<<endl;

    set<int>::iterator itr=s.find(5);
    for(auto it=itr; it!=s.end();it++){
        cout<<*it<<" ";
    }



}