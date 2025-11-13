#include <iostream>
using namespace std;

void scambia(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void clamp(int &x, int lo, int hi) {
    if (x < lo) {
        x = lo;
    } else if (x > hi) {
        x = hi;
    }
}

int main() {
    int a = 0;
    int b = 0;
    cout << "a b: ";
    cin >> a >> b;
    scambia(a, b);
    cout << "Dopo swap: a=" << a << " b=" << b << endl;
    
    int x = 0;
    int lo = 0;
    int hi = 0;
    cout << "x lo hi: ";
    cin >> x >> lo >> hi;
    clamp(x, lo, hi);
    cout << "Clamp(x): " << x << endl;
}
