#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

vector<vector<int> >printadjlist(int n,int m,vector<vector<int> >&edges){
          vector<int> ans[n];
          //ans array will store all adjacent nodes corresponding on indexes
          for(int i=0;i<m;i++){
                int u=edges[i][0];
                int v=edges[i][1];
                
                //undirected graph
                ans[u].push_back(v);
                ans[v].push_back(u);
          }
          //output
          vector<vector<int> >adj(n);
          for(int i=0;i<n;i++){
                adj[i].push_back(i);
                
                //entering neighbours
                for(int j=0;j<ans[i].size();j++){
                      adj[i].push_back(ans[i][j]); 
                }
          }
          return adj;
}

int main(){
        int n;
        cout<<"Enter the no of nodes:";
        cin>>n;
        
        int m;
        cout<<"Enter the no of edges:";
       cin>>m;
       
       vector<vector<int> >edges={{1,2},{2,3},{3,1}};
       
       vector<vector<int> >result=printadjlist(n,m,edges);
       
       for(int i=0;i<m;i++){
       cout<<i<<"->";
            for(int j=0;j<2;j++){
                 cout<<result[i][j]<<",,";
            } 
            cout<<endl;
       }
}