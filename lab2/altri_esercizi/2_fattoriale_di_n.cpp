#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int fatt = 1;
    for (int i = 0; i < n; i++) {
        int mul = i + 1;
        fatt *= mul;
    }
    cout << "Il fattoriale e' " << fatt << endl;
    return 0;
}
