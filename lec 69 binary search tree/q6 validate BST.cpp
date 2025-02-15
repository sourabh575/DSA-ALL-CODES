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
bool isBST(node* root,int min,int max)
{
    //base case
    if(root==NULL)
        return true;

    if(root->data>=min && root->data<=max){
       bool left=isBST(root->left,min,root->data);
       bool right=isBST(root->right,root->data,max);
       return left && right;
    }
    else{
        return false;
    }
}

int main(){
    node* root=NULL;
    cout<<"Enter data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrdertraversal(root);
    // 10 8  21 12 5 2 0 7 27 5 4 3 -1
    // 5 6 7 8 0 2 8 6 8 5 6

    if(isBST(root,-1000,1000)){
        cout<<"yes this is BST"<<endl;
    }
    else{
        cout<<"NO this is not BST"<<endl;
    }
}

