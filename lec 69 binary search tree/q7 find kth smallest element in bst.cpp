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
void inorder(node *root){
    //base case
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void preorder(node *root){
    //base case
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(node *root){
    //base case
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int solve(node* root,int &i,int k){
    //base case
    if(root==NULL){
        return -1;
    }
    //L
    int left=solve(root->left,i,k);

    if(left != -1){
        return left;
    }
    //N
    i++;
    if(i==k)
        return root->data;

    //R
    return solve(root->right,i,k);
}



int kthsmallest(node* root,int i,int k){
    int ans=solve(root,i,k);
    return ans;

}






int main(){
    node* root=NULL;
    cout<<"Enter data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrdertraversal(root);
    //10 8  21 12 7 27 5 4 3 -1


    cout<<"printing Inorder"<<endl;
    inorder(root);

    cout<<endl<<"printing preorder"<<endl;
    preorder(root);

    cout<<endl<<"printing postorder"<<endl;
    postorder(root);
    cout<<endl;

    int i=0;
    int k=3;
    cout<<k<<" th smallest number is:"<<kthsmallest(root,i,k)<<endl;

}
