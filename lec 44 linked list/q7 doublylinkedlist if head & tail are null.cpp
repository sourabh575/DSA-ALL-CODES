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

void insertathead(node* &tail,node* &head,int d){
	if(head==NULL){
		node* temp=new node(d);
		head=temp;
		tail=temp;
	}
	else{
		node* temp=new node(d);
	    temp->next=head;
	    head->prev=temp;
	    head=temp;
	}
	
	
}

void insertattail(node* &tail,node* &head,int d){
	if(tail==NULL){
		node* temp=new node(d);
		tail=temp;
		head=temp;
	}
	else{
		node* temp=new node(d);
	    tail->next=temp;
	    temp->prev=tail;
	    tail=temp;	
	}
}
	
void insertatpostion(node* &tail,node* &head,int postion,int d ){
	//insertion at start
	
	if(postion==1){
		insertathead(tail,head,d);
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
		insertattail(tail,head,d);
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
	
	node* head=NULL;
	node* tail=NULL;
	
	
	print(head);
	cout<<getlength(head)<<endl;
	
	insertathead(tail,head,15);
	print(head);
	
	insertathead(tail,head,8);
	print(head);
	
	
	insertattail(tail,head,25);	
	print(head);
	
	insertattail(tail,head,105);	
	print(head);
	
	insertatpostion(tail,head,2,22);
	print(head);

	insertatpostion(tail,head,3,100);
	print(head);	
	
	
}  
