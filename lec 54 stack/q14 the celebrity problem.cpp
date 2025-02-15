#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int> >&M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }
    else{
        return false;
    }


}

int celebrity(vector<vector<int> >&M,int n){
    stack<int>s;
    //step 1->push all element in stack
    for(int i=0;i<n;i++){
        s.push(i);
    }
    //step 2->get two element then compare them
    while(s.size()>1){
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if(knows(M,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int canditate=s.top();
    //step 3->if single celebrity in stack then check them
    bool rowCheck=false;
    int zerocount=0;


    for(int i=0;i<n;i++){
        if(M[canditate][i]==0){
            zerocount++;
        }
        //all zeroes
        if(zerocount==n){
            rowCheck=true;
        }
    }
    //column check
    bool colcheck=false;
    int onecount=0;
    for(int i=0;i<n;i++){
        if(M[i][canditate]==1){
            onecount++;
        }
        if(onecount==n-1){
            colcheck=true;
        }
    }
    if(rowCheck==true && colcheck==true){
        return canditate;
    }
    else{
        return -1;
    }



}



int main(){
    vector<vector<int> >M={{0,0,1},{0,0,1},{0,0,0}};
    int n=3;


    cout<<"celebrity is:"<<celebrity(M,n);



}
