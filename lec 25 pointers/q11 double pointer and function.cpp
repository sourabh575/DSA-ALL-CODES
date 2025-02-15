#include<iostream>
using namespace std;
void update(int **p2){
//	p2=p2+1;
//	cout<<"inside update:"<<p2<<endl;
	
//	*p2=*p2+1;
	
	**p2=**p2+1;
}


int main(){
	int i=5;
	int* p=&i;
	int** p2=&p;
	cout<<"before update:"<<i<<endl;
	cout<<"before update:"<<p<<endl;
	cout<<"before update:"<<p2<<endl;
	update(p2);
	cout<<"after update:"<<i<<endl;
	cout<<"after update:"<<p<<endl;
	cout<<"after update:"<<p2<<endl;
	

}
