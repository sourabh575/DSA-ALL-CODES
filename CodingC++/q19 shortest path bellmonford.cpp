#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
using namespace std;

int bellmonford(int src,vector<vector<int>> &edges,int n,int m,int dest){
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    
    //n-1 times
    for(int i=1;i<=n;i++){
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            
            if(dist[u] != 1e9 &&((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }
    //check for negative cycle
    bool flag=0;
    for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            
            if(dist[u] != 1e9 &&((dist[u]+wt)<dist[v])){
                flag=1;
            }
    }
    if(flag==0){
        return dist[dest];
    }
    return -1;
     
    
}

int main() {
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1]>>edges[i][2];
    }
    
    cout<<"shortest path is "<<bellmonford(1,edges,n,m,3);
}