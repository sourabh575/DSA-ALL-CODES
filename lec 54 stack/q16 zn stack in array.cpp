#include <iostream>
using namespace std;

class Nstacks {
public:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

    // Constructor
    Nstacks(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top array
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next array
        for (int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        // Update the last index to -1
        next[s - 1] = -1;

        // Initialize freespot
        freespot = 0;
    }

    bool push(int x, int m) {
        // Check for overflow
        if (freespot == -1) {
            return false;
        }

        // Step 1: Find index
        int index = freespot;

        // Step 2: Update freespot
        freespot = next[index];

        // Step 3: Insert value in an array
        arr[index] = x;

        // Update nextk
        next[index] = top[m - 1];

        // Step 4: Update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        // Check underflow condition
        if (top[m - 1] == -1) {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main() {
    // Create an instance of Nstacks with 3 stacks and total size 10
    Nstacks ns(3, 10);

    // Perform some operations
    ns.push(10, 1);
    ns.push(15, 1);
    ns.push(20, 2);

    cout << "Popped from stack 1: " << ns.pop(1) << endl; // Should output 15
    cout << "Popped from stack 2: " << ns.pop(2) << endl; // Should output 20

    return 0;
}
