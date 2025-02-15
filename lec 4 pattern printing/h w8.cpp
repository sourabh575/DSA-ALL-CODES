#include <iostream>

int main() {
    int n;

    // Input the number of rows
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    // Loop for each row
    for (int i = 1; i <= n; ++i) {
        // Print numbers in ascending order
        for (int j = 1; j <= i; ++j) {
            std::cout << j << " ";
        }

        // Print '*' for the remaining spaces
        for (int k = 1; k <= (n - i) * 2; ++k) {
            std::cout << "* ";
        }

        // Print numbers in descending order
        for (int j = i; j >= 1; --j) {
            if (j != n) {
                std::cout << j << " ";
            }
        }

        // Move to the next line
        std::cout << std::endl;
    }

    return 0;
}

