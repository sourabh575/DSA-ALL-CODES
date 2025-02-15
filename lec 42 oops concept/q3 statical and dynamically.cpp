#include<iostream>
using namespace std;

class Hero{
	public:
	
	int health;
	char level;
};

int main(){
	//static allocation
	Hero a;
	a.health=70;
	a.level='A';
	
	cout<<"level is:"<<a.level<<endl;
	cout<<"health is"<<a.health<<endl;
	
	//dynamically
	Hero *b=new Hero;
	b->health=85;
	b->level='C';
		
	cout<<"level is:"<<(*b).level<<endl;
	cout<<"health is"<<(*b).health<<endl;
		
	//another type of print b
	cout<<"level is:"<<b->level<<endl;
	cout<<"health is:"<<b->health<<endl;
		
}

