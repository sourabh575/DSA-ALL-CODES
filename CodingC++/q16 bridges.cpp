#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
using namespace std;

void dfs( int node; int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int> >& result,unordered_map<int,list<int> >adj,unordered_map<int , bool> &visited ){
        visited[node]=true;
        disc[node] = low[node]=timer++;
        
        for(auto nbr: adj[node]){
             if(!nbr==parent){
                continue;
             }
             if(!visited[nbr]){
                 dfs(nbr,node,timer,disc,low,result,adj,visited);
                 low[node]=min(low[node],low[nbr]);
                 
                 //check edge is bridge
                 if(low[nbr]>disc[node]){
                     vector<int> ans;
                     ans.push_back(node);
                     ans.push_back(nbr);
                     result.push_back(ans);
                 }
             }
             else{
                   //back edge
                   low[node]=min(low[node],disc[nbr]);
             }
        }
}

vector<vector<int> >Findbridges(vector<vector<int>> &edges,int v,int e){
     unordered_map<int,list<int> >adj;
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][v];
        
        adj[u].push_back(v); 
     }
     
     int timer=0;
     vector<int> disc(v);
     vector<int> low(v);
     int parent=-1;
     unordered_map<int,bool> visited;
     
     for(int i=0; i<v; i++){
          disc[i]=-1;
          low[i] =-1;
     }
     vector<vector<int> >result;
     //dfs
     for(int i=0; i<v; i++){
           if(!visited){
               dfs(i,parent,timer,disc,low,result,adj,visited);
           }
     }
     return result;
     
}

int main() {
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<int> result=topologicalsort(edges,n);
    for(int i=0;i<n;i++){
       cout<<result[i]<<" ";
    }
    
}