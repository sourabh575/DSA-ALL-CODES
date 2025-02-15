#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class node{
public:
    int data;
    int i,j;

    node(int data,int row,int col){
        this->data=data;
        i=row;
        j=col;

    }

};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>kb->data;
    }

};
vector<int> mergeksortedarrays(vector<vector<int>>& karrays,int k){
     priority_queue<node*, vector<node*>, compare>minheap;
     vector<int>ans;

    //step1: saare arrays k first elmenet insert h
    for(int i=0;i<k;i++){
        if(!karrays[i].empty()){

          node* tmp=new node(karrays[i][0],i,0);
         minheap.push(tmp);
        }
    }

    //step2;
    while(!minheap.empty()){
        node* tmp=minheap.top();

        ans.push_back(tmp->data);
        minheap.pop();

        int i=tmp->i;
        int j=tmp->j;

        if(j+1<karrays[i].size()){
            node* next=new node(karrays[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;


}

int main(){
        vector<vector<int>> karrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int k = karrays.size();

    vector<int> result = mergeksortedarrays(karrays, k);

    // Print the merged array
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}


