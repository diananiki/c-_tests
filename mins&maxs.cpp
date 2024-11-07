//задача про четные минимумы и нечетные максимумы
#include <iostream>
using namespace std;

void F(int *M, int n) {
    int ma = M[1], mi = M[0];
    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
            mi = min(mi, M[i]);
        } else {
            ma = max(ma, M[i]);
        }
    }
    cout << mi + ma;
}

int main() {
    int n;
    cin >> n;
    int *M = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }
    F(M, n);
    delete[] M;
    return 0;
}