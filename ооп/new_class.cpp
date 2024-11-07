#include <iostream>
#include <new>
using namespace std;

class Class {
public:
    Class(int a, int b) {
        n1 = a;
        n2 = b;
    }
    void print();
    void change(int a, int b);
    void product();
    void minimum();
    ~Class();
private:
    int n1, n2;
};

void Class::print() {
    cout << n1 << ' ' << n2 << '\n';
}

void Class::change(int a, int b) {
    n1 = a;
    n2 = b;
}

void Class::product() {
    cout << n1 * n2 << '\n';
}

void Class::minimum() {
    cout << min(n1, n2) << '\n';
}

Class::~Class(){}



int main() {
    int a, b;
    cin >> a >> b;
    Class new_class(a, b);
    new_class.print();
    new_class.change(a + 1, b + 1);
    new_class.print();
    new_class.product();
    new_class.minimum();
    return 0;
}