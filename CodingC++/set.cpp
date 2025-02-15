#include <iostream>
#include <set>

int main() {
    // Step 1: Create a set
    std::set<int> s;

    // Step 2: Insert elements
    s.insert(5);
    s.insert(10);
    s.insert(1);
    s.insert(7);

    // Step 3: Display elements (automatically sorted)
    std::cout << "Set elements: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Step 4: Check if an element exists (search)
    if (s.find(7) != s.end()) {
        std::cout << "7 is in the set" << std::endl;
    } else {
        std::cout << "7 is not in the set" << std::endl;
    }

    // Step 5: Remove an element
    s.erase(10);
    std::cout << "After removing 10, set elements: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Step 6: Get the size of the set
    std::cout << "Set size: " << s.size() << std::endl;

    // Step 7: Clear the set
    s.clear();
    std::cout << "After clearing, set size: " << s.size() << std::endl;

    return 0;
}