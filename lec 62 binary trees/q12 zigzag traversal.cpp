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
vector<int> zigzagtraversal(node *root){
    vector<int>result;
    if(root==NULL)
        return result;

    queue<node*>q;
    q.push(root);
    bool lefttoright=true;


    while(!q.empty()){

        int size=q.size();
        vector<int> ans(size);
        //level process
        for(int i=0;i<size;i++){

            node* frontnode=q.front();
            q.pop();

            //normal and reverse insert
            int index=lefttoright ? i : size-i-1;
             ans[index]=frontnode->data;

             if(frontnode->left)
             q.push(frontnode->left);

             if(frontnode->right)
               q.push(frontnode->right);

        }
        //direction  change krni hai
        lefttoright=!lefttoright;
        for(auto i:ans){
          result.push_back(i);
        }
    }
    return result;
}


int main(){
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout<<"print the level order traversal"<<endl;
    levelordertraversal(root);

    vector<int> result=zigzagtraversal(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }


}
//1 3 7 9 -1 -1 -1 11 -1 -1 5 17 56 -1 -1 -1 -1

