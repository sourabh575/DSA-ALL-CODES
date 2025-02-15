#include<iostream>
#include<stack>
using namespace std;
class Nstacks{
    public:
    int *arr;
    int *top;
    int *next;
    int n,s;
    int freespot;

        Nstack(int N,int S){
            n=N;
            s=S;
            arr=new int[s];
            top=new int[n];
            next=new int[s];

        //top intialize
        for(int i=0;i<n;i++){
            top[i]=-1;
        }

        //next intialize
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        //update last index to-1
        next[s-1]=-1;

        //intialise freespot
        freespot=0;

        }


        bool push(int x,int m){
            //check for overflow
            if(freespot==-1){
                return false;
            }
            //step->1 find index;
            int index=freespot;

            //step->2 update freespot
            freespot=next[index];

            //step->3 insert value in  an array
            arr[index]=x;

            //update next
            next[index]=top[m-1];

            //step->update top;
             top[m-1]=index;

             return true;

        }
        int pop(int m){
            //check underflow condition
            if(top[m-1]==-1){
                return -1;
            }
            int index=top[m-1];

            top[m-1]=next[index];

            next[index]=freespot;

            freespot=index;

            return arr[index];


        }


};

int main(){
    Nstacks arr(3,10);
    arr.push(10,1);
    cout<<arr.pop();


}
