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
node* minval(node* root){
    node* temp=root;
    while(temp != NULL){
        temp=temp->left;
    }
    return temp;

}
node* deletefromBST(node* root,int val){
    //base case
    if(root==NULL)
        return root;

    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
     if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }



    }
    else if(root->data>val){
        //left part meh jao
        root->left=deletefromBST(root->left,val);
        return root;
    }

    else{
        //right part meh jao
        root->right=deletefromBST(root->right,val);
        return root;
    }
}




int main(){
    node* root=NULL;
    cout<<"Enter data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrdertraversal(root);
    //10 8  21 12 7 27 5 4 3 -1

    root=deletefromBST(root,30);
    //50 20 70 10 30 90 110 -1

    cout<<"Printing the BST after deletion"<<endl;
    levelOrdertraversal(root);


}

