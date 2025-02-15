#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,stack<int> &st,unordered_map<int,list<int>> &adj){
     visited[node]=true;
     for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
          dfs(neighbour,visited,st,adj);
        }
     } 
     //imp
     st.push(node);
}

void reversedfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int> >&adj){
        vis[node] = true;
        for(auto nbr : adj[node]){
              if(!vis[nbr]){
                 reversedfs(nbr,vis,adj);
              }
        }
}

int strongconnectedcomponent(vector<vector<int>> &edges,int V){
     unordered_map<int,list<int> >adj;
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][v];
        
        adj[u].push_back(v); 
     }
     //topo sort
     unordered_map<int,bool> vis;
     stack<int> st;
     for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    //create a transpose list
    unordered_map<int,list<int> >transpose;
    for(int i=0;i<V;i++){
         vis[i] = 0;
         for(auto nbr: adj[i]){
              transpose[nbr].push_back(i);
         }
    }
    //dfs call suing above ordering
    int count=0;
    while(!st.empty()){
             int top=st.top();
             st.pop();
             if(!vis[top]){
                 count++;
                 reversedfs(top,vis,transpose) ;
             }
    }
    return count;
    
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
    
    cout<<"stong connected component "<<strongconnectedcomponent(edges,n);
    
}