#include<iostream>
using namespace std;

class a{
	public:
	void func(){
		cout<<"I AM A"<<endl;
	}
	
};
class b{
	public:
	void func(){
		cout<<"I AM B"<<endl;
	}
	
};
class c:public a,public b{
	
};



int main(){
	c obj;
	obj.a::func();
	obj.b::func();
	


}
