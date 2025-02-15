#include<iostream>
#include<stack>
using namespace std;

bool reduntantbracket(string &s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];

        if(ch=='('|| ch=='+' || ch=='-' || ch=='*'|| ch=='/'){
            st.push(ch);
        }
        //close bracket and lowercase present
        else{
            if(ch==')'){
                bool isreduntant=true;

                while(st.top()!='('){
                      char top=st.top();
                      if(top=='+' || top=='-' || top=='*'|| top=='/'){
                        isreduntant=false;

                      }
                      st.pop();
                }
                if(isreduntant==true){
                    return true;
                    st.pop();
                }
            }
        }
    }
    return false;
}


int main(){
    string s="(a+(a))";

    if(reduntantbracket(s)){
        cout<<"yes this is reduntant"<<endl;
    }
    else{
        cout<<"no this is not reduntant"<<endl;
    }

}
