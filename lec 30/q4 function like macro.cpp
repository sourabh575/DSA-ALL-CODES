#include<iostream>
using namespace std;
//function like macro defination
#define min(a,b) (((a) < (b)) ? (a) : (b)) 
/*(((a) < (b)) ? (a) : (b)): This is the code that will be substituted whenever min(a,b) is encountered in the program. Let's break it down further:

(a) < (b): This checks if a is less than b.
?: This is a ternary operator, which works like an if-else statement. It evaluates the condition before the ?. If the condition is true, it returns the value before :; otherwise, it returns the value after :.
(a): This is returned if a is less than b.
:: This separates the true and false conditions in the ternary operator.
(b): This is returned if a is not less than b.
*/
int main(){
	int a=18;
	int b=76;
	printf("minimum value between %d and %d is :%d",a,b,min(a,b));

}
