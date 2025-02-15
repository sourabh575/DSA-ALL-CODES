#include<iostream>
using namespace std;

class MyClass {
public:
    int getValue() const; // Constant member function
private:
    int data;
};

int MyClass::getValue() const {
    // data = 10; // Error: Cannot modify member variables in a const member function
    return data;
}

int main() {
    const MyClass obj;
    obj.getValue(); // Allowed since getValue() is const
    return 0;
}

