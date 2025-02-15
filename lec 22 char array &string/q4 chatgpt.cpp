#include<iostream>
using namespace std;

void tolowercase(char name[]){
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] = name[i] - 'A' + 'a';
        }
    }
}

bool palindrome(char name[], int n){
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (name[i] != name[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;    
}

int getlength(char name[]){
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main(){
    char name[20];
    cout << "Enter your name: ";
    cin >> name;
    int len = getlength(name);
    tolowercase(name);
    if (palindrome(name, len)) {
        cout << "This is a palindrome";
    } else {
        cout << "This is not a palindrome";
    }
    return 0;
}


