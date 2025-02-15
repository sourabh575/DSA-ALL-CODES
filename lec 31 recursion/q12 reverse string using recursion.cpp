#include<iostream>
using namespace std;

bool checkpalindrome(string &str,int i,int j){
	if(i>j)
	return 1 ;
	
	if(str[i] != str[j]){
		return 0;
	}
	else{

		return checkpalindrome(str,i+1,j-1);
	}
	
}
	
	


int main(){
	
	string name="abbccbba";
	int ans=checkpalindrome(name,0,name.length()-1);
	if(ans){
		cout<<"yes this is palindrome";
	}
	else{
		cout<<"no this is not palindrome";
	}
	
}
	

