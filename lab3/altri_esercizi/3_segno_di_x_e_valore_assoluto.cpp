#include <iostream>
using namespace std;

int segno(int x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}
int abs_int(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main() {
    int x = 0;
    cout << "x: ";
    cin >> x;
    cout << "segno(x) = " << segno(x) << endl;
    cout << "|x| = " << abs_int(x) << endl;
}
