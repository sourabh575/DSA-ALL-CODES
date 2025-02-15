#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<list>
#include<queue>
using namespace std;
void prepareadjlist(unordered_map<int,set<int> >&adjlist,vector<pair<int,int> >&edges){

          for(int i=0;i<edges.size();i++){
                int u=edges[i].first;
                int v=edges[i].second;
                
                //undirected graph
                adjlist[u].insert(v);
                adjlist[v].insert(u);
          }
          
}

void bfs(unordered_map<int,set<int> >&adjlist,unordered_map<int,bool >&visited,vector<int> &ans,int node){
    queue<int> q;   
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        
        //store frontnodes into ans
        ans.push_back(frontnode);
        
        //traverse all neighbours of front node
        for(auto i:adjlist[frontnode]){
           if(!visited[i]){
             q.push(i);
             visited[i]=1;
           }
        }
    }
    
}
vector<int> BFS(int vertex,vector<pair<int,int> >edges){
       unordered_map<int,set<int> >adjlist ;
       vector<int>ans;
       
       unordered_map<int,bool >visited;
       
       prepareadjlist(adjlist,edges);
       
       //traverse all component of a graph
       for(int i=0;i<vertex;i++){
           if(!visited[i]){
              bfs(adjlist,visited,ans,i);
           }
       }
       return ans;
       
}

int main(){
    int vertex = 5; // Number of vertices
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}
    }; // Example edges in the graph

    vector<int> bfsTraversal = BFS(vertex, edges);

    cout << "BFS Traversal of the graph is: ";
    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
       
