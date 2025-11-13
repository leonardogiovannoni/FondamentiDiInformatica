#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0;
    cout << "Inserisci due numeri interi:" << endl;
    cin >> a >> b;
    while (b != 0) {
	    int r = a % b;

        a = b;
        b = r; 
    }
    cout << "Il massimo comune divisore è: " << a << endl;
    return 0;
}
