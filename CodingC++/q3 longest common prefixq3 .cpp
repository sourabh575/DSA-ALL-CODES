#include<iostream>
#include<vector>
using namespace std;

string longestcommonprefix(vector<string>  &arr,int n){
            string ans;
            
            //for traversing  all  characters of first string
            for(int i=0;i<arr[0].length();i++){
                 char ch = arr[0][i];
                 
                 bool match=true;
                 
                 //comparing ch with rest of the strings
                 for(int j=1; j<n ;  j++){
                       //charachter not matched
                       if(arr[j].size()<i ||  ch !=arr[j][i]){
                          match=false;
                          break;
                       }
                 }
                 if(match==false)
                 break;
                 
                 else
                       ans.push_back(ch);
                 
                 
            }
            return ans;

}

int main(){
      vector<string>arr={"coding","codingninja","coders"};
      string ans=longestcommonprefix(arr,arr.size());
      
      for(int i=0;i<ans.size();i++){
           cout<<ans[i];  
       }
      
}
       
       
    


