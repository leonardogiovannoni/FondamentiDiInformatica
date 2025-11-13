#include <iostream>
using namespace std;


int main() {
    int n = 0;
    cin >> n;
    // in genere meglio utilizzare nei `for` gli intervalli chiusi
    // a sinistra e aperti a destra, come [1, 11) per evitare errori di off-by-one,
    // ma qui è troppo più naturale usare [1, 10]
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << (n * i) << endl;
    }

    return 0;
}
