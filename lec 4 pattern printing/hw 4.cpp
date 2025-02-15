#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	for (int i = 1; i <=n; ++i) {
        for (int j = 0; j < i-1; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k <= n - i; ++k) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
	
}

