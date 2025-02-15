#include<iostream>
#include<queue>
using namespace std;
class kqueue{
public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

public:
    kqueue(int n,int k){
        this->n=n;
        this->k=k;
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        next=new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        arr=new int[n];
        freespot=0;
    }
    void enqueue(int data,int qn){
        //overflow
        if(freespot==-1){
            cout<<"no empty space is present in array"<<endl;
        }
        //find first free index
        int index=freespot;

        //update freespot
        freespot=next [index];

        //check whether first element
        if(front[qn-1 ]== -1){
                //qn-1 because index start with 0
            front[qn-1]=index;
        }
        else{
            //link new element to the prev array
            next[rear[qn-1]]=index;
        }
        //update next
        next[index]=-1;

        //update rear
        rear[qn-1]=index;

        //push element
        arr[index]=data;

    }
    int dequeue(int qn){
        //underflow
        if(front[qn-1]==-1){
            cout<<"queue underfllow"<<endl;
            return -1 ;
        }
        //find index to pop
        int index=front[qn-1];

        //front ko aage badhao bo bhi same queue meh
        front[qn-1]=next[index];

        //freeslots ko manage kro
        next[index]=freespot;
        freespot=index;
        return arr[index];

    }

};

int main(){
    kqueue kq(10,3);
    kq.enqueue(5,1);
    kq.enqueue(10,1);
    kq.enqueue(2,2);
    kq.enqueue(3,2);
    kq.enqueue(15,1);
    kq.enqueue(4,5);
    kq.enqueue(6,2);
   cout<< kq.dequeue(1);


}
