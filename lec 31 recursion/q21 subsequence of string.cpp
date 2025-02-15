#include<iostream>
#include<vector>
using namespace std;

void solve(const string& str, string& output, int index, vector<string>& ans) {
    // Base case
    if (index >= str.length()) {
        ans.push_back(output);
        return;
    }

    // Exclude
    solve(str, output, index + 1, ans);

    // Include
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
    output.pop_back();
}

vector<string> subsequences(const string& str) {
    vector<string> ans;
    string output = "";
    solve(str, output, 0, ans);
    return ans;
}

int main() {
    string str = "abc";
    vector<string> result = subsequences(str);

    // Output all subsequences
    for (const auto& subseq : result) {
        cout << "[" << subseq << "]" << endl;
    }

    return 0;
}

