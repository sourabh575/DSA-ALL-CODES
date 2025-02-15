#include<iostream>
using namespace std;
int main(){
	cout<<endl;
	while(true){
	    int num=1;
	    char ch='1';
	
		
		switch(ch){
		case 1:cout<<"first"<<endl;
               cout<<"first again"<<endl;
			   break;
		case '1':switch(num){
			case 1:cout<<"value of num is "<<num<<endl;
			exit(1);
		}	   
		break;
		default :cout<<"It is default case"<<endl;
			break;
		}
	
	}
}
