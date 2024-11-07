#include <iostream>
using namespace std;

long int F(long int a, long int b) {
    if (a == 0 and b == 0) {
        return 0;
    } else if (a > b) {
        return F(a - 1, b) + b;
    } else if (b >= a) {
        return F(a, b - 1) + a;
    }
}

int main() {
    for (long int a = 0; a < 100000; a+=110) {
        for (long int b = 0; b < 100000; b+=100) {
            if (F(a, b) == 333396000) {
                cout << a << b;
            }
        }
    }
}