#include<iostream>
#include<cstring>
using namespace std;

class Hero{
	public:	
	int health;
	static int timetocomplete;
	static int random(){
		return timetocomplete;
	}
    
};
int Hero::timetocomplete=5;

int main(){
	cout<<Hero::random()<<endl;


	
	
	
}
