#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define the node class to hold data, row index, and column index
class node {
public:
    int data;
    int i, j;

    node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

// Define a comparison class for the priority queue (min heap)
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;  // Use > for a min heap to get the smallest element on top
    }
};

// Function to merge k sorted arrays
vector<int> mergeksortedarrays(vector<vector<int>>& karrays, int k) {
    priority_queue<node*, vector<node*>, compare> minheap;
    vector<int> ans;  // Resultant merged array

    // Step 1: Insert the first element of each array into the min heap
    for (int i = 0; i < k; i++) {
        if (!karrays[i].empty()) {  // Check if the array is not empty
            node* tmp = new node(karrays[i][0], i, 0);
            minheap.push(tmp);
        }
    }

    // Step 2: Extract the minimum element from the heap and add the next element from the same array
    while (!minheap.empty()) {
        node* tmp = minheap.top();
        ans.push_back(tmp->data);
        minheap.pop();

        int i = tmp->i;
        int j = tmp->j;

        // If there is a next element in the same array, push it into the min heap
        if (j + 1 < karrays[i].size()) {
            node* next = new node(karrays[i][j + 1], i, j + 1);
            minheap.push(next);
        }
    }

    return ans;
}

int main() {
    // Example input: 3 sorted arrays
    vector<vector<int>> karrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int k = karrays.size();

    // Merge k sorted arrays
    vector<int> result = mergeksortedarrays(karrays, k);

    // Print the merged and sorted array
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
