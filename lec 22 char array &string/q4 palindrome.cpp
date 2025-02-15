#include<iostream>
using namespace std;
bool palindrome(char name[],int n){
	int i=0;
	int j=n-1;
	while(i<=j){
		if(name[i]==name[j]){
			i++;
			j--;
		}
		else{
			return false;
		}
	}
	return true;	
}
int getlength(char name[]){
	int count=0;
	for(int i=0;name[i]!='\0';i++){
		count=count+1;
	}
	return count++;
}

int main(){
	char name[20];
	cout<<"enter your name ";
	cin>>name;
	int len=getlength(name);
	if(palindrome(name,len)==true){
		cout<<"this is palindrome";
	}
	else{
		cout<<"this is not palindrome";
	}
}
