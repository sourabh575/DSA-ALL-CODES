#include<iostream>
using namespace std;

class Hero{
	private:
		
	int health;
	char level;
	public:
	Hero(){
		cout<<"constructor called"<<endl;
	}	
	//paramerterised constructor
	Hero (int health){
		cout<<"this->"<<this<<endl;
		this->health=health;
	}
	Hero (int health,char level){
		this->level=level;
		this->health=health;
	}
	void print(){
		cout<<health<<endl;
		cout<<level<<endl;
	}
	
	//getter
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
		
	}
	
//	void setlevel(char l){
//		level=l;
//	}		
};

int main(){
	
	Hero ramesh(10);
	cout<<"address of ramesh:"<<&ramesh<<endl;
	ramesh.print();
	
	//dynamically
	Hero *h=new Hero(11);
	h->print();
	
	
	Hero temp(22,'B');
	temp.print();
	
	
}

