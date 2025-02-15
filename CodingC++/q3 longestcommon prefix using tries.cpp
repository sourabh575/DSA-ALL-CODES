#include<iostream>
#include<vector>
using namespace std;

class trienode{
   public:
       char data;
       trienode* children[26];
       int childcount;
       bool isterminal;
       
       trienode(char ch){
            data=ch;
            for(int i=0;i<=26;i++){
                children[i]=NULL;
            }
            childcount=0;
            isterminal=false;
       }
};
class trie{
     public:
     trienode* root;
     
     trie(char ch){
        root=new trienode('ch');
     }
     
     void insertutil(trienode* root,string word){
         //base case
         if(word.length()==0){
           root->isterminal=true;
           return;
         }   
         //assume that word will be in CAPs
         int index=word[0]-'a';
         trienode* child;
         
         //present
         if(root->children[index]!=NULL){
           child=root->children[index];
         }
         else{
             //absent
             child=new trienode(word[0]);
             root->childcount++;
             root->children[index]=child;
         }
         //Recursion
         insertutil(child,word.substr(1));
     }
     
     void insertword(string word){
         insertutil(root,word);
     }
     void lcp(string str,string &ans){
         for(int i=0;i<str.length();i++){
              char ch=str[i];
         
         if(root->childcount == 1){
            ans.push_back(ch);
            //aage badhjao
            int index=ch-'a';
            root=root->children[index];
         }
         else{
                break;
         }
         
         if(root->isterminal)
             break;
        }
     }
};



string longestcommonprefix(vector<string> &arr,int n){
           trie *t=new trie('\0');
           
           //insert all string into trie
           for(int i=0;i<n;i++){
                  t->insertword(arr[i]);     
           }
           
           string first=arr[0];
           string ans="";
           
           t->lcp(first,ans);
           return ans;

}

   

int main(){
vector<string>arr={"ninja","nil","night"};
string str=longestcommonprefix(arr,arr.size());

for(int i=0;i<str.length();i++){
       cout<<str[i];
   }
}