#include <iostream>
using namespace std;

void eps(int n) {
    int arr[26] = {7,1,8,2,8,1,8,2,8,4,5,9,0,4,5,2,3,5,3,6,0,2,8,7,5, 0};
    if (n == 0) cout << 3;
    else {
        cout << "2.";
        for (int i = 0; i < n - 1; i ++) cout << arr[i];
        if (arr[n] < 5) cout << arr[n-1];
        else cout << arr[n-1]+1;
    }
}

using namespace std;
int main() {
    int n;
    cin >> n;
    eps(n);
    return 0;
}