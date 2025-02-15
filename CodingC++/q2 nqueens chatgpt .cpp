#include<iostream>
#include<vector>
using namespace std;

void addsolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool issafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;
    
    // Check for the same row on the left side
    while (y >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
    }
    
    // Check upper diagonal on the left side
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    
    // Check lower diagonal on the left side
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    // Base case: if all queens are placed
    if (col == n) {
        addsolution(ans, board, n);
        return;
    }
    
    // Try placing this queen in all rows one by one
    for (int row = 0; row < n; row++) {
        if (issafe(row, col, board, n)) {
            // Place the queen
            board[row][col] = 1;
            
            // Recur to place the rest of the queens
            solve(col + 1, ans, board, n);
            
            // Backtrack and remove the queen
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nqueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    
    solve(0, ans, board, n);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> result = nqueens(n);
    
    // Print all the solutions
    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < n * n; j++) {
            cout << result[i][j] << " ";
            if ((j + 1) % n == 0) cout << endl;
        }
        cout << endl;
    }

    return 0;
}