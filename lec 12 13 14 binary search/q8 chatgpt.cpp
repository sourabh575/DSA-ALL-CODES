#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& stall, int k, int mid) {
    int cowCount = 1;
    int lastPos = stall[0];
    for (int i = 1; i < stall.size(); i++) {
        if (stall[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPos = stall[i];
        }
    }
    return false;
}

int aggressiveCow(vector<int>& stall, int k) {
    sort(stall.begin(), stall.end());
    int low = 1, high = stall[stall.size() - 1] - stall[0], maxDist = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(stall, k, mid)) {
            maxDist = max(maxDist, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return maxDist;
}

int main() {
    // Using array
    int stallsArray[] = {4, 2, 1, 3, 6};
    int n = sizeof(stallsArray) / sizeof(stallsArray[0]);
    int k = 2;
    cout << "Using array: " << aggressiveCow(vector<int>(stallsArray, stallsArray + n), k) << endl;

    // Using vector
    vector<int> stallsVector = {4, 2, 1, 3, 6};
    cout << "Using vector: " << aggressiveCow(stallsVector, k) << endl;

    return 0;
}

