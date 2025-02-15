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
void deletenode(node* &tail,int value){
	//empty list
	if(tail==NULL){
		cout<<"null list"<<endl;
		return;
	}
	else{
		//non empty
		//assuming that value is present in L.L.
		node* prev=tail;
		node* curr=prev->next;
		
		while(curr->data!=value){
			prev=curr;
			curr=curr->next;
		}
		
		prev=prev->next=curr->next;
		
		//1 node
		if(curr==prev){
			tail=NULL;
		}
		if(tail==curr){
			tail=prev;
		}
		curr->next=NULL;
		delete curr;
		
		
	}
	
}




void print(node* &tail){
	node* temp=tail;
	if(tail==NULL){
		cout<<"list is empty"<<endl;
	}
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
	
	deletenode(tail,3);
	print(tail)	;
}
