#include <iostream>
#include <cmath>
using namespace std;


void risolvi_equazione(double a, double b, double c) {
    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                cout << "L'equazione ha infinite soluzioni." << endl;
            } else {
                cout << "L'equazione non ha soluzioni." << endl;
            }
        } else {
            double x = -c / b;
            cout << "Equazione di primo grado. Soluzione: x = " << x << endl;
        }
        
    } else {
        double delta = b * b - 4 * a * c;
        
        if (delta > 0.0) {
            double sqrt_delta = sqrt(delta);
            double x1 = (-b + sqrt_delta) / (2 * a);
            double x2 = (-b - sqrt_delta) / (2 * a);

            cout << "Due soluzioni reali distinte:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            
        } else if (delta == 0.0) {
            double x = -b / (2 * a);
            cout << "Una soluzione reale doppia:" << endl;
            cout << "x = " << x << endl;
            
        } else {
            cout << "Nessuna soluzione reale (discriminante negativo)." << endl;
        }
    }
}

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    
    cout << "Inserisci i coefficienti a, b, c: ";
    cin >> a >> b >> c;
    
    risolvi_equazione(a, b, c);

    return 0;
}