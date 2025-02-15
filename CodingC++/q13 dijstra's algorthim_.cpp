// Online C++ compiler to run C++ program online
#include <iostream>
#include<set>
#include<vector>
#include<list>

//#include<limit.h>
#include<unordered_map>

using namespace std;

vector<int> dijkstra(vector<vector<int> >&vec,int vertices,int edges,int source){

    unorderd_map<int,pair<int,int>> adj   ;
    for(int i=0;i<vertices;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        
        vec[u].push_back(make_pair(v,w));
        vec[v].push_back(make_pair(u,w));
    }
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=-1;
    }
    set<pair<int,int>>st;
    
    dist[source]=0;
    st.insert(make_pair(0,source));
    
    while(!st.empty()){
        //fetch top record
        auto top=*(st.begin());
        
        int nodedistance=top.first;
        int topnode=top.second;
        
        //remove top record now
        st.erase(st.begin());
        
        //traverse all neighbours
        for(auto neighbour: adj[topnode]){
            if(nodedistance+neighbour.second < dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                
                //if record found then erase it
                if(record !=st.end()){
                    st.erasef(f);
                }
                //distance update
                dist[neighbour.first]= nodedistance+neighbour.second;
                
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
    
    
}




int main(){
  int vertices = 5;
    // Create a vector of vectors, where each inner vector holds pairs of integers
    vector<vector<int>>vec <>;

    // Add some edges (using push_back with make_pair)
    vec[0].push_back(make_pair(1, 10));
    vec[0].push_back(make_pair(4, 20));
    vec[1].push_back(make_pair(2, 30));
    vec[2].push_back(make_pair(3, 40));
    vec[3].push_back(make_pair(4, 50));
    
    
    vector<int>result=dijkstra(vec,vertices,7,0);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
}