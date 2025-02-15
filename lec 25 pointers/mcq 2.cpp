#include<iostream>
using namespace std;
int main(){
	int first=16;
	int *ptr=&first;
	int *q=ptr;
	(*q)++;
	cout<<first<<endl;
	
	
}
