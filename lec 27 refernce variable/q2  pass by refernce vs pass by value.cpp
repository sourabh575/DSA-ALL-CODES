#include<iostream>
using namespace std;
void update1(int n){
	n++;
}
void update2(int &n){
	n++;
}

int main(){
	int n;
	cout<<"enter a number:"<<endl;
	cin>>n;
	update1(n);
	cout<<"pass by value:"<<n<<endl;
	update2(n);
	cout<<"pass by refrences:"<<n<<endl;

}
