#include<iostream>
using namespace std;
int main(){
	string s="ab\0c\0";
	cout<<s<<endl;
	char array[5]={'a','b','\0','c','\0'};
	cout<<array<<endl;
}
