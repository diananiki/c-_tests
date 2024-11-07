//поиск дырки в массиве
#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int rand_el;
    cin >> n;
    vector<int> arr(n + 1);
    iota(arr.begin() + 1, arr.end(), 1);
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
    uniform_int_distribution<> dist(0, n);
    rand_el = dist(g);
    arr.erase(arr.begin() + rand_el, arr.begin() + rand_el + 1);
    cout << "Random array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int sum_arr;
    sum_arr = accumulate(arr.begin(), arr.end(), 0);
    cout <<  '\n' << n*(n+1)/2 - sum_arr;
    return 0;
}