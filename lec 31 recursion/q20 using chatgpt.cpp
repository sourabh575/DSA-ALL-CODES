#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int> > & ans) {
    // Base case
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude
    solve(nums, output, index + 1, ans);

    // Include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
    output.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(nums, output, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    // Output all subsets
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

