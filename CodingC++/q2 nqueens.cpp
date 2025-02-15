#include<iostream>
#include<vector>
using namespace std;

void addsolution(vector<vector<int> > &ans,vector<vector<int> > & board,int n){
      vector<int> temp;
      
      for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                 temp.push_back(board[i][j]);
           }
      }
      ans.push_back(temp);
}

bool issafe(int row,int col,vector<vector<int> > &board,int n){
         int x=row;
         int y=col;
         
         //check for same row
         while(y>=0){
                 if(board[x][y]==1)
                     return false;
                     y--;
         }
         x=row;
         y=col;
         
         //check for diagonal
         while(x>=0 && y>=0){
                 if(board[x][y]==1)
                     return false;
                     x--;
                     y--;
         }
         
         while(x<n && y>=0){
                 if(board[x][y]==1)
                     return false;
                     x++;
                     y--;
         }
         //all safe
         return true;
         
         
}

void solve(int col,vector<vector<int> > &ans,vector<vector<int> > &board,int n){
        //base case
        if(col==n){
             addsolution(ans,board,n);
             return;
        }
        
        //solve 1 case and rest recursion will handle
        
        for(int row=0; row<n;row++){
               if(issafe(row,col,board,n)){
                   //if placing queen is safe
                   board[row][col] = 1;
                   solve(col+1,ans,board,n);
                   //backtrack
                   board[row][col] = 0;
               }
        }
}

vector<vector<int> >nqueens(int n){
           vector<vector<int> > board(n,vector<int>(n,0)) ;
           vector<vector<int> > ans;
           
           solve(0,ans,board,n);
           return ans;             
}
int main(){
    int n = 4;
    vector<vector<int> > result = nqueens(n);

    for(int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << result[i][j * n + k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}



