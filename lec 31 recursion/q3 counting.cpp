#include<iostream>
using namespace std;
void counting(int n){
	//base case
	if(n==0)
		return ;

	//tail recursion
	cout<<n<<endl;
	counting(n-1);
	//head recursion
	cout<<n<<endl;
}

int main(){
	int n;
	cin>>n;
	counting(n);
	
}
