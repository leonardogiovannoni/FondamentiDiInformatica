#include <iostream>
using namespace std;

void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Questa funzione ha la seguente firma:
// ```
// void inverti(int arr[], int n); (1)
// ```
// La firma sopra è equivalente e intercambiabile con:
// ```
// void inverti(int *arr, int n); (2)
// ```
// Questa cosa cosa è davvero terribile se pensiamo che ogni volta
// che vediamo un puntatore a un tipo T, in realtà potrebbe essere
// un array di T. Se un linguaggio simile al C++ venisse scritto oggi,
// probabilmente non avrebbe questa ambiguità e un puntatore a T 
// riferirebbe sempre e solo a un singolo elemento di tipo T, mentre
// gli array sarebbero gestiti in modo distinto.
// Detto questo, l'unica maniera per capire se un puntatore
// è in realtà un array è il contesto in cui viene utilizzato
// e sperabilmente un commento di documentazione.
// Da ora in avanti, utilizzeremo nelle firme delle funzioni
// (ma non altrove, perché la sintassi non lo permette) la sintassi
// (1) per ricordarci che il parametro non è un puntatore a un singolo
// elemento, ma è il puntatore al primo elemento di un array.
void inverti(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        // arr[i] e arr[n - 1 - i] sono gli elementi
        // da scambiare
        // La sintassi arr[i] è solo un ergonomico per *(arr + i)
        scambia(&arr[i], &arr[n - 1 - i]);
    }
}

int main() {
    const int N = 5;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Array originale: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Passare un array ad una funzione non è pulito in C++: A me piacerebbe passare
    // un riferimento o un puntatore ad un generico *array* di dimensione N, ma C++
    // (per quanto vediamo noi) non lo permette, perché ho bisogno di essere generico
    // rispetto alla dimensione dell'array e di passare un riferimento o puntatore ad
    // un array. In particolare, quando dichiaro un array
    // ```
    // int arr[5] = {};
    // ```
    // sto dichiarando la variabile `arr` con tipo `int[5]`. I tipi riferimenti ad
    // array e puntatori ad array esistono, ma hanno una sintassi scomoda e in
    // pratica non sono mai utilizzati (per noi non esisteranno). La sintassi è
    // questa `int (&ref)[5] = arr` per un riferimento ad un array di 5 interi, e
    // `int (*ptr)[5] = &arr` per un puntatore ad un array di 5 interi, detto
    // questo, questa sintassi può essere dimenticata alla fine del prossimo
    // paragrafo. Se noi pensassimo a un riferimento (o puntatore) ad un array, in
    // ogni caso il tipo dovrebbe contenere la dimensione (int (&ref)[5] oppure int
    // (*ref)[5]), il che rende scomodo passarlo alle funzioni sia che utilizzassimo
    // un riferimento, un puntatore o la copia. Quando passiamo un array a una
    // funzione, vorrei potergli passare un array generico rispetto alla dimensione
    // cioè se ho un codice del genere
    // ```
    // int arr1[2] = { 1, 2 }; 
    // int arr2[3] = { 2, 3, 4 };
    // riordina(arr1, ..);
    // riordina(arr2, ..);
    // ```
    // Vorrei potergli passare entrambi gli array alla funzione `riordina` senza
    // dover creare due overload diversi per ogni dimensione. La soluzione che adotta
    // il C++ è quella di passare il puntatore al primo elemento dell'array e un
    // indicatore (come la dimensione o l'ultimo indice valido) che ci faccia capire
    // quanto grande è l'array. Noi passeremo sempre il puntatore al primo elemento e
    // la dimensione dell'array.
    // ```
    // int arr1[2] = { 1, 2 };
    // int arr2[3] = { 2, 3, 4 };
    // riordina(&arr1[0], 2); // passo alla funzione il puntatore al primo elemento
    //                        // e la dimensione dell'array
    // riordina(&arr2[0], 3); // passo alla funzione il puntatore al primo elemento
    //                        // e la dimensione dell'array
    // ```
    // L'idea è che la funzione chiamata, ricevendo il puntatore al primo elemento,
    // può accedere a tutti gli altri elementi e non oltre sapendo quanti sono
    // (tramite la dimensione passata), utilizzando l'aritmetica dei puntatori. Per
    // rendere più ergonomico l'utilizzo dell'aritmetica dei puntatori, in C++
    // possiamo utilizzare la sintassi delle parentesi quadre `[]` anche quando
    // lavoriamo con i puntatori, ben sapendo che in realtà stiamo lavorando con dei
    // puntatori. Questa sovrapposizione di sintassi dove su un puntatore possiamo
    // usare la sintassi delle `[]` degli array è chiaramente voluta in C++. L'idea è
    // che il puntatore è strettamente legato al concetto di array, perché entrambi
    // possono essere utilizzati per accedere a una sequenza di elementi contigui in
    // memoria. L'esempio sopra infatti può essere riscritto come:
    // ```
    // int arr1[2] = { 1, 2 };
    // int arr2[3] = { 2, 3, 4 };
    // riordina(arr1, 2); // arr1 è convertito implicitamente in un
    //                    // puntatore al primo elemento dell'array
    // riordina(arr2, 3); // arr2 è convertito implicitamente in un
    //                    // puntatore al primo elemento dell'array
    // ```
    // E ha lo stesso comportamento dell'esempio precedente, dove però ciò che cambia
    // è che il compilatore esegue implicitamente la conversione da array a
    // puntatore, ovvero da `int[2]` a `int*` e da `int[3]` a `int*`, e questa
    // conversione corrisponde a passare alla funzione il puntatore al primo elemento
    // dell'array (il primo elemento dell'array ha anche lo stesso indirizzo
    // dell'array stesso). Questo è abbastanza strano, perché siamo abituati a
    // pensare che, a meno di riferimenti, la sintassi `foo(var)` passi sempre una
    // copia del valore di `var` alla funzione `foo`. In questo caso invece, passiamo
    // "una copia" del puntatore al primo elemento dell'array. Si dice che il tipo
    // array "decade" in un puntatore, dove "decade" significa che perde alcune delle
    // sue proprietà (la dimensione). La decadenza automatica degli array in puntatori
    // è una caratteristica del C++ ed è a tutti gli effetti una debolezza del sistema
    // di tipi, che porta a svariati possibili bug. L'idea è validissima: usare la
    // coppia `(puntatore primo elemento, dimensione)` per rappresentare un array in
    // modo generico. Come il C++ lo implementa però è error-prone e non immediato da
    // comprendere.
    inverti(arr, N);

    cout << "Array invertito: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
