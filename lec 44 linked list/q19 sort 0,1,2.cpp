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

node* mergesort(node *head){
	if(head==NULL)
	return NULL;
	
	int cnt0=0;
	int cnt1=0;
	int cnt2=0;
	
	node *curr=head;
	while(curr!=NULL){
		if(curr->data==0){
			cnt0++;
		}
		else if(curr->data==1){
			cnt1++;
		}
		else if(curr->data==2){
			cnt2++;
		}
		curr=curr->next;
	}
	curr=head;
	
	while(curr!=NULL){
		if(cnt0!=0){
			curr->data=0;
			cnt0--;
		}
		else if(cnt1!=0){
	 	    curr->data=1;
		    cnt1--;
		}
		else if(cnt2!=0){
			curr->data=2;
			cnt2--;
		}
		curr=curr->next;
	}
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
	
	insertatpostion(tail,head,4,2);
	print(head);
	
	insertatpostion(tail,head,5,2);
	print(head);
	
		insertedattail(tail,0);
	print(head);
	
		insertedattail(tail,0);
	print(head);
	
		insertedattail(tail,0);
	print(head);
	
	head=mergesort(head);	
	print(head);
		
}
