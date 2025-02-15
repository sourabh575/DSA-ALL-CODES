#include <iostream>
#include <queue>  // for priority_queue

int main() {
    // Create a priority queue (max heap by default)
    std::priority_queue<int> pq;

    // Push elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Display the top element
    std::cout << "Top element: " << pq.top() << std::endl;

    // Remove the top element (pop)
    pq.pop();  // Removes 20, the largest element
    std::cout << "After pop, top element: " << pq.top() << std::endl;

    return 0;
}