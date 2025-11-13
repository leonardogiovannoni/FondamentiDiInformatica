#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += i;
    }
    cout << "La somma fa: " << somma << endl;
    return 0;
}
