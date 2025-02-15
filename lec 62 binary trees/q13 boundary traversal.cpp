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
void traverselleft(node *root,vector<int> &ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL))
        return ;

     ans.push_back(root->data);
     if(root->left)
            traverselleft(root->left,ans);

     else
        traverselleft(root->right,ans);

}
void traversalleaf(node*root,vector<int> &ans){
        if(root==NULL)
        return ;

        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traversalleaf(root->left,ans);
        traversalleaf(root->right,ans);

}
void traverselright(node *root,vector<int> &ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL))
        return ;

     if(root->right)
            traverselright(root->right,ans);
     else
        traverselleft(root->left,ans);

     //wapas aagaye
     ans.push_back(root->data);


}



vector<int> boundary(node* root ){
    vector<int>ans;
    if(root==NULL)
        return ans;

    ans.push_back(root->data);
    //left part print
    traverselleft(root->left,ans);

    //traverse leaf node

    //left subtree
    traversalleaf(root->left,ans);

    //right subtree
    traversalleaf(root->right,ans);

    //traverse rightpart
    traverselright(root->right,ans);

    return ans;

}
int main(){
node* root=NULL;

//creating a tree
root=buildTree(root);
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

//level order
cout<<"print the level order traversal"<<endl;
levelordertraversal(root);

vector<int> result=boundary(root);

for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
}

}
