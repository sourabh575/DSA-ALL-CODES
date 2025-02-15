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
pair<bool,int> isbalncedfast(node *root){
    if(root==NULL){
        pair<bool,int>p= make_pair(true,0);
            return p;
    }
    pair<bool,int>left=isbalncedfast(root->left);
    pair<bool,int>right=isbalncedfast(root->right);

    bool leftans=left.first;
    bool rightans=right.first;

    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;

    if(leftans && rightans && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}
bool isbalnced(node *root){
    return isbalncedfast(root).first;
}


int main(){
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 10 5 -1 -1 -1 39 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root);

    if(isbalnced(root)){
        cout<<"yes tree is balnced"<<endl;
    }
    else{
        cout<<"No tree is not balnced"<<endl;
    }


}
