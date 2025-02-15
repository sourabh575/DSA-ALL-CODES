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
};

int main(){
	cout<<"hi\n";
	//creation of object
	Hero ramesh;
	
}

