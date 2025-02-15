#include <iostream>
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
    // new node create
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertedattail(node* &tail, int d) {
    // new node create
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertatpostion(node* &tail, node* &head, int position, int d) {
    // insertion at start
    if(position == 1) {
        insertedathead(head, d);
        return;
    }
    node* temp = head;
    int cnt = 1;
    
    while(cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }
    // insertion at last position
    if(temp->next == NULL) {
        insertedattail(tail, d);
        return;
    }
    
    // creating a node for d
    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(node* &head) {
    node* temp = head;
    
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* getmid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* reverse(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool ispalindrome(node* head) {
    if(head == NULL || head->next == NULL) {
        return true;
    }
    
    // step 1 -> find middle
    node* middle = getmid(head);
    
    // step 2 -> reverse list after middle
    node* temp = middle->next;
    middle->next = reverse(temp);
    
    // step 3 compare both halves
    node* head1 = head;
    node* head2 = middle->next;
    
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // step 4 repeat step 2 to restore original list
    temp = middle->next;
    middle->next = reverse(temp);
    
    return true;
}

int main() {
    // create a new node
    node* node1 = new node(1);

    // head points to node1
    node* head = node1;
    node* tail = node1;

    print(head);
    
    insertedattail(tail, 2);
    print(head);
    
    insertedattail(tail, 1);
    print(head);
   
     insertedattail(tail, 1);
    print(head);   
    if(ispalindrome(head)) {
        cout << "yes this is palindrome" << endl;
    } else {
        cout << "no this is not palindrome" << endl;
    }

    return 0;
}

