#include <iostream>
#include<vector>
using namespace std;

bool issafe(int newx,int newy,vector<vector<bool> > &vis,vector<vector<int> >&arr,int n){
          if((newx>=0 && newx<n) && (newy>=0 && newy<n) && vis[newx][newy] !=1 && arr[newx][newy]==1){
              return true;
          }
          else{
                 return false;
          }
}

void solve(int x,int y,vector<vector<int> >&arr,int n,vector<string> &ans,vector<vector<bool> >&vis,string path){
        //base case
        if(x==n-1 && y==n-1){
           ans.push_back(path);
           return;
        }
        
        //4 movement
        //D,L,R,U
        
        //down
        if(issafe(x+1,y,vis,arr,n)){
           vis[x][y]=1;
           solve(x+1,y,arr,n,ans,vis,path + 'D');
           vis[x][y]=0;
        }
        
        
         //left
        if(issafe(x,y-1,vis,arr,n)){
           vis[x][y]=1;
           solve(x,y-1,arr,n,ans,vis,path + 'L');
           vis[x][y]=0;
        }
        
        //right
        if(issafe(x,y+1,vis,arr,n)){
           vis[x][y]=1;
           solve(x,y+1,arr,n,ans,vis,path + 'R');
           vis[x][y]=0;
        }
        
        
        //up
        if(issafe(x-1,y,vis,arr,n)){
           vis[x][y]=1;
           solve(x-1,y,arr,n,ans,vis,path + 'U');
           vis[x][y]=0;
        }
        
}

vector<string> searchMaze(vector<vector<int> >&arr,int n){
          vector<string> ans;
          vector<vector<bool> >visited (n, vector<bool> (n,0));
          string path="";
          if(arr[0][0] == 0){
               return ans;
           }
          
          solve(0,0,arr,n,ans,visited,path);
          return ans;
          
}

int main(){
       vector<vector<int> >arr={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
       int n=arr.size();
       
       vector<string>str=searchMaze(arr,n);
       for(int i=0;i<str.size();i++){
             cout<<str[i];
             cout<<endl;
       }
      
}