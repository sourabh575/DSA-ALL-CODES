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


node* reverselinkedlist(node* &head,int k){
    
	//base case
	if(head==NULL){
    	return NULL;
	} 

    //step 1
	node *next=NULL;
	node *prev=NULL;
	node *curr=head;
	int count=0;
	
	while(curr!=NULL && count<k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	
	//step2
	
	if(next!=NULL){
		head->next=reverselinkedlist(next,k);
	}
	//step 3 return head of reverselist
	return prev;
	
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
	
	insertatpostion(tail,head,4,22);
	print(head);
	
	insertatpostion(tail,head,5,17);
	print(head);

	insertatpostion(tail,head,6,2);
	print(head);
	
	head=reverselinkedlist(head,2);
	print(head);
	

			
				
		
}

































