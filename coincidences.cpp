//удаление чисел с одинаковыми цифрами
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> M;
    for (int i = 1; i <= 10000; i++) {
        if (i < 10) {}
        else if (i < 100) {
            if (i / 10 == i % 10) {
                continue;
            }
        }
        else if (i < 1000) {
            if (i / 10 % 10 == i % 10 or i / 100 == i % 10 or i / 100 == i / 10 % 10) {
                continue;
            }
        }
        else {
            if (i / 1000 == i % 10 or i / 10000 == i / 100 % 10 or i / 10000 == i / 10 % 10 or i / 10 % 10 == i % 10 or i / 10 % 10 == i / 100 % 10 or i / 100 % 10 == i % 10) {
                continue;
            }
        }
        M.push_back(i);
    }
    int n;
    cin >> n;
    cout << M[n - 1];
    return 0;
}