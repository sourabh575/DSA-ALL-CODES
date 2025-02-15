#include<iostream>
using namespace std;
bool tolowercase(char name[]){
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] = name[i] - 'A' + 'a';
        }
    }
}

char tolowercase(name ch){
	if(ch>='a' && ch<='z') || (ch>='0' && ch<='9'){
		return ch;
	}
	else{
		char temp=ch-'A'+'a';
		return temp;
	}
}
bool checkpalindrome(string a){
	int s=0;
	int e=a.length()-1;
	while(s<=e)
	if(a[s]!=a[e]){
		return 0;
	}
	else{
		s++;
		e--;
	}
}
bool ispalindrome(string s){
	string temp="";
	for(int j=0;j<s.length();j++){
		if (valid(s[j])){
			temp.push_back(s[j]);
			
		}
	}
	for(int j=0;j<temp.length();j++){
		temp[j]=tolowercase(temp[j]);
		
	}
	return checkpalindrome(temp);
}
int main(){
	string s="abcba";
	if(ispalindrome(s)){
		cout<<" yes this is  palindrome";
	}
	else{
		cout<<" no this is not a  palindrome";
	}
}
	
	

