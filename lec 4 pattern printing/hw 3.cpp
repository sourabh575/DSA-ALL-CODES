#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter a number:";
	cin>>n;
	for (int i = 0; i <n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < n - i; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
	
}

