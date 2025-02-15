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
	~node(){
		int value=this->data;
		//memory free
		if(this->next!=NULL){
			delete next;
			this->next=NULL;
	}
		cout<<"memory is free for node with data: "<<value<<endl;
	}		
		
};
void insertnode(node* &tail,int element,int d){
	//empty list
	if(tail==NULL){
		node* newnode=new node(d);
		tail=newnode;
		newnode->next=newnode;
	}
	
	else{
		//non empty list
		//assuming that the element is present in the list
		node* curr=tail;
		
		while(curr->data!=element){
			curr=curr->next;
		}
		
		//element found= curr is represented that element wala node
		node* temp=new node(d);
		temp->next=curr->next;
		curr->next=temp;
		
	}
}
bool check(node* &tail){
	//emptylist
	if(tail==NULL){
		return true;
	}

	
	node* temp=tail->next;
	while(temp!=NULL && temp!=tail){
		temp=temp->next;
	}
	if(temp==NULL){
		return false;
		
	}
	else(temp==tail);
		return true;
	
}





void print(node* &tail){
	node* temp=tail;
	do{
		cout<<tail->data<<" ";
		tail=tail->next;
	}
	while(tail!=temp);
	cout<<endl;	
	
}


int main(){
	//create at new node
	node* tail=NULL;
	
	//empty list
	insertnode(tail,5,3);
	print(tail);
	
	insertnode(tail,3,5);
	print(tail);
	
	insertnode(tail,5,7);
	print(tail);
	
	insertnode(tail,7,9);
	print(tail);
	
	insertnode(tail,3,6);
	print(tail);
	
		insertnode(tail,9,2);
	print(tail);
	
    insertnode(tail,3,4);
	print(tail);	
	
	if(check(tail)){
		cout<<"this linkedlist is circular";
	}
	else{
	cout<<"this linkedlist is not circular";		
	}
}









