#include <iostream>
#include <cmath> // Necessario per la funzione sqrt() che calcola la radice quadrata
using namespace std;

// 
// Funzione che risolve un'equazione di secondo grado nella forma ax² + bx + c = 0
// 
// il parametro `a` è il coefficiente del termine quadratico (x²)
// il parametro `b` è il coefficiente del termine lineare (x)
// il parametro `c` è il termine noto (costante)
// 
// La funzione gestisce tutti i casi possibili:
// - Equazione di secondo grado (a ≠ 0)
// - Equazione di primo grado (a = 0, b ≠ 0)
// - Casi degeneri (a = 0, b = 0)
// 
void risolvi_equazione(double a, double b, double c) {
    if (a == 0.0) {
        // a = 0 → Non è un'equazione di secondo grado
        // L'equazione diventa: bx + c = 0
        
        if (b == 0.0) {
            // Anche b = 0, l'equazione diventa: c = 0
            
            if (c == 0.0) {
                // 0 = 0 → Identità sempre vera
                cout << "L'equazione ha infinite soluzioni." << endl;
            } else {
                // c = 0 con c ≠ 0 → Contraddizione (es: 5 = 0)
                cout << "L'equazione non ha soluzioni." << endl;
            }
        } else {
            // b ≠ 0 → Equazione di primo grado: bx + c = 0
            // Soluzione: x = -c/b
            double x = -c / b;
            cout << "Equazione di primo grado. Soluzione: x = " << x << endl;
        }
        
    } else {
        // a ≠ 0 → Equazione di secondo grado: ax² + bx + c = 0
        
        // Calcolo del discriminante (Δ = b² - 4ac)
        // Il discriminante determina il numero e la natura delle soluzioni
        double delta = b * b - 4 * a * c;
        
        if (delta > 0.0) {
            // Δ > 0 → Due soluzioni reali e distinte
            // Formula: x = (-b ± √Δ) / (2a)
            
            // Calcola √Δ una sola volta per efficienza
            double sqrt_delta = sqrt(delta);
            double x1 = (-b + sqrt_delta) / (2 * a); // Prima soluzione
            double x2 = (-b - sqrt_delta) / (2 * a); // Seconda soluzione
            
            cout << "Due soluzioni reali distinte:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            
        } else if (delta == 0.0) {
            // Δ = 0 → Una soluzione reale doppia (due radici coincidenti)
            // Formula semplificata: x = -b / (2a)
            
            double x = -b / (2 * a);
            cout << "Una soluzione reale doppia:" << endl;
            cout << "x = " << x << endl;
            
        } else {
            // Δ < 0 → Nessuna soluzione reale (soluzioni complesse coniugate).
            // In questo programma non gestiamo i numeri complessi
            cout << "Nessuna soluzione reale (discriminante negativo)." << endl;
        }
    }
}

int main() {
    // Dichiarazione e inizializzazione delle variabili per i coefficienti
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    
    cout << "Inserisci i coefficienti a, b, c: ";
    cin >> a >> b >> c;
    
    risolvi_equazione(a, b, c);

    return 0;
}