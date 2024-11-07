#include <iostream>
#include <vector>
#define N 7

using namespace std;

double sled(vector<vector<double>> A){
    double sum = 0;
    for (int i=0; i<N; i++){
        sum+=A[i][i];
    }
    return sum;
}

int main() {
    vector<vector<double>> A(N, vector<double>(N));

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++) {
            A[i][j] = rand() % 100;
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout <<A[i][j]<<"\t";
        }
        cout << endl;
    }

    cout << sled(A);

    return 0;
}