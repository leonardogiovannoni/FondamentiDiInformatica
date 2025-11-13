#include <iostream>
using namespace std;

int main() {
    // Utilizziamo una costante per definire la dimensione dell'array.
    // Questo ci permette di cambiare facilmente la dimensione in un
    // unico punto del codice, invece di dover modificare ogni
    // occorrenza del numero "magico" 6 sparsa nel programma.
    // Inoltre, usando una costante, evitiamo errori di battitura
    // e rendiamo chiaro il significato del numero.
    // Per le costanti useremo sempre la naming convention con lettere
    // maiuscole e underscore tra le parole.
    const int N = 6;
    // Dichiarazione e inizializzazione dell'array di dimensione N.
    // Le graffe vuote {} si utilizzano per inizializzare tutti gli
    // elementi a zero.
    // Questo è equivalente a scrivere:
    // ```
    // int arr[N];
    // for (int i = 0; i < N; i++) {
    //     arr[i] = 0;
    // }
    // ```
    // Ma noi preferiamo inizializzare direttamente l'array a zero 
    // al momento della dichiarazione e questa sintassi è anche più
    // concisa.
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int num_pari = 0;
    for (int i = 0; i < N; i++) {
        // Un numero è pari se e solo se il resto della divisione per 2 è zero.
        if (arr[i] % 2 == 0) {
            num_pari++;
        }
    }
    cout << "Risultato: " << num_pari << endl;

    return 0;
}
