#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> printadjlist(int n, int m, vector<vector<int>> edges) {
    // Create an adjacency list with n vectors (one for each node)
    vector<vector<int>> adj(n);
    
    // Fill the adjacency list
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // Since it's an undirected graph, add an edge from u to v and from v to u
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return adj;
}

int main() {
    int n, m;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    cout << "Enter the number of edges: ";
    cin >> m;
    
    vector<vector<int>> edges(m, vector<int>(2));
    
    cout << "Enter the edges (u v format):" << endl;
    for(int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<vector<int>> result = printadjlist(n, m, edges);
    
    // Print the adjacency list
    for(int i = 0; i < n; i++) {
        cout << i << "-> ";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if(j != result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }

    return 0;
}

