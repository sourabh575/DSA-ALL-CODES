#include<iostream>
using namespace std;
int modularexponentation(int x,int n,int m){
	int res=1;
	while(n>0){
		if(n&1){
			res=((res)*(x)%m)%m;
	    }
	    x=((x)%m)%m;
	    n=n>>1;
	
	}
	return res;	
}
int main(){
	int x,n,m;
	cin>>x>>n>>m;
	cout<<modularexponentation(x,n,m);
}
