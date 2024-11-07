#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a % 10 == 0) cout << 0;
    else {
        int s = pow(a % 10,b % 4);
        cout << s % 10;
    }
    return 0;
}