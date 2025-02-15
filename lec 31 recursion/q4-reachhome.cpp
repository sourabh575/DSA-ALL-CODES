#include<iostream>
using namespace std;
void reachhome(int source,int destination){
		cout<<"source:"<<source<<" destination:"<<destination<<endl;
	//base case
	if(source==destination){
		cout<<"punch gaya"<<endl;
		return;
	}
	cout<<"source:"<<source<<" destination:"<<destination<<endl;
	//processing - ek step aage badhao
	 source++;
	// Recursive relation
	return reachhome(source,destination);
}


int main(){
	int destination=10;
	int source=1;
	reachhome(source,destination);
	
	
	
}
