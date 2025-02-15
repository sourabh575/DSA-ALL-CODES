                                                                                                               #include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
		
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
void deletenode(node* &head,int postion){
	//delete at first node
	if(postion==1){
		node* temp=head;
		temp->next->prev;
		head=temp->next;
		//memory free start node
		temp->next=NULL;
		delete temp;
	}
	
	//delete  any middle or last postion
	else{
		node*curr=head;
		node* prev=NULL;
	
		int cnt=1;
		while(cnt<postion){
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		curr->prev=NULL;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
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
	cout<<"head:"<<head->data<<endl;

	cout<<"tail:"<<tail->data<<endl;
		
	deletenode(head,4);
	print(head);

	cout<<"tail:"<<tail->data<<endl;	
}
