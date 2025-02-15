#include<iostream>
using namespace std;

class Twostack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    //intialize two stack
    Twostack(int s){
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];


    }
    void push1(int element){
        //atleast 1 space should be present
        if(top2-top1>1){
            top1++;
            arr[top1]=element;
        }
        else{
            cout<<"stack is overflow"<<endl;
        }

    }
    void push2(int element){
        if(top2-top1>1){
            top2--;
            arr[top2]=element;
        }
        else{
            cout<<"stack is overflow"<<endl;
        }

    }
    int pop1(){
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        cout<<"stack is underflow"<<endl;
    }
    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        cout<<"stack is underflow"<<endl;
    }
    int peek1(){
        if(top1>=0){
            return arr[top1];
        }
        else{
                cout<<"stack is empty"<<endl;

        }


    }
    int peek2(){
        if(top2<=size){
            return arr[top2];
        }
        else{
                cout<<"stack is empty"<<endl;

        }


    }

};
int main(){
    Twostack s(10);
    s.push1(5);
    s.push1(1);
    s.push1(3);

    s.pop1();
    cout<<s.peek1()<<endl;
    s.push2(10);
    s.push2(30);
    s.push2(20);
    cout<<s.pop2()<<endl;
    cout<<"top element of 2nd stack is:"<<s.peek2()<<endl;



}
