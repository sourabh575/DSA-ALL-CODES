#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *right;
    node *left;
    public:

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node *root){
    int data;
    cout<<"enter the data:"<<endl;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"enter data for inserting in right of "<<data<<endl;;
    root->right=buildTree(root->right);

    return root;
}
void levelordertraversal(node *root){
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

void buildfromlevelorder(node* root){
    queue<node*>q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter left node for:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata !=-1){
           temp->left=new node(leftdata);
           q.push(temp->left);
        }
        cout<<"enter right node for:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata !=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}




int main(){
    node* root=NULL;
    buildfromlevelorder(root);
    levelordertraversal(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1

   /* //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root);

    cout<<"preorder traversal is:";
    preorder(root);

*/
}
