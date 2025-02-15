#include<iostream>
 #include<math.h>
 using namespace std;
 int main(){
 	int n;
 	cout<<"enter a number:";
 	cin>>n;
 	int ans=0;
 	int i=0;
 	while(n!=0){
 		int bit =n&1;
 		ans=(bit*pow(10,i))+ans;
 		n=n>>1;
 		i++;
 		
	 }
	 cout<<"answer is :"<<ans<<endl;
	 int comp =~ans;
	 int result=comp+1;
	 cout<<result<<endl;
	 //int tcomp=~result;
	 //int answer= tcomp+1;
	 //cout<<answer<<endl;	 
	int tans=0;
 	int j=0;
 	while(result!=0){
 		int digit =result%10;
 		if(digit ==1){
 			
		   ans=pow(2,j)+tans;
	    }
 		result=result/10;
 		j++;
 		
	 }
	 cout<<"answer is :"<<ans<<endl;
 } 
 	
 
  
 	
 
