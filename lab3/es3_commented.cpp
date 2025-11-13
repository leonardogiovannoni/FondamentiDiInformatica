#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0; 
    cin >> a >> b;
   
    int *max_ptr = nullptr; // Puntatore che punterà al numero maggiore.
    // Lo inizializziamo a `nullptr` (puntatore nullo),
    // ovvero gli stiamo dando il valore "0",
    // che per convenzione non è un indirizzo valido
    // in memoria.
    // (`int *p = nullptr; *p = 5;` => il programma crasha).
    // Utilizzeremo `nullptr` sia come valore iniziale
    // quando non sappiamo ancora a cosa far puntare il
    // puntatore, sia come valore sentinella per indicare
    // che il puntatore non contiene un valore valido.
    // Ne seguirà che ogni volta che useremo il puntatore,
    // dovremo prima assicurarci che non sia `nullptr`,
    // eccetto casi banali dove siamo certi che il puntatore
    // è stato inizializzato correttamente (come in questo
    // caso, quando avremo eseguito l'assegnamento all'indirizzo 
    // del numero maggiore).

    // Assegniamo a `max_ptr` l'indirizzo del numero maggiore
    if (a > b) {
        // in questo caso utilizziamo l'operatore `address-of`
        max_ptr = &a;       // che restituisce l'indirizzo di memoria della
    } else {                // variabile. L'operatore address-of è rappresentato
        max_ptr = &b;       // dall'ampersand (`&`).
    }   // Purtroppo, è lo stesso simbolo usato per i
        // riferimenti. Chiariamo che l'operatore `address-of`
        // e il riferimento non hanno _NULLA_ a che vedere
        // l'uno con l'altro.
        // Nel caso del riferimento, l'ampersand _fa parte
        // del tipo_ della variabile, quindi se scriviamo 
        // ```
        // int a = 5;
        // int &ra = a;
        // ```
        // Stiamo dichiarando la variabile `a` di tipo `int`
        // e la variabile `ra` di tipo "int&".
        // Nel caso dell'operatore `address-of`, l'ampersand
        // si applica a una _variabile_ (non a un tipo) e
        // restituisce l'indirizzo di memoria di quella
        // variabile.
        // Usare due simboli diversi avrebbe aiutato a evitare
        // confusione, ma purtroppo in C++ è andata così.

        // In maniera analoga a quanto detto poc'anzi,
        // l'asterisco (`*`) ha due significati diversi
        // (escludendo la molitplicazione): 
        // uno quando fa parte di una dichiarazione di
        // variabile (dichiarazione di un puntatore), e uno
        // quando è usato come operatore di dereferenziazione.
        // Nel primo caso abbiamo una situazione del genere:
        // ```
        // int a = 5;
        // int *pa = &a;
        // ```
        // Qui stiamo dichiarando la variabile `pa` di tipo
        // "int*", che conterrà _il valore numerico
        // dell'indirizzo in memoria_ di `a`.
        // Nel secondo caso abbiamo una situazione del genere:
        // ``` (1)
        // int a = 5;
        // int *pa = &a; // primo caso: dichiarazione
        // // (* secondo caso
        // int b = *pa; // dereferenziazione per lettura
        // *pa = 10; // dereferenziazione per scrittura
        // // secondo caso *)
        // ```
        // Qui stiamo usando l'operatore di dereferenziazione
        // (`*`) per ottenere il valore a cui punta il
        // puntatore. Con `int b = *pa;` stiamo leggendo il
        // valore contenuto nell'indirizzo di memoria
        // memorizzato in `pa` (ovvero `a`) e lo stiamo
        // copiando in `b`, mentre con `*pa = 10;` stiamo
        // scrivendo il valore `10` nell'indirizzo di memoria
        // memorizzato in `pa` (ovvero stiamo sovrascrivendo
        // `a` con la logica dell'esempio (1)).
        // In breve: `pa` ti dice _dove_ sta la variabile,
        // `*pa` ti fa vedere (o modificare) _cosa_ c'è lì.
        // Un puntatore come `int*` non è _niente di più_ che
        // una variabile che contiene un numero esattamente
        // come una variabile di tipo `int`, o `long`.
        // La differenza è che su quella variabile possiamo
        // usare l'operatore di dereferenziazione (`*`) per
        // leggere o scrivere il valore memorizzato
        // nell'indirizzo di memoria indicato dal numero
        // contenuto nel puntatore. Una variabile puntatore
        // occupa SEMPRE 8 byte (su architetture a 64 bit
        // ovvero il 99% dei computer moderni), ne segue che
        // la dimensione _della variabile puntatore_ (e NON
        // _del valore puntato dalla variabile puntatore_) è
        // sempre la stessa, indipendente dal tipo di dato a
        // cui punta, essendo semplicemente un numero che
        // rappresenta un indirizzo di memoria.
        // Se pensiamo alla memoria come un grande array di
        // byte, un puntatore è semplicemente un indice in
        // quell'array (chiamato indirizzo) che ci dice _dove_
        // si trova il dato che ci interessa e ci ricorda
        // anche di che tipo è quel dato (in modo da sapere
        // quanti byte leggere o scrivere).

    cout << "Il numero maggiore è: " << *max_ptr << endl;
    *max_ptr = 0;
    cout << "Dopo l'azzeramento, i valori sono: a = " 
         << a << ", b = " << b << endl;
    return 0;
}


// ==================================================
//                  APPROFONDIMENTO
// ==================================================
//
// Immagina la memoria del computer come un vettore ENORME:
//
//    byte memoria[4294967296];  // miliardi di celle da un byte!
//
// Ogni cella può contenere 1 byte (un numeretto da 0 a 255 estremi inclusi).
// 1 byte => 2 cifre esadecimali (da 0x00 a 0xff estremi inclusi).
// 2 byte => 4 cifre esadecimali (da 0x00_00 a 0xff_ff estremi inclusi, ci mettiamo
// un underscore per leggerlo meglio).
// 4 byte => 8 cifre esadecimali (da 0x00_00_00_00 a 0xff_ff_ff_ff estremi inclusi).
// e così via.
// Ogni cella ha la sua posizione (indirizzo).
//
//
//   POSIZIONE             CONTENUTO
//   (indirizzo)           (1 byte)
//   ---------------       --------
//
//   memoria[0x0..00000] -> [0xde]      // byte di memoria...   
//   memoria[0x0..00001] -> [0xad]      // byte di memoria...
//   memoria[0x0..00002] -> [0xbe]      // byte di memoria...
//   memoria[0x0..00003] -> [0xef]      // byte di memoria...
//        ...            ...
//
//   memoria[0x0..01000] -> [0x05]  <-- int a = 5; inizia qui!
//   memoria[0x0..01001] -> [0x00]      (occupa 4 celle di fila, 
//   memoria[0x0..01002] -> [0x00]      perché un `int` occupa 4 byte, 
//   memoria[0x0..01003] -> [0x00]      dove le ultime 3 sono zeri in quanto 
//                                      0x00_00_00_05 = 0x5 ---> 5)
//        ...            ...
//   memoria[0x0..01004] -> [0xca]      // altri byte di memoria... 
//   memoria[0x0..01005] -> [0xfe]      // altri byte di memoria...
//        ...            ...
//
//   memoria[0x0..02000] -> [0x00]  <-- int* pa = &a;
//   memoria[0x0..02001] -> [0x10]      (contiene 0x1000 diviso in byte)
//   memoria[0x0..02002] -> [0x00]      
//   memoria[0x0..02003] -> [0x00]      insieme formano: 0x00_00_00_00_00_00_10_00 
//   memoria[0x0..02004] -> [0x00]      
//   memoria[0x0..02005] -> [0x00]      pa "punta" alla cella 0x1000
//   memoria[0x0..02006] -> [0x00]
//   memoria[0x0..02007] -> [0x00]
//        ...            ...
//  Nota: usiamo 0..0 per indicare che gli zeri a sinistra:
//      0x0..01000 => 0x00_00_00_00_00_00_10_00
//      8 coppie di cifre esadecimali => 8 byte => 64 bit