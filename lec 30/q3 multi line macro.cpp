#include<iostream>
using namespace std;
//multi line macro 
#define ELE 1,\
2,\
3

int main(){
	int arr[]={ ELE } ;
	for(int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	}

}
