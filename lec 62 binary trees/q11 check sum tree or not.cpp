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
pair<bool,int> issumtreefast(node *root){
    //base case
    if(root==NULL){
        pair<bool,int>p= make_pair(true,0);
            return p;
    }
    if(root->left==NULL && root-> right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int>leftans=issumtreefast(root->left);
    pair<bool,int>rightans=issumtreefast(root->right);

    bool isleftsumtree=leftans.first;
    bool isrightsumtree=rightans.first;

    bool condn=root->data==leftans.second+rightans.second;

    pair<bool,int>ans;
    if(isleftsumtree && isrightsumtree && condn){
        ans.first=true;
       ans.second=2*root->data;
       // ans.second=root->data+left.second+right.second;
    }
    else{
        ans.first=false;
    }
    return ans;

}
bool issumtree(node *root){
    return issumtreefast(root).first;
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

    if(issumtree(root)){
        cout<<"yes "<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


}
