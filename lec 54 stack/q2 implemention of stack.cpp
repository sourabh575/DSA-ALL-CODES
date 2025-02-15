#include<iostream>
using namespace std;

class stack{
public:
    //properties
    int *arr;
    int top;
    int size;

    //behaviour
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;

    }
    void push(int element){
        //check space available
        if(size-top>1){
            top++;
            arr[top]=element;

        }
        else{
            cout<<"stack is overflow"<<endl;
        }
    }
    void pop(){
        if(size-top>1){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0 ){
            return arr[top];
        }
         else{
            cout<<"stack is empty"<<endl;

        }
    }
    bool isempty(){
     if(top==-1){
            return 1;
        }
         else{
            return 0;
        }


    }


};

int main(){

    stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);

    cout<<st.peek()<<endl;
    st.pop();
   cout<<st.peek()<<endl;
   st.push(498);
   cout<<st.peek()<<endl;

    if(st.isempty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }


   st.isempty();

}
