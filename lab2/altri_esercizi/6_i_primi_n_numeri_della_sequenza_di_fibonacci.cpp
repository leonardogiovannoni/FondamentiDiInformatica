#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int a = 0;
    int b = 1;

    if (n <= 0) {
        return 0;
    }
    if (n >= 1) {
        cout << 0 << endl;
    }
    if (n >= 2) {
        cout << 1 << endl;
    }

    for (int i = 2; i < n; ++i) {
        int c = a + b;
        cout << c << endl;
        a = b;
        b = c;
    }
    return 0;
}
