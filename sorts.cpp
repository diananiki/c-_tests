///сортировки
#include <iostream>
#include <new>
using namespace std;

void bubble(int *arr, int m) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                res += 1;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << res;
}

void insert(int *arr, int m) {
    int res = 0;
    for (int i = 1; i < m; i++) {
        int n = arr[i];
        int j = i;
        while (j > 0 and arr[j - 1] > n) {
            res += 1;
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = n;
    }
    cout << res;
}

int res = 0;
void speed(int *arr, int s, int f) {
    int i = s;
    int j = f;
    int med = arr[(i + j) / 2];
    while (i <= j) {
        while (arr[i] < med)
            i++;
        while (arr[j] > med)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            res += 1;
            i++;
            j--;
        }
    }
    if (j > s)
        speed(arr, s, j);
    if (i < f)
        speed(arr, i, f);
}

int main() {
    int n, a;
    cin >> n;
    int *M = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }
    cout << "choose: 1 - bubble, 2 - insert, 3 - quick";
    int num;
    cin >> num;
    if (num == 1) {
        bubble(M, n);
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << M[i] << " ";
        }
    }
    if (num == 2) {
        insert(M, n);
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << M[i] << " ";
        }
    }
    if (num == 3) {
        speed(M, 0, n - 1);
        cout << res << '\n';
        for (int i = 0; i < n; i++) {
            cout << M[i] << " ";
        }
    }
    delete[] M;
    return 0;
}