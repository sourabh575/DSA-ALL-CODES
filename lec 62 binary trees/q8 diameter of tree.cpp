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
/*int heightofbinarytree(node* root){
    if(root==NULL){
    return 0;
    }

    //recursive call
    int h1=heightofbinarytree(root->left);
    int h2=heightofbinarytree(root->right);

    int ans=max(h1,h2)+1;
    return ans;
}
int diameter(node* root){
    if(root==NULL){
    return 0;
    }

    //recursive call
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=heightofbinarytree(root->left)+heightofbinarytree(root->right)+1;

    int ans=max(op1,max(op2,op3));
    return ans;
}
*/
pair<int,int> diameterfast(node *root){
    //base case
    if(root == NULL){
        pair<int,int>p=make_pair(0,0);
           return p;

    }
    pair<int,int>left=diameterfast(root->left);
    pair<int,int>right=diameterfast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;

    return ans;
}
int diameter(node* root){
    return diameterfast(root).first;

}

int main(){
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout<<"print the level order  traversal"<<endl;
    levelordertraversal(root);


    int result=diameter(root);
    cout<<"answer is:"<<result;


}
