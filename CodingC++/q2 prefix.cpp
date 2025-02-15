#include<iostream>
using namespace std;

class trienode{
   public:
       char data;
       trienode* children[26];
       bool isterminal;
       
       trienode(char ch){
            data=ch;
            for(int i=0;i<=26;i++){
                children[i]=NULL;
            }
            isterminal=false;
       }
};
class trie{
     public:
     trienode* root;
     
     trie(){
        root=new trienode('\0');
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
             root->children[index]=child;
         }
         //Recursion
         insertutil(child,word.substr(1));
     }
     
     void insertword(string word){
         insertutil(root,word);
     }
     bool searchutil(trienode* root,string word){
         //base case
         if(word.length()==0){
            return root->isterminal;        
         }
         int index=word[0]-'a';
         trienode* child;
         
         //present
         if(root->children[index] !=NULL ){
           child=root->children[index];
         }
         
         else{
             //absent
             return false;
         }
         //recursion
         return searchutil(child,word.substr(1));
     
     } 
         
     bool searchword(string word){
         return searchutil(root,word);
     }
     
     bool prefixutil(trienode* root,string word){
         //base case
         if(word.length()==0){
            return true;        
         }
         int index=word[0]-'a';
         trienode* child;
         
         //present
         if(root->children[index] !=NULL ){
           child=root->children[index];
         }
         
         else{
             //absent
             return false;
         }
         //recursion
         return prefixutil(child,word.substr(1));
     
     }     
     
     
     bool startwith(string prefix){
         return prefixutil(root,prefix);
     }
     
};

   

int main(){
   trie *t;
   t->insertword("abcd");
   
   cout<<"present or not:"<<t->searchword("abcdw")<<endl;
      
}