#include <iostream>
#include <new>
using namespace std;

class Square {
public:
    Square(int s_size, int **M) {
        size = s_size;
        arr = new int *[size];
        for (int i = 0; i < size; i++) {
            arr[i] = new int[size];
            for (int j = 0; j < size; j++) {
                arr[i][j] = M[i][j];
            }
        }
    }

    Square operator +(const Square&square) {
        int **M = new int *[size];
        for (int i = 0; i < size; i++) {
            M[i] = new int[size];
            for (int j = 0; j < size; j++) {
                M[i][j] = square.arr[i][j]+arr[i][j];
            }
        }
        Square result(size, M);
        for (int i = 0; i < size; i++) {
            delete[] M[i];
        }
        delete[] M;
        return result;
    }

    Square operator -(const Square&square) {
        int **M = new int *[size];
        for (int i = 0; i < size; i++) {
            M[i] = new int[size];
            for (int j = 0; j < size; j++) {
                M[i][j] = arr[i][j]-square.arr[i][j];
            }
        }
        Square result(size, M);
        for (int i = 0; i < size; i++) {
            delete[] M[i];
        }
        delete[] M;
        return result;
    }

    Square operator *(const int& a) {
        int **M = new int *[size];
        for (int i = 0; i < size; i++) {
            M[i] = new int[size];
            for (int j = 0; j < size; j++) {
                M[i][j] = arr[i][j] * a;
            }
        }
        Square result(size, M);
        for (int i = 0; i < size; i++) {
            delete[] M[i];
        }
        delete[] M;
        return result;
    }

    void trans() {
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                int pred = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = pred;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }

    ~Square() {
        for (int i = 0; i < size; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

private:
    int** arr;
    int size;
};


int main() {
    int size;
    int a;
    cin >> size >> a;
    int **M = new int *[size];
    for (int i = 0; i < size; i++) {
        M[i] = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> M[i][j];
        }
    }
    Square Q1(size, M);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> M[i][j];
        }
    }
    Square Q2(size, M);
    for (int i = 0; i < size; i++) {
        delete[] M[i];
    }
    delete[] M;
    (Q1 + Q2).print();
    (Q1 - Q2).print();
    (Q1 * a).print();
    Q1.trans();
    Q1.print();
    return 0;
}