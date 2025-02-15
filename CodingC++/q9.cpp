#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
using namespace std;
void topsort(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){
     visited[node]=1;
     for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
          topsort(neighbour,visited,s,adj);
        }
     } 
     //imp
     s.push(node);
}

vector<int> topologicalsort(vector<vector<int>> &edges,int V){
     unordered_map<int,list<int> >adj;
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][v];
        
        adj[u].push_back(v); 
     }
     //call dfs topology sort util function for all component
     unordered_map<int,bool> visited;
     stack<int> s;
     for(int i=0;i<V;i++){
        if(!visited[i]){
          topsort(i,visited,s,adj);
        }
     }
     vector<int> ans;
     while(!s.empty()){
          ans.push_back(s.top());
          s.pop();
     }
     return ans;
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