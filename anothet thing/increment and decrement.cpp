#include <iostream>
using namespace std;

int main() {
    int i = 0;

    // Using post-increment operator
    int a = i++;  // a gets the value of i (0) and then i gets incremented to 1
    cout << "Using i++:" << endl;
    cout << "a: " << a << ", i: " << i << endl;  // Output: a: 0, i: 1

    // Using explicit addition
    i = 0;  // Reset i to 0
    int b = i = i + 1;  // i is incremented by 1 and then assigned to b
    cout << "\nUsing i = i + 1:" << endl;
    cout << "b: " << b << ", i: " << i << endl;  // Output: b: 1, i: 1

    return 0;
}

