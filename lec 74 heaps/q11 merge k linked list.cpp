#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>kb->data;
    }

};
node* mergeklists(vector<node*>& list arrays){
    priority_queue<node*>,vector<node*>,compare>minheap;

    int k=listarray.size();

    if(k==0){
        return NULL;
    }

    //step1:
    for(int i=0;i<k;i++){
        if(listarray[i] !=NULL){
            minheap.push(listarray[i]);

        }
    }
    node* head=NULL;
    node* tail=NULL;

    while(!minheap.empty()){
          node* top=minheap.top();
          minheap.pop();

          if(top->next !=null){
            minheap.push(top->next);
          }

    if(head==NULL){
            //ll is empty
        head=top;
        tail=top;

    }
    else{
            //inserted in ll
        tail->next=top;
        tail=top;
        if(tail->next !=NULL){
            minheap.push(tail->next);
        }
    }


    return head;


}



int main(){

}
