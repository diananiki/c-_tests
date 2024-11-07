#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >>a4;
        cout << min(a1 + min(a2, a3) * 2 + min(a1, a2 + a3 + a4 - min(a2, a3) * 2) + 1, a1+a2+a3+a4) << '\n';
    }
    return 0;
}