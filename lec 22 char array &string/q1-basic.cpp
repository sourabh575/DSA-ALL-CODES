#include<iostream>
#include<vector>
using namespace std;
int main(){
	char name[20];
	cout<<"enter your name ";
	cin>>name;
	cout<<"your name is "<<name<<endl;
	vector<string>s;
	string st="hello";
	for(int i=0;i<3;i++){
		s.push_back(st);


	}
	cout<<s[0];
	
}
