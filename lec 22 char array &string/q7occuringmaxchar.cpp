#include<iostream>
#include <unordered_map>
using namespace std;
#include <climits>

char getMaxOccuringChar(string str)
    {
        unordered_map<char, int> charcount;
        
        for(char c:str){
            charcount[c]++;
        }
        
        char maxchar=CHAR_MAX;
        int maxcount=0;
        
        for(const auto &pair: charcount){
            if(pair.second>maxcount || (pair.second==maxcount && pair.first<maxchar)){
                maxchar=pair.first;
                maxcount=pair.second;
            }
        }
        return maxchar;
    }

    int main(){
	string s;
    cout<<"enter string:";
	cin>>s;
	cout<<getMaxOccuringChar(s);

}

