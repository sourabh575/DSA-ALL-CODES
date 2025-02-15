#include<iostream>
#include<vector>
using namespace std;

void solve(string digit,string output,int index,vector<string>& ans,string mapping[]){
	//base case
	if(index>=digit.length()){
		ans.push_back(output);
		return;
	}
	int number=digit[index]-'0';
	string value=mapping[number];
	
	for(int i=0;i<value.length();i++){
		output.push_back(value[i]);
		solve(digit,output,index+1,ans,mapping);
	//	output.pop_back();
	    output.erase(output.size() - 1);
	
	
	}
}
vector<string> lettercombinations(string digit){
	vector<string>ans;
	
	if(digit.length()==0)
		return ans;
	string output;
	int index=0;
	string mapping[10]={"","","abc","def","jkl","mno","pqrs","tuv","wxyz"};
	solve(digit,output,index,ans,mapping);
	return ans; 
}

/*int main(){
    string digit="23";
    vector<string> result = lettercombinations(digit);

    // Print the result
    for(const auto& str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
*/
int main(){
    string digit="23";
    cout<<digit.length()<<endl;
    vector<string> result = lettercombinations(digit);

    // Print the result using a normal for loop
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

