#include <iostream>
using namespace std;

int main() {
    int t, n, a, pred;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        bool lf = false, gigares = false;
        int res = 0;
        cin >> pred;
        for (int j = 1; j < n; j++) {
            cin >> a;
            if (j == 1 and pred <= a) {
                lf = true;
            }
            if (j == n - 1 and pred >= a) {
                if (lf or pred > a) {
                    res += 1;
                    gigares = true;
                    if (res > 1) {
                        gigares = false;
                        break;
                    }
                }
            }
            if (pred < a) {
                if (lf) {
                    res += 1;
                    gigares = true;
                    if (res > 1) {
                        gigares = false;
                        break;
                    }
                }
                lf = false;
            } else if (pred > a) {
                lf = true;
            }
            pred = a;
        }
        if (n == 1) {
            cout << "YES" << '\n';
        } else if (gigares) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}