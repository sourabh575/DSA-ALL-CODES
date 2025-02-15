#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;

		node(int data){
			this->data=data;
			this->next=NULL;
		}

};
void insertedathead(node* &head,int d){
	//new node create
	node* temp=new node(d);
	temp->next=head;
	head=temp;

}

void insertedattail(node* &tail,int d){
	//new node create
	node* temp=new node(d);
	tail->next=temp;
	tail=temp;

}
void insertatpostion(node* &tail,node* &head,int postion,int d ){
	//insertion at start

	if(postion==1){
		insertedathead(head,d);
		return;
	}
	node* temp=head;
	int cnt=1;

	while(cnt<postion-1){
		temp=temp->next;
		cnt++;
	}
	//insertion at last postion
	if(temp->next==NULL){
		insertedattail(tail,d);
		return;
	}

	//creating anode for d
	node* nodetoinsert=new node(d);
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;


}


void print(node* &head){
	node* temp=head;

	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
node *findmid(node* head){
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;

}
node* merge(node *left,node* right){
    if(left==NULL)
        return right;
    if(right==NULL)
        return left;

    node* ans=new node(-1);
    node* temp=ans;
    //merge 2 sorted linked list
    while(left !=NULL && right !=NULL){
        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;

        }
    }
    while(left !=NULL){
        temp->next=left;
        temp=left;
        left=left->next;

    }
    while(right !=NULL){
        temp->next=right;
        temp=right;
        right=right->next;

    }

    ans=ans->next;
    return ans;


}


node* mergesort(node *head){
    //base case
    if(head==NULL||head->next==NULL){
        return head;
    }
//break linked list in two halves
    node *mid=findmid(head);


    node* left=head;
    node* right=mid->next;
    mid->next=NULL;

    //recurssive call
    left=mergesort(left);
    right=mergesort(right);

    //mergeboth left and right halves
     node *result=merge(left,right);



}



int main(){
	//create at new node
	node* node1=new node(3);

	//head ko point krdiya node1 meh
	node* head=node1;

	node* tail=node1;
	print(head);

	insertedattail(tail,5);
	print(head);

	insertedattail(tail,1);
	print(head);

	insertatpostion(tail,head,4,2);
	print(head);

	insertatpostion(tail,head,5,9);
	print(head);

	cout<<"merge sort"<<endl;

	head=mergesort(head);
	print(head);

}

