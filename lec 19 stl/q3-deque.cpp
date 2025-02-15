#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<int>d;
	d.push_back(1);
	d.push_back(2);
	for(int i:d){
		cout<<i<<" ";
	}cout<<endl;
	cout<<"element at 1nd index:"<<d.at(1)<<endl;
	cout<<"empty or not:"<<d.empty()<<endl;
	cout<<"first element:"<<d.front()<<endl;
	cout<<"last element:"<<d.back()<<endl;
	cout<<"before erase "<<d.size()<<endl;
	d.erase(d.begin(),d.begin()+1);
	cout<<"after erase "<<d.size()<<endl;	
}
