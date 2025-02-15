#include<iostream>
#include<vector>
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
	if(tail==NULL){
		tail=temp;
	}
	else{
		tail->next=temp;
	    tail=temp;

	}
}
void insertatpostion(node* &tail,node* &head,int postion,int d ){
	//insertion at start
	
	if(postion==1){
		insertedathead(head,d);
		if(tail==NULL){
			tail=head;
		}
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
node* solve(node *first,node *second) {
	//if only one element is present in first
	if(first->next==NULL){
		first->next=second;
		return first;
	}
	
	node *curr1=first;
	node *next1=curr1->next;
	node* curr2=second;
	node* next2=curr2->next;
	
	while(next1!=NULL && curr2!=NULL){
		if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
			//add node  in between the first list
			curr1->next=curr2;
			next2=curr2->next;
			curr2->next=next1;
			
			//update pointer
			curr1=curr2;
			curr2=next2;
		}
		else{//curr1 and next 1 ko aage badhana h
		    curr1=next1  ;
		    next1=next1->next;
		    
		    if(next1==NULL){
		    	curr1->next=curr2;
		    	return first;
		    	
			}
			
		}
	}
	if(curr2!=NULL){
		curr1->next=curr2;
	}
	return first;
	
	
}

node* sorttwolists(node *first,node* second){
	if(first==NULL)
	return second;
	
	if(second==NULL)
	return first;
	
	if(first->data <= second->data){
		return solve(first,second);
	}
	else{
		return solve(second,first);
	}
	
}






int main(){
	//create at new node
	node* node1=new node(1);
	node* node2=new node(2);
	

	//head ko point krdiya node1 meh
	node* head1=node1;
	node* head2=node2;
	node* tail1=node1;
	node* tail2=node2;
	insertedattail(tail1,3);
	insertedattail(tail2,4);
	insertedattail(tail1,5);
	insertedattail(tail2,5 );
	print(head1);
	print(head2);
	
	head1=sorttwolists(head1,head2);
	print(head1);

		
}
