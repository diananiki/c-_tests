#include <vector>
#include <iostream>
#include <cstdlib>

#define n 2
#define m 3

using namespace std;

double prod(vector<vector<double>> a, vector<double> b){
    vector<double> result(m);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            result[i] += a[j][i] * b[j];
        }
        cout << '\n';
    }

    cout << "result vector: ";
    for (int i = 0; i < m; i++){
        cout << result[i] << " ";
    }
}

int main()
{
    vector<vector<double>> a(n, vector<double>(m));
    vector<double> b(n);

    srand(time(NULL));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = rand() % 10 + 1 ;
        }
    }

    cout << "\n matrix \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++){
        b[i] = rand () % 10 + 1;
    }

    cout << "\n vector \n";
    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << "\n";

    prod(a, b);

    return 0;
}