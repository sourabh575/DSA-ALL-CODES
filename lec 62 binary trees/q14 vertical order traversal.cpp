/*#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    if(root==NULL){
        return ;
    }
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
vector<int> verticalorder(node* root){
    if(root==NULL){
        return vector<int>();
    }
    map<int,map<int,vector<int>>> nodes;
    queue<pair<node* ,pair<int,int>>>q;
    if(root==NULL)
        return ans;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<node*,pair<int,int>> temp=q.front();
        node* frontnode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);

        if(frontnode->left)
                    q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));

        if(frontnode->right)
                    q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));

        }
        for(auto i:nodes){
            for(auto j: i.second){
                for(auto k:j.second){
                        ans.push_back(k);

                }
            }
        }
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

    vector<int> result=verticalorder(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }


}
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

public:
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;  // Handle empty tree case
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

vector<int> verticalOrder(Node* root) {
    if (root == NULL) {
        return vector<int>();  // Empty vector for empty tree
    }

    map<int, vector<int>> nodes;  // Use map for horizontal distance
    queue<pair<Node*, int>> q; // Queue with node and horizontal distance
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        Node* frontNode = temp.first;
        int hd = temp.second;  // Horizontal distance

        nodes[hd].push_back(frontNode->data);

        if (frontNode->left) {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right) {
            q.push(make_pair(frontNode->right, hd + 1));
        }

        q.pop();
    }

    vector<int> ans;
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        for (int value : it->second) {
            ans.push_back(value);
        }
    }

    return ans;
}

int main() {
    Node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    // Level order traversal
    cout << "Print the level order traversal: " << endl;
    levelOrderTraversal(root);

    // Vertical order traversal
    vector<int> result = verticalOrder(root);
    cout << "Vertical order traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
