#include<iostream>
#include<stack>
using namespace std;

bool isvalidparenthesis(string expression){
    stack<char> s;
    for(int i=0;i<expression.length();i++){

        char ch=expression[i];
        //if opening bracket,stack push
        //if close bracket,stacktop check and pop

        if(ch=='('|| ch=='{',ch=='['){
           s.push(ch);

        }
        else{
            //for closing bracket
            if(!s.empty()){
                char top=s.top();
                if((ch==')'&& top=='(')|| (ch=='}'&& top=='{')||(ch=='['&& top==']') ){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else {
                return false;
            }
        }

    }
    if(s.empty()){
        return true;
    }
    else
        return false;


}

int main(){
    string expression="[({})]";
    bool result=isvalidparenthesis(expression);

    if(result==true){
        cout<<"balnced paranthesis"<<endl;

    }
    else{
            cout<<"unbalnced paranthesis"<<endl;

    }

}
