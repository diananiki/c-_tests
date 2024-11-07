#include <iostream>
using namespace std;

int res = 0;

template<class Type>
Type search(Type **arr, Type s, int rows, int cols){
    res = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == s) {
                res += 1;
            }
        }
    }
    if (res > 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    int **M = new int *[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    }
    int s;
    cin >> s;
    if (search(M, s, n, m)) {
        cout << "Yes " << res << '\n';
    } else {
        cout << "No" << '\n';
    }
    cin >> n >> m;
    double **M1 = new double *[n];
    for (int i = 0; i < n; i++) {
        M1[i] = new double[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> M1[i][j];
    }
    double s1;
    cin >> s1;
    if (search(M1, s1, n, m)) {
        cout << "Yes " << res << '\n';
    } else {
        cout << "No" << '\n';
    }
    cin >> n >> m;
    char **M2 = new char *[n];
    for (int i = 0; i < n; i++) {
        M2[i] = new char[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> M2[i][j];
    }
    char s2;
    cin >> s2;
    if (search(M2, s2, n, m)) {
        cout << "Yes " << res << '\n';
    } else {
        cout << "No" << '\n';
    }
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    for (int i = 0; i < n; i++) {
        delete[] M1[i];
    }
    for (int i = 0; i < n; i++) {
        delete[] M2[i];
    }
    delete[] M;
    delete[] M1;
    delete[] M2;
    return 0;
}


///#include <iostream>
//using namespace std;
//
//void F(int *M, int n) {
//    int ma = M[1], mi = M[0];
//    for (int i = 2; i < n; i++) {
//        if (i % 2 == 0) {
//            mi = min(mi, M[i]);
//        } else {
//            ma = max(ma, M[i]);
//        }
//    }
//    cout << mi + ma;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    int *M = new int [n];
//    for (int i = 0; i < n; i++) {
//        cin >> M[i];
//    }
//    F(M, n);
//    delete[] M;
//    return 0;
//}