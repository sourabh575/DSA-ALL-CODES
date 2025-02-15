#include<iostream>
using namespace std;
class A{
	public:
	void sayhello(){
		cout<<"hello sourabh"<<endl;
	}
	int sayhello(char a){
		cout<<"hello "<<endl;
		return 1;
	}
	void sayhello(string name){
		cout<<"hello"<<name<<endl;
	}
};

int main(){
	A obj;
	obj.sayhello();
	
	
}
