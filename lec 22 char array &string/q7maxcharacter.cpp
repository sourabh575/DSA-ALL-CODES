#include<iostream>
using namespace std;
#include<string>
char getmaxocccharacter(string s){
	int arr[26]={0};
	for(int i=0;i<s.length();i++){
		char ch =s[i];
		int number=0;
		if (ch>='a'&&ch<='z'){
			number =ch-'a';
		}
		else{
			number=ch-'A';
		}
		arr[number]++;
	}
	int maxi=-1,ans=0;
	for(int i=0;i<26;i++){
		if(maxi<arr[i]){
			ans=i;
			maxi=arr[i];
		}
	}
	char finalans='a'+ans;
	return finalans;
		
}
int main(){
	string s;
	cout<<"enter string:";
	
	 cin>>s;
	cout<<getmaxocccharacter(s);

}
