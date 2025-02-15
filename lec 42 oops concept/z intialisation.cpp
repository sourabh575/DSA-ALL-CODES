#include <iostream>

class MyClass {
private:
    int myInt;
    double myDouble;

public:
    // Constructor with initialization list
    MyClass(int i, double d) : myInt(i), myDouble(d) {
        // Constructor body (if needed)
        std::cout << "Constructor called with values: " << myInt << ", " << myDouble << std::endl;
    }

    // Other member functions...
};

int main() {
    // Creating an object of MyClass
    MyClass obj(5, 3.14);

    return 0;
}
