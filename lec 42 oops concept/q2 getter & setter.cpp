#include<iostream>
using namespace std;

class Hero{
	private:
		
	int health;
	  
	
	char level;
	public:
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
	//creation of object
	Hero ramesh;
	cout<<sizeof(ramesh)<<endl;

	
	//setter
	ramesh.sethealth(70);
	ramesh.setlevel('A');
	
	//getter
	cout<<"ramesh health is:"<<ramesh.gethealth()<<endl;	
	cout<<"ramesh level is:"<<ramesh.getlevel()<<endl;
}


