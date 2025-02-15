#include<iostream>
#include<string>
using namespace std;
class human{
	private:
	int age;
	int weight;
	int height;
		
	public:
	int getage(){
		return this->age;
	}	
	void setweight(int w){
		this->weight=w;
	}					
};

class male:public human{
	public:
	string color;
	
	void sleep(){
		cout<<"male slepping"<<endl;
	}	
	int getheight(){
		this->height;
	}
	
	
};


int main(){
	male m1;
	cout<<m1.getheight()<<endl;


}
