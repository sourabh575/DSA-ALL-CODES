#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* prev;
		node* next;
		
		//constructor
		node(int d){
			this->data=d;
			this->prev=NULL;
			this->next=NULL;
		}
};
void print(node* head){
	node* temp=head;
	
	while(temp !=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int getlength(node* head){
	int len=0;
	node*temp=head;
	
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;
}

void insertathead(node* &head,int d){
	node*temp=new node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}

void insertattail(node* &tail,int d){
	//create a node for tail
	node* temp=new node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
void insertatpostion(node* &tail,node* &head,int postion,int d ){
	//insertion at start
	
	if(postion==1){
		insertathead(head,d);
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
		insertattail(tail,d);
		return;
	}
	
	//creating anode for d
	node* nodetoinsert=new node(d);
	
	nodetoinsert->next=temp->next;
	
	temp->next->prev=nodetoinsert;
	
	temp->next=nodetoinsert;
	
	nodetoinsert->prev=temp;
	
	
}

int main(){
	node* node1=new node(10);	
	node* head=node1;
	node* tail=node1;
	
	
	print(head);
	cout<<getlength(head)<<endl;
	
	insertathead(head,15);
	print(head);
	
	insertathead(head,8);
	print(head);
	
	
	insertattail(tail,25);	
	print(head);
	
	insertatpostion(tail,head,2,22);
	print(head);
	
	
}  
