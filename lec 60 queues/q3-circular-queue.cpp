#include<iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue function to add elements to the circular queue
    bool enqueue(int val) {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return false;
        } 
        else if (front == -1) { // First element insertion
            front = rear = 0;
            arr[rear] = val;
        } 
        else if (rear == size - 1 && front != 0) { // To maintain cyclic nature
            rear = 0;
            arr[rear] = val;
        } 
        else { // Normal case
            rear++;
            arr[rear] = val;
        }
        return true;
    }

    // Dequeue function to remove elements from the circular queue
    bool dequeue() {
        if (front == -1) { // Queue is empty
            cout << "Queue is empty" << endl;
            return false;
        }

        int ans = arr[front];
        arr[front] = -1;

        // If there is only one element
        if (front == rear) {
            front = rear = -1;
        } 
        else if (front == size - 1) { // To maintain cyclic nature
            front = 0;
        } 
        else { // Normal case
            front++;
        }
        return true;
    }

    // Function to return the front element of the queue
    int qfront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue cq(5);  // Create a circular queue of size 5

    cq.enqueue(10);
    cq.enqueue(20);
    cout << "Front element: " << cq.qfront() << endl; // Should print 10

    cq.dequeue(); // Remove 10
    cout << "Front element after dequeuing: " << cq.qfront() << endl; // Should print 20

    return 0;
}

