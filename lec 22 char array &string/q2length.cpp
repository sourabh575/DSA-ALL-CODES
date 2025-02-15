#include<iostream>
using namespace std;
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
	cout<<"length is:"<<getlength(name);
	
}
