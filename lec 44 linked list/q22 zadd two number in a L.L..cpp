#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
        
        node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void insertedathead(node* &head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertedattail(node* &tail, int d) {
    node* temp = new node(d);
    if (tail == NULL) {
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void insertatpostion(node* &tail, node* &head, int postion, int d) {
    if (postion == 1) {
        insertedathead(head, d);
        if (tail == NULL) {
            tail = head;
        }
        return;
    }
    node* temp = head;
    int cnt = 1;
    
    while (cnt < postion - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL) {
        insertedattail(tail, d);
        return;
    }
    
    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(node* &head) {
    node* temp = head;
    
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* reverse(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertattail(node* &head, node* &tail, int val) {
    node* temp = new node(val);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

node* add(node* first, node* second) {
    int carry = 0;
    node* ansHead = NULL;
    node* ansTail = NULL;
    
    while (first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if (first != NULL) {
            val1 = first->data;
        }
        
        int val2 = 0;
        if (second != NULL) {
            val2 = second->data;
        }
        
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        
        insertattail(ansHead, ansTail, digit);
        
        carry = sum / 10;
        
        if (first != NULL) {
            first = first->next;
        }
        if (second != NULL) {
            second = second->next;
        }
    }
    return ansHead;
}

node* addtwolist(node* first, node* second) {
    first = reverse(first);
    second = reverse(second);
    
    node* ans = add(first, second);
    
    ans = reverse(ans);
    
    return ans;
}

int main() {
    node* node1 = new node(4);
    node* node2 = new node(3);
    
    node* head1 = node1;
    node* head2 = node2;
    node* tail1 = node1;
    node* tail2 = node2;
    
    insertedattail(tail1, 5);  // Adds 5 to the end of the first list
    insertedattail(tail2, 5);  // Adds 4 to the end of the second list
    insertedattail(tail2, 5);  // Adds 5 to the end of the second list
    
    print(head1);  // Expected output: 4 5
    print(head2);  // Expected output: 3 4 5
    
    node* result = addtwolist(head1, head2);
    
    print(result);  // Expected output: 7 9 5
    
    return 0;
}


