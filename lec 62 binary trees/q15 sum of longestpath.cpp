#include<iostream>
#include<queue>
#include<limits.h>
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
void solve(node* root,int sum,int &maxsum,int len,int &maxlen){
    //base case
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=max(sum,maxsum);
        }
        else if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);




}



int sumOflongroottoleafpath(node* root){
    int len=0;
    int maxlen=0;

    int sum=0;
    int maxSum=INT_MIN;

    solve(root,sum,maxSum,len,maxlen);

    return maxSum;


}




int main(){
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root);

    cout<<"The sum of longest path of the tree is:"<<endl;
    cout<<sumOflongroottoleafpath(root);



}
