#include<iostream>
using namespace std;
inline int getmax(int &a,int &b){
	return (a>b) ? a : b
}

int main(){
	int a=12,b=14;
	int ans=0;
	ans=getmax(a,b);
	cout<<ans<<endl;
	a=a+5;
	b=b+1;
	ans=getmax(a,b);
	cout<<ans<<endl;
}
