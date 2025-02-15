#include<iostream>
#include<vector>
#include<limits.h>
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

node* solve(vector<int>& preorder,int mini,int maxi,int &i){
    if(i >=preorder.size())
        return NULL;

    if(preorder[i]<mini || preorder[i]>maxi)
        return NULL;

    node* root=new node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);

    return root;

}
node* preordertobst(vector<int>preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;

    int i=0;
    return solve(preorder,mini,maxi,i);

}



int main(){
    node* root=NULL;
    cout<<"Enter data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrdertraversal(root);
    //10 8  21 12 7 27 5 4 3 -1
    vector<int> preorder={20,10,5,15,1,35,0,42};

    root=preordertobst(preorder);
    cout<<"preorder BST is "<<endl;
    levelOrdertraversal(root);
}
