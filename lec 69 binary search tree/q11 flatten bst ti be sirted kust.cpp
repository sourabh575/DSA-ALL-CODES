#include<iostream>
#include<queue>
#include<vector>
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
void inorder(node* root,vector<int> &in){
    if(root==NULL)
        return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
node* flatten(node* root){
    vector<int> inorderval;
    //store inoreder->sorted value

    inorder(root,inorderval);
    int n=inorderval.size();

    node* newroot=new treenode<int>(inorderval[0]);
    treenode<int>* curr=newroot;

    //2nd step

    for(int i=1;i<n;i++){
        treenode<int>* temp=ne
    }

}





int main(){
    node* root=NULL;
    cout<<"Enter data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrdertraversal(root);
    //10 8  21 12 7 27 5 4 3 -1
    //10 6 12 8 2 11 15 -1
    //4 2 1 3 6 5 7



}
