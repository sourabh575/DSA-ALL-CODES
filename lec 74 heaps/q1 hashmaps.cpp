#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<string,int>m;

    //insertiom
    //1st way
    pair<string,int>pair1=make_pair("babbar",3);
    m.insert(pair1);

    //2nd way
    pair<string,int>pair2=make_pair("love",2);
    m.insert(pair2);

    //3rd way
    m["mera"]=1;

    //updation
    m["mera"]=2;

    //searching  entry;
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

   // cout<<m.at("unknownkey")<<endl;
    cout<<m["unknownkey"]<<endl;
   cout<<m.at("unknownkey")<<endl;

   //size;
   cout<<m.size()<<endl;

   cout<<m.count("love")<<endl;

   //erase
   m.erase("love");

   cout<<m.size()<<endl;

   for(auto i:m){
       cout<<i.first<<" "<<i.second<<endl;

   }

   //itreator
   unordered_map<string,int> :: iterator it=m.begin();
   while(it !=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
   it++;

   }


}
