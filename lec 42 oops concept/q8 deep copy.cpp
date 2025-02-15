#include<iostream>
#include<cstring>
using namespace std;

class Hero{
	public:
		
	int health;
	char level;
	char *name;
	public:
	Hero(){
		//simple constructor
		
		cout<<"constructor called"<<endl;
		name=new char[100];
	}*
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
		char *ch=new char[strlen(temp.name)+1];
		strcpy(ch,temp.name);
		this->name=ch;
		
		cout<<"copy constructor called:"<<endl;
		this->health=temp.health;
		this->level=temp.level;
	}
	
	void print(){
	cout<<"name:"<<this->name<<",";
	cout<<"level:"<<this->level<<",";
	cout<<"health:"<<this->health;	

	}
	
	//getter
	int gethealth(){
		return health;
	}
	
	
	char getlevel(){
		return level;
	}
	//setter
	
	void sethealth(int h){
		health=h;
	
    }

	void setlevel(char l){
		level=l;
	}
    void setname(char name[]){
    	strcpy(this->name, name);
	}				
    
};

int main(){
	Hero hero1;
	hero1.sethealth(12);
	hero1.setlevel('A');
	char name[8]="sourabh";
	hero1.setname(name);
	
	hero1.print();
	
	//use default copy constructor
	Hero hero2(hero1);
	hero2.print();
	
	hero1.name[0]='G';
	hero1.print();
	
	hero2.print();
	
	
	
}
