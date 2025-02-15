#include<iostream>
using namespace std;
bool isprime(int n){
	if(n<=1){
		return false;
	}
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
			break;
		}
	}
	return true;
}
int countprime(int n){
	int count=0;
	for(int i=2;i<n;i++){
		if(isprime(i)){
			count++;
		}
	}
	return count;
}
int main(){
	int n;
	cout<<"enter a number:"<<endl;
	cin>>n;
	cout<<"total no of prime number in range from 2 to "<<n<<":"<<countprime(n)<<endl;
	
}
