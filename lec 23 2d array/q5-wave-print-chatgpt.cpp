#include<iostream>
#include<vector>
using namespace std;

vector<int> waveprint(vector<vector<int> > arr, int nrow, int mcol) {
    vector<int> ans;
    for (int col = 0; col < mcol; col++) {
        if (col & 1) {
            for (int row = nrow - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        else {
            for (int row = 0; row < nrow; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > arr = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};
    vector<int> result = waveprint(arr, 3, 4);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

