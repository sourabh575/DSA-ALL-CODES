#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node *right;
    node *left;


    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelOrdertraversal(node *root){
    if(root==NULL)
        return ;

    queue<node*>q;
    q.push(root);
    //sepreator
    q.push(NULL);


    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        //purana level complete traverse ho chuka hai
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
            }
        }
    }
}
 node* insertinBST(node* root,int data){
    //base case
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(data>root->data){
        //right part me insert krdo
        root->right=insertinBST(root->right,data);

    }
    else{
        //left part me insert krdo
        root->left=insertinBST(root->left,data);
    }
    return root;


}


void takeInput(node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertinBST(root,data);
        cin>>data;
    }
}
/*bool searchInBST(node* root,int x){
    //base case
    if(root==NULL){
        return NULL;
     }

    if(root->data==x){
        return root;
    }


    if(root->data>x){
        //left part me
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
    }

    return NULL;
}
*/
bool searchInBST(node* root,int x){
    node*temp=root;

    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}



int main(){
    node* root=NULL;
    cout<<"Enter data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrdertraversal(root);
    //10 8  21 12 7 27 5 4 3 -1
    int x=1;

    if(searchInBST(root,x)){
        cout<<"yes x is present in BST"<<endl;
    }
    else{
        cout<<"NO x is not present in BST"<<endl;
    }
}
