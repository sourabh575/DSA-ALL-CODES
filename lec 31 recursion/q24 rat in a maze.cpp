#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool issafe(int x, int y, int n, vector<vector<int> >& visited, vector<vector<int> >& m) {
    return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
}

void solve(vector<vector<int> >& m, int n, string& ans, int scrx, int scry, vector<vector<int> >& visited, string path) {
    if (scrx == n - 1 && scry == n - 1) {
        ans = path;
        return;
    }
    visited[scrx][scry] = 1;

    int newx, newy;

    // Down
    newx = scrx + 1;
    newy = scry;
    if (issafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
      //  path.pop_back();
      path.erase(path.size()-1);
  }

    // Left
    newx = scrx;
    newy = scry - 1;
    if (issafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.erase(path.size()-1);
    }

    // Right
    newx = scrx;
    newy = scry + 1;
    if (issafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.erase(path.size()-1);
    }

    // Up
    newx = scrx - 1;
    newy = scry;
    if (issafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.erase(path.size()-1);
    }

    visited[scrx][scry] = 0;
}

string findpath(vector<vector<int> >& m, int n) {
    string ans;
    if (m[0][0] == 0) {
        return ans;
    }

    int srcx = 0, srcy = 0;
    vector<vector<int> > visited(n, vector<int>(n, 0)); // Initialize with zeros

    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int> > m = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    
    int n = 4;
    string result = findpath(m, n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}

