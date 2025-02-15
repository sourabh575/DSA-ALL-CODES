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


void print(node* &head){
	node* temp=head;
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<NULL<<endl;
}


int main(){
	//create at new node
	node* node1=new node(10);
	cout<<node1->data<<endl;
	cout<<node1->next<<endl;
	
	//head ko point krdiya node1 meh
	node* head=node1;
	print(head);
	
	insertedathead(head,12);
	print(head);
	
	insertedathead(head,15);
	print(head);
		
}
