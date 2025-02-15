#include <iostream>
#include<set>
#include<vector>
#include<list>

#include<climits>
#include<unordered_map>
using namespace std;

void makeset(vector<int> &parent,vector<int> &rank,int n){
     for(int i=0;i<n;i++){
         parent[i]=1;
         rank[i]=0;
     }
}
int findparent(vector<int> &parent,int node){
     if(parent[node]==node){
       return node; 
     }
     
     return parent[node]=findparent(parent,parent[node]);
}
void unionset(int u,int v,vector<int>&parent,vector<int> rank){
     u=findparent(parent,u);
     v=findparent(parent,v);
     
     if(rank[u]<rank[v]){
       parent[u]=v;    
     }
     else if(rank[v]<rank[u]){
          parent[v]=u;
     }     
     else{
        parent[v]=u; 
        rank[u]++;
     }
}

int minimumspanningtree(vector<vector<int>> &edges,int n){
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
}

int main(){
    int n=7;
    vector<vector<int>> edges(n,vector<int>(2)); 
    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout<<minimumspanningtree(edges,n);

}
