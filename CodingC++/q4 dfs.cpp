#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component){
     component.push_back(node);
     visited[node]=1;
     for(auto i:adj[node]){
         if(!visited[i]){
           dfs(i,visited,adj,component);
         }  
     }
}
vector<vector<int> > depthFirstsearch(int V, vector<vector<int> >& edges) {
    // Create an adjacency list with n vectors (one for each node)
    unordered_map<int,list<int>> adj;
    
    // Fill the adjacency list
    for(int i = 0; i <edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    vector<vector<int> >ans;
    unordered_map<int,bool> visited;
    
    for(int i=0;i<V;i++){
       if(!visited[i]){
          vector<int> component;
          dfs(i,visited,adj,component);
          ans.push_back(component);
       } 
    }
    
    return ans;
}


int main() {
    int V;

    cout << "Enter the number of vertices: ";
    cin >> V;
    int m;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> result = depthFirstsearch(V, edges);

    // Print all the connected components
    cout << "Connected components are: " << endl;
    for (auto component : result) {
        for (auto node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

