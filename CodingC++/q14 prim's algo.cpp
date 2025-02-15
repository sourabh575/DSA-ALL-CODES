#include <iostream>
#include<set>
#include<vector>
#include<list>

#include<climits>
#include<unordered_map>
using namespace std;

//prism's algo
vector<pair<pair<int,int>,int> > calculatepathmst(int n,int m,vector<pair<pair<int,int>,int> > &g){
      //create adjlist
      unordered_map<int,list<pair<int,int> > >adj;
      for(int i=0;i<g.size();i++){
         int u=g[i].first.first;
         int v=g[i].first.second;
         int w=g[i].second;
         
         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));
      }
      vector<int> key(n+1);
      //n+1 because i want to start with 1
      vector<bool> mst(n+1);
      vector<int>parents(n+1);
      
      for(int i=0;i<=n;i++){
         key[i]=INT_MAX;
         parents[i]=-1;
         mst[i]=false;
      }
      
      //lets start algo
      key[1]=0;
      parents[1]=-1;
      
      for(int i=1;i<=n;i++){
         int mini=INT_MAX;
         int u;
         
         //find the main vali node
         for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
              u=v;
              mini=key[v];
            } 
         }
         
         //mark min node as true
         mst[u]=true;
         
         //chek its adjacent nodes
         for(auto it: adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                parents[v]=u;
                key[v]=w; 
            }
         }
      }
      vector<pair<pair<int,int>,int> > result;
      for(int i=2;i<=n;i++){
          result.push_back({{parents[i],i},key[i]});
          
      }
      return result;
      
      
      

}
//int main(){
  /*  vector<pair<pair<int, int>, int>> edges;
    edges.push_back(make_pair(make_pair(0, 1), 2));
    edges.push_back(make_pair(make_pair(0, 3), 6));
    edges.push_back(make_pair(make_pair(1, 2), 3));
    edges.push_back(make_pair(make_pair(1, 3), 8));
    edges.push_back(make_pair(make_pair(1, 4), 5));
    edges.push_back(make_pair(make_pair(2, 4), 7));
    int  n=5;
    int m=6;
    vector<pair<pair<int,int>,int> > result=calculatepathmst(n,m,edges);
    for(int i=0;i<n;i++){
        cout<<"("<<result[i].first.first<<","<<result[i].first.second<<") "<<result[i].second;
        cout<<endl;
    } 
}
*/
int main() {
    vector<pair<pair<int, int>, int>> edges;
    edges.push_back(make_pair(make_pair(1, 2), 2));
    edges.push_back(make_pair(make_pair(1, 4), 6));
    edges.push_back(make_pair(make_pair(2, 3), 3));
    edges.push_back(make_pair(make_pair(2, 4), 8));
    edges.push_back(make_pair(make_pair(2, 5), 5));
    edges.push_back(make_pair(make_pair(3, 5), 7));
    int n = 5;
    int m = 6;
    vector<pair<pair<int,int>,int> > result = calculatepathmst(n,m,edges);
    for(int i=0; i<n-1; i++) {  // You need to print n-1 edges for a MST
        cout<<"("<<result[i].first.first<<","<<result[i].first.second<<") "<<result[i].second;
        cout<<endl;
    } 
}
    






    