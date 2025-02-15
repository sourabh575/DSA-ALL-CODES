#include<iostream>
using namespace std;

class Hero{
	private:
		
	int health;
	char level;
	public:
	/*Hero(){
		//simple constructor
		cout<<"constructor called"<<endl;
	}*/	
	//paramerterised constructor
	Hero (int health){
		this->health=health;
	}
	Hero (int health,char level){
		this->level=level;
	    this->health=health;
	}
	
	//copy constructor
	Hero(Hero &temp){
		cout<<"copy constructor called:"<<endl;
		this->health=temp.health;
		this->level=temp.level;
	}
	
	void print(){
		cout<<"level:"<<this->level<<endl;
		cout<<"health:"<<this->health<<endl;

	}
	
/*	//getter
	int gethealth(){
		return health;
	}
	
	
	char getlevel(){
		return level;
	}
	//setter
	
	void sethealth(int h,char l){
		health=h;
		level=l;
	
    }*/
};

int main(){
	Hero suresh(70,'C');
	suresh.print();
	
	//copy constructor
	Hero ramesh(suresh);
	ramesh.print();
	
}
