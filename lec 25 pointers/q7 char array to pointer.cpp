#include<iostream>
using namespace std;
int main(){
	int arr[5]={1,2,3,4,5};
	char ch[10]="hello";
	cout<<arr<<endl;
	cout<<ch<<endl;
	char *c=ch;
	cout<<c<<endl;
	
	char temp='z';
	char *p=&temp;
	cout<<p<<endl;
}
