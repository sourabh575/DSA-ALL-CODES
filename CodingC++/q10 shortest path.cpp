#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> shortestpath(vector<vector<int>>& edges, int n, int m, int s, int t) {
    unordered_map<int, list<int> > adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming the graph is undirected
    }

    // BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    parent[s] = -1;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // Prepare the shortest path
    vector<int> ans;
    int currentnode = t;
    ans.push_back(t);

    while (currentnode != s) {
        currentnode = parent[currentnode];
        ans.push_back(currentnode);
    }

    reverse(ans.begin(), ans.end()); // Reverse to get the path from s to t
    return ans;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int s = 1; // starting node
    int t = 8; // target node

    vector<int> result = shortestpath(edges, n, m, s, t);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}