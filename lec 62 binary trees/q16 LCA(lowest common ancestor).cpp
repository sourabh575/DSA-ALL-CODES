#include<iostream>
#include<vector>
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
int lca(node* root,int n1,int n2){
    //base case
    if(root==NULL){
       return 0;
    }
    if(root->data==n1 || root->data==n2){
        return root->data;
    }
    int leftans=lca(root->left,n1,n2);
    int rightAns=lca(root->right,n1,n2);
    if(leftans !=0 && rightAns!=0){
        return root->data;
    }
    else if(leftans !=0 && rightAns==0){
        return leftans;
    }
    else if(leftans ==0&& rightAns!=0){
        return rightAns;
    }
    else{
        return 0;
    }

}

/*node* lca(node* root,int n1,int n2){
    //base case
    if(root==NULL){
       return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftans=lca(root->left,n1,n2);
    node* rightAns=lca(root->right,n1,n2);
    if(leftans !=NULL && rightAns!=NULL){
        return root;
    }
    else if(leftans !=NULL && rightAns==NULL){
        return leftans;
    }
    else if(leftans ==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return NULL;
    }

}*/


int main(){
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 2 6 -1 8 -1 -1 -1 3 4 -1 -1 5 21 -1 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root);

    cout<<"Lowest Common Ancestor is:"<<lca(root,4,21);




}
