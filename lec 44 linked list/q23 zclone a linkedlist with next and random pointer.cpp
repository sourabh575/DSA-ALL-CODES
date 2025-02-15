#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void inserted_at_tail(Node*& head, Node*& tail, int data) {
    Node* new_node = new Node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
}

Node* copy_list(Node* head) {
    Node* clone_head = NULL;
    Node* clone_tail = NULL;

    // Create a clone list with the same data values
    Node* temp = head;
    while (temp) {
        inserted_at_tail(clone_head, clone_tail, temp->data);
        temp = temp->next;
    }

    // Create a map to store mappings between original and clone nodes
    unordered_map<Node*, Node*> old_to_new;
    Node* original_node = head;
    Node* clone_node = clone_head;
    while (original_node && clone_node) {
        old_to_new[original_node] = clone_node;
        original_node = original_node->next;
        clone_node = clone_node->next;
    }

    // Assign random pointers in the clone list
    original_node = head;
    clone_node = clone_head;
    while (original_node) {
        clone_node->random = old_to_new.get(original_node->random);
        original_node = original_node->next;
        clone_node = clone_node->next;
    }

    return clone_head;
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    inserted_at_tail(head, tail, 2);
    inserted_at_tail(head, tail, 3);

    // Print the original list
    cout << "Original List:" << endl;
    print_list(head);

    // Clone the linked list
    Node* clone_head = copy_list(head);

    // Print the cloned list
    cout << "Cloned List:" << endl;
    print_list(clone_head);

    return 0;
}

