#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool issafe(int x, int y, int n, int visited[][4], int m[][4]) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    } else {
        return false;
    }
}

void solve(int m[][4], int n, string &ans, int scrx, int scry, int visited[][4], string path) {
    if (scrx == n - 1 && scry == n - 1) {
        ans = path; // Update ans directly with the current path
        return;
    }
    visited[scrx][scry] = 1;

    int newx, newy;

    // Down
    newx = scrx + 1;
    newy = scry;
    if (issafe(newx, newy, n, visited, m)) {
        solve(m, n, ans, newx, newy, visited, path + 'D'); // Append 'D' to path and pass it to the next recursive call
		//path.erase(path.size()-1);
    }

    // Left
    newx = scrx;
    newy = scry - 1;
    if (issafe(newx, newy, n, visited, m)) {
        solve(m, n, ans, newx, newy, visited, path + 'L'); // Append 'L' to path and pass it to the next recursive call
    }

    // Right
    newx = scrx;
    newy = scry + 1;
    if (issafe(newx, newy, n, visited, m)) {
        solve(m, n, ans, newx, newy, visited, path + 'R'); // Append 'R' to path and pass it to the next recursive call
    }

    // Up
    newx = scrx - 1;
    newy = scry;
    if (issafe(newx, newy, n, visited, m)) {
        solve(m, n, ans, newx, newy, visited, path + 'U'); // Append 'U' to path and pass it to the next recursive call
    }

    visited[scrx][scry] = 0;
}

string findpath(int m[][4], int n) {
    string ans;
    if (m[0][0] == 0) {
        return ans;
    }

    int srcx = 0, srcy = 0;
    int visited[4][4] = {0}; // Initialize with zeros

    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    return ans;
}

int main() {
    int m[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    string result = findpath(m, n);
    cout << result << endl;
    return 0;
}

