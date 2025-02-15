#include<iostream>
using namespace std;
void reversearray(char name[],int n){
	int i=0;
	int j=n-1;
	while(i<=j){
		swap(name[i],name[j]);
		i++;
		j--;
	}
	
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
	reversearray(name,len);
	cout<<name<<endl;
	//cout<<"your name is "<<name<<endl;
	
}
