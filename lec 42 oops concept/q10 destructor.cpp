#include<iostream>
#include<cstring>
using namespace std;

class Hero{

	public:
	Hero(){
		//simple constructor
		
		cout<<"simple constructor called"<<endl;
	}
	~Hero(){
		cout<<"destructor bhai called"<<endl;
	}

};

int main(){
	//static
	Hero a;
	
	//dynamic
	Hero *b=new Hero();
	//manually called destructor
	delete b;
	
}
