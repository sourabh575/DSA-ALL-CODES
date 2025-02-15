#include<iostream>

using namespace std;
class animal{
	public:
	int age;
	int weight;
		
	public:
	void speak(){
		cout<<"dog is speaking";
	}	
					
};

class dog: public animal{
	
};
class germanshepard: public dog{
	
};



int main(){
	germanshepard d;
	d.speak();


}
