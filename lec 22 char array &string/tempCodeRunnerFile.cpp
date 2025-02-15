#include <iostream>
#include <vector>

using namespace std;

int DanceRev(vector<string> instructions, int n) {
    int legMove = 0;
    string prev1 = instructions[0];
    string prev2 = instructions[1];

    for (int i = 2; i < n; ++i) {
        if (instructions[i] != prev1 && instructions[i] != prev2) {
            legMove++;
            prev1 = prev2;
            prev2 = instructions[i];
        }
    }

    return legMove;
}

int main() {
    int n;
    cin >> n;

    vector<string> instructions(n);
    for (int i = 0; i < n; ++i) {
        cin >> instructions[i];
    }

    cout << DanceRev(instructions, n) << endl;

    return 0;
}