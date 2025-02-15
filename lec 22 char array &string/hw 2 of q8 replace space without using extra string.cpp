 #include<iostream>
using namespace std;
string spacereplace(string str){
	//string temp=" ";
	for(int i=0;i<str.length();i++){
		if(str[i]==' '){
			str.push_back('@');
			str.push_back('4');
			str.push_back('0');
		}
		else{
			str[i]=str[i];
		}
	
	}
	return str;
	
}
int main(){
	string str="my name is sourabh";
	cout<<str<<endl;
	cout<<spacereplace(str)<<endl;
}
