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
void insertat(node* tail,node* curr){
	tail->next=curr;
	tail=curr;
}

node* mergesort(node *head){

	
	node *zerohead=new node(-1);
	node* zerotail=zerohead;
	node *onehead=new node(-1);
	node* onetail=onehead;
	node *twohead=new node(-1);
	node* twotail=twohead;
	
	node *curr=head;
	//create seprate list 0s,1s,2s
	
	while(curr!=NULL){
		int value=curr->data;
		if(value==0){
			insertat(zerotail,curr);
		}
		else if(value==1){
			insertat(onetail,curr);
		}
		else if(value==2){
			insertat(twotail,curr);
		}
		curr=curr->next;
					
	}
	
	//merge 3 sublist
	
	//is list not empty
	
	if(onehead->next!=NULL){
		zerotail->next=onehead->next;
		
	}
	else{
		//is list empty
		zerotail->next=twohead->next;
	}
	
	onetail->next=twohead->next;
	twotail->next=NULL;
	
	//setup head
	head=zerohead->next;
	
	//delete dummynodes
	delete zerohead;
	delete onehead;
	delete twohead;
	
	return head;
	
}

int main(){
	//create at new node
	node* node1=new node(1);

	//head ko point krdiya node1 meh
	node* head=node1;
	node* tail=node1;
	print(head);
	
	insertedattail(tail,0);
	print(head);
	
	insertedattail(tail,1);
	print(head);
	
	insertedattail(tail,2);
	print(head);	
	
	insertedattail(tail,0);
	print(head);	

		insertedattail(tail,2);
	print(head);
	
	head=mergesort(head);	
	print(head);
		
}
