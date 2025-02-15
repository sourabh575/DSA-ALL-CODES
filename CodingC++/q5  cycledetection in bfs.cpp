#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

bool iscyclebfs(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
       unordered_map<int,int>parent;
       parent[src]= -1;
       visited[src] =1;
       
       queue<int> q;
       q.push(src);
       
       while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto neighbour : adj[front]){
                if(visited[neighbour] && neighbour!= parent[front]){
                   return true;
                }
                else if(!visited[neighbour]){
                     q.push(neighbour);
                     visited[neighbour]=1;
                     parent[neighbour]=front;
                }
            }
       }
       return false;
       
}

string cycledetection(vector<vector<int> >&edges,int n, int m) {
    // Create an adjacency list with n vectors (one for each node)
    unordered_map<int,list<int>> adj;
    
    // Fill the adjacency list
    for(int i = 0; i <edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
       if(!visited[i]){
          bool ans=iscyclebfs(i,visited,adj);
          if(ans==1){
            return "yes";
            //break;    
          }
       } 
    }
    
    return "No";
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
    cout<<cycledetection(edges,n,m);
    
}

