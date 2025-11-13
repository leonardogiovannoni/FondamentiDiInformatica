/* Scrivere un programma che esegua un menu per fare delle operazioni.

 MENU
 A - Stampa la somma di due numeri
 B - Stampa la differenza di due numeri
 T -    Esce dal programma

 Il programma deve
     - stampare il menu
     - leggere un carattere e in base al carattere eseguire l'operazione e
         stampare il risultato
     - terminare se legge il carattere T
     - stampare "Scelta non valida" e presentare di nuovo il menu
         se il carattere è diverso da A, B, T
*/
#include <iostream>
using namespace std;

int main() {
    char opt = 'X';
    do {
        cout << "MENU " << endl;
        cout << "S - Stampa la somma di due numeri" << endl;
        cout << "D - Stampa la differenza di due numeri" << endl;
        cout << "X - Esce dal programma" << endl << endl;
        cin >> opt;
        int a = 0;
        int b = 0;
        switch (opt) {
            case 'S': {
                cout << "Inserisci due numeri" << endl;
                cin >> a >> b;
                int sum = a + b;
                cout << "Somma:" << sum << endl << endl;
                break;
            }
            case 'D': {
                cout << "Inserisci due numeri" << endl;
                int diff = a - b;
                cout << "Differenza:" << diff << endl << endl;
                break;
            }
            case 'X': {
                cout << endl;
                break;
            }
            default: {
                cout << "Scelta non valida" << endl << endl;
            }
        }
    } while (opt != 'X');

    return 0;
}
