#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

bool checkcycledfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    dfsvisited[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycledetected=checkcycledfs(neighbour,visited,dfsvisited,adj);
            if(cycledetected)
            return true;
        }
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    dfsvisited[node]=false;
    return false;
    
}
 
bool detectcycledirectedgraph(vector<vector<int> >&edges,int n) {
    // Create an adjacency list with n vectors (one for each node)
    unordered_map<int,list<int>> adj;
    
    // Fill the adjacency list
    for(int i = 0; i <edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    //call dfs for all component
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    
    for(int i=1;i<=n;i++){
       if(!visited[i]){
          bool cyclefound=checkcycledfs(i,visited,dfsvisited,adj);
          if(checkcycledfs){
            return true;
             
          }
       } 
    }
    
    return false;
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
    bool result=detectcycledirectedgraph(edges,n);
    if(result){
        cout<<"Yes this is cyclic directed graph";
    }
    else{
        cout<<"No";
    }
    
}