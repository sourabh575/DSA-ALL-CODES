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
bool checkpalindrome(vector<int>arr){
	int s=0;
	int e=arr.size()-1;
	while(s<=e){
		if(arr[s]!=arr[e]){
			return 0;
		}
		s++;
		e--;
	}
	return 1;
}
bool ispalindrome(node *head){
	vector<int> arr;
	node *temp=head;
	while(temp!=NULL){
		arr.push_back(temp->data);
		temp=temp->next;
		
	}
	return checkpalindrome(arr);
	
}


int main(){
	//create at new node
	node* node1=new node(1);

	//head ko point krdiya node1 meh
	node* head=node1;
	
	node* tail=node1;
	print(head);
	
	insertedattail(tail,2);
	print(head);
	
	insertedattail(tail,1);
	print(head);
		insertedattail(tail,1);
	print(head);
	
	
	if(ispalindrome(head)){
	    cout<<"yes this is palindrome"<<endl;
	}
	else{
		cout<<"no this is not palindrpme";
	}
	
	

}
