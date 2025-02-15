#include<iostream>
using namespace std;

class a{
	public:
	void speak(){
		cout<<"speak"<<endl;
	}
	
};
class b{
	public:
	void bark(){
		cout<<"bark"<<endl;
	}
	
};
class c:public a,public b{
	
};



int main(){
	c obj;
	obj.speak();
	obj.bark();
	


}
