#include<iostream>


using namespace std;
class Hero{
	public:		
	int health;
	char level;	
	
};


int main(){
	//creation of object
	Hero ramesh;
	ramesh.health=70;
	ramesh.level='A';
	cout<<"Health is:"<<ramesh.health<<endl;
	cout<<"level is:"<<ramesh.level<<endl;
	
	
}
