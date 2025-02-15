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
node* reverse(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertattail(node  *head,node *tail,int val){
	node *temp=new node(val);
	if(head==NULL){
		head=temp;
		tail=temp;
		return;
	}
	else{
		tail->next=temp;
		tail=temp;
		
	}
	
}

node *add(node  *first,node *second){
	int carry=0;
	int sum=0;
	int digit;
	
	while(first !=NULL && second != NULL){
		sum=carry + first->data + second ->data;
		
		digit=sum %10;
		
		//create a node  and add a LL
		insertattail(first,second,digit);
		carry=sum/10;	
	}
	while(first !=NULL){
		int sum=carry + first->data;
		digit=sum %10;
		
		//create a node  and add in ans a LL
		insertattail(first,second,digit);
		carry=sum/10;
		first=first->next;
	}
	while(second !=NULL){
		int sum=carry + second->data;
		digit=sum %10;
		
		//create a node  and add a LL
		insertattail(first,second,digit);
		carry=sum/10;
		second=second->next;
	}
	while(carry !=0){
		int sum=carry;
		digit=sum %10;
		
		//create a node  and add a LL
		insertattail(first,second,digit);
		carry=sum/10;	
	}
	return first;
	
	
	
	
	
	
}


node *addtwolist(node  *first,node *second){
	//step 1 revesre input ll
	first=reverse(first);
	second=reverse(second);
	
	//step2=add 2LL
	node *ans=add(first,second);
	
	//step 3
	ans=reverse(ans);
	
	return ans;
	
}








int main(){
	//create at new node
	node* node1=new node(4);
	node* node2=new node(3);
	

	//head ko point krdiya node1 meh
	node* head1=node1;
	node* head2=node2;
	node* tail1=node1;
	node* tail2=node2;
	insertedattail(tail1,5);
	insertedattail(tail2,4);
	insertedattail(tail2,5 );
	print(head1);
	print(head2);
	
	addtwolist(head1,head2);
	print(head1);
	


		
}
