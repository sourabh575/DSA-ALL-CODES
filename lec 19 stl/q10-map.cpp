#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int main(){
   

    map<string,int>m;
    m["tv"]=1;
    m["smartphone"]=2;
    m["laptop"]=100;
    m["tv"]=1;
    m.insert({"mobile",25});
    m.emplace("camera",100);
    m.erase("tv");
    

    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    // find if it is found then it gove itreator of that location or we can say address and not found then it will give next element itreator of that element
    if(m.find("camera")!=m.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"not found";
    }

    cout<<m.count("tv")<<endl;
    cout<<"multi map"<<endl;
    
    multimap<string,int>mm;
    mm.emplace("tv",100);
    mm.emplace("tv",100);
    mm.emplace("tv",100);
    mm.emplace("tv",100);

    for(auto p:mm){
        cout<<p.first<<" "<<p.second<<endl;
    }

   cout<<"unordered map"<<endl;
    unordered_map<string,int>um;
     um["tv"]=1;
    um["smartphone"]=2;
   um["laptop"]=100;
    um["tv"]=1;
    um.insert({"mobile",25});
    um.emplace("camera",100);
    um.erase("tv");

    for(auto p:um){
        cout<<p.first<<" "<<p.second<<endl;
    }









}