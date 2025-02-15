#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted " << data << " at the front." << endl;
    }

    void insertRear(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted " << data << " at the rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        Node* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        cout << "Deleted " << temp->data << " from the front." << endl;
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        Node* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        cout << "Deleted " << temp->data << " from the rear." << endl;
        delete temp;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return rear->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.display();  // Output: 5 10 20

    deque.deleteFront();  // Deletes 5
    deque.display();  // Output: 10 20

    deque.deleteRear();  // Deletes 20
    deque.display();  // Output: 10

    cout << "Front element: " << deque.getFront() << endl;  // Output: 10
    cout << "Rear element: " << deque.getRear() << endl;    // Output: 10

    return 0;
}
