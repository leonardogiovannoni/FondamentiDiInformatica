/*4 Scambio con puntatori
Testo. Scrivi una funzione che scambia due valori interi utilizzando i puntatori. La
funzione deve avere la seguente firma:
void scambia(int *a, int *b);
Nel programma principale, leggi due interi, scambiali usando la funzione e stampa i nuovi
valori.*/

#include <iostream>
using namespace std;
/** 
 * Scambia i valori interi a cui puntano i puntatori `a` e `b`.
 * 
 * @param a Puntatore non nullo al primo intero.
 * @param b Puntatore non nullo al secondo intero.
 */
// scriviamo nel commento che i puntatori non devono essere nulli.
void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 0;
    int b = 0;
    cin >> a >> b;

    scambia(&a, &b);  // Passiamo gli indirizzi di `a` e `b` alla funzione.
    cout << "Dopo scambio: a = " 
         << a << " b = " << b << endl;
}