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
bool isidentical(node* root1,node* root2){
    //base case
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    bool left=isidentical(root1->left,root2->left);
    bool right=isidentical(root1->right,root2->right);

    bool val=root1->data == root2->data;
    if(left && right && val){
        return true;
    }
    else{
        return false;
    }




}

int main(){
    node* root1=NULL;
    node* root2=NULL;

    //creating a tree
    root1=buildTree(root1);
    //1 2 -1 -1 2 -1 -1
    root2=buildTree(root2);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root1);
    levelordertraversal(root2);

    if(isidentical(root1,root2)){
        cout<<"yes this is identical"<<endl;
    }
    else{
          cout<<"no this is not identical"<<endl;
    }



}
