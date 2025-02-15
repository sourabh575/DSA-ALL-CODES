#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node* &head, int d){
    // new node create
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node* &tail, int d){
    // new node create
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node* &tail, node* &head, int position, int d){
    // insertion at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    // insertion at last position
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    node* nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAt(node* &tail, node* curr){
    tail->next = curr;
    tail = curr;
}

node* mergeSort(node *head){
    if(!head || !head->next) return head; // if the list is empty or has only one node

    // Dummy nodes to help with the merging process
    node *zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node *oneHead = new node(-1);
    node* oneTail = oneHead;   
    node *twoHead = new node(-1);
    node* twoTail = twoHead;

    node *curr = head;

    // create separate lists for 0s, 1s, 2s
    while(curr != NULL){
        int value = curr->data;
        if(value == 0){
            insertAt(zeroTail, curr);
        } else if(value == 1){
            insertAt(oneTail, curr);
        } else if(value == 2){
            insertAt(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublists
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // set up the new head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    // create a new node
    node* node1 = new node(1);

    // head points to node1
    node* head = node1;
    node* tail = node1;
    print(head);

    insertAtTail(tail, 0);
    print(head);

    insertAtTail(tail, 1);
    print(head);

    insertAtPosition(tail, head, 4, 2);
    print(head);

    insertAtPosition(tail, head, 5, 2);
    print(head);

    insertAtTail(tail, 0);
    print(head);

    head = mergeSort(head);
    print(head);

    return 0;
}

