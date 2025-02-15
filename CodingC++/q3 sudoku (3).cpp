#include<iostream>
#include<vector>
using namespace std;

bool issafe(int row,int col, vector<vector<int> >&board,int val){
           for(int i=0; i<board.size(); i++){
                 //row check
                 if(board[row][i]==val   || board[i][col]==val){
                     return false;
                 }
                 //3*3 matrix check
                 if(board[3*(row/3) + i/3] [3 *(col/3) + i%3] == val)
                 return false;
           } 
           return true;
}

bool solve(vector<vector<int> >& board){
           
           int n=board[0].size();
           for(int row=0; row<n; row++){
                    for(int col=0; col<n; col++){
                                   
                             //cell empty
                             if(board[row][col]==0){
                                       for(int val=1;  val<=9; val++){
                                              if(issafe(row, col, board, val)){
                                                    board[row][col]=val;
                                                    //recursive call
                                                    bool nextsolutionpossible=solve(board);
                                                    if(nextsolutionpossible)
                                                        return true;
                                                     
                                                     else{
                                                             //back tracking
                                                             board[row][col]=0;
                                                     }
                                              }
                                       }
                                       return false;
                                        
                                   }
                    }
           }
           return true;
}

void solvesudoku(vector<vector<int> >&sudoku){
          solve(sudoku);
          for(int row=0; row<9; row++){
                    for(int col=0; col<9; col++){
                            cout<<sudoku[row][col]<<" ";
                    }                               
                    cout<<endl;    
          }
          
}

int main(){
      vector<vector<int> >sudoku={{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
       solvesudoku(sudoku);      
}