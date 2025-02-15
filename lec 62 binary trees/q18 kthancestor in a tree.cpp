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
void solve(node *root,int k,int &count,vector<int>path){
    //base case
    if(root==NULL)
        return ;

    path.push_back(root->data);

    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    //check for sum

    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum += path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}
int sumkpath(node* root,int k){
    int count=0;
    vector<int>path;

    solve(root,k,count,path);
    return count;


}



int main(){
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 3 2 -1 -1 1 1 -1 -1 -1 1 41 -1 -1 2 -1 -1 5 -1 6 -1 -1
//1 2 -1 -1 3 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root);


    int k=5;

    cout<<"Total number of k sum path is:"<<sumkpath(root,k);




}
