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

void insertedattail(node* &tail,int d){
	//new node create
	node* temp=new node(d);
	tail->next=temp;
	tail=temp;

}


void print(node* &head){
	node* temp=head;
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


int main(){
	//create at new node
	node* node1=new node(10);

	//head ko point krdiya node1 meh
	node* head=node1;
	node* tail=node1;
	print(head);
	
	insertedattail(tail,12);
	print(head);
	
	insertedattail(tail,15);
	print(head);
		
}
