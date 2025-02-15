#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,  unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,vector<int>&ap) {
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child=0;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }

        if (!visited[nbr]) {
            dfs(nbr, node, timer, disc, low,  adj, visited,ap);
            low[node] = min(low[node], low[nbr]);
            //check AP or not
            if(low[nbr]>=disc[node] && parent !=1){
                 ap[node]=1;
            }
            child++;
        }
            else{
                  low[node]=min(low[node],disc[nbr]);
            }
    }
    if(parent==-1  && child>1){
         ap[node] = 1;
    }    

}

vector<int> Findarticulationpoint(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's an undirected graph
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> visited;
    vector<int> ap(v,0);

    // DFS for every component
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, parent, timer, disc, low,  adj, visited,ap);
        }
    }

    return ap;
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

    vector<int> ap = Findarticulationpoint(edges, n, m);

    cout << "Articulation points in the graph are:" << endl;
    for (int i=0;i<n ;i++) {
           if(ap[i] !=0){
               cout<<i<<" ";
           }cout<<endl;
    
    }

    return 0;
}