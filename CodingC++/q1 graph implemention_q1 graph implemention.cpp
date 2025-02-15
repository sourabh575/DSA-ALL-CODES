#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
     public:
     unordered_map<int, list<int> >adj;
     
     void addedge(int u,int v,bool direction){
          //direction=0->undirected graph
          //direction=1->directed graph
          
          //create an edge from u to v
          adj[u].push_back(v);
          if(direction== 0){
               adj[v].push_back(u);
          }
     }
     
               void printadjlist(){
                 for(auto i:adj){
                      cout<<i.first<<"->";
                          for(auto j:i.second){
                                cout<<j<<",";
                          }
                          cout<<endl;
                 }
          }

};

int main(){
        int n;
        cout<<"Enter the no of nodes:";
        cin>>n;
        
        int m;
        cout<<"Enter the no of edges:";
       cin>>m;
       
       graph g;
       
       for(int i=0;i<m;i++){
             int u,v;
             cin>>u >>v;
             //creating an undirected graph
             g.addedge(u,v,0);
       }
       //print the graph
       g.printadjlist();

}