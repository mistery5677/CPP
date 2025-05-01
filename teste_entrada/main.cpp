#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Bark" << endl;
    }
};

int main() {
    Animal *a = new Dog();
    a->speak();
    delete a;
    return 0;
}
