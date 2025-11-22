#include <cstring>
#include <iostream>
using namespace std;

// Safety: `dst` deve avere una capacità >= alla capacità minima della stringa
// contenuta in `src`
char *my_strcpy(char dst[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

bool is_alpha_maiusc_or_numeric(const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        // Sfruttiamo una proprietà garantita dal C++: le lettere 'A'..'Z' e le cifre '0'..'9'
        // hanno valori interi consecutivi. Possiamo quindi verificare se `c` è una maiuscola
        // controllando che sia tra 'A' e 'Z' (e analogamente per le cifre).
        //
        // Se non potessimo fare questa assunzione, ad esempio con alfabeti diversi o con
        // insiemi di caratteri non ordinati, dovremmo controllare esplicitamente:
        // ```
        // const char MAIUSC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // bool is_maiusc = false;
        // for (int j = 0; MAIUSC[j] != '\0'; j++) {
        //     if (c == MAIUSC[j]) { 
        //         is_maiusc = true;
        //         break; 
        //     }
        // }
        // ```
        bool is_maiusc = (c >= 'A' && c <= 'Z');
        bool is_digit  = (c >= '0' && c <= '9');
        bool is_valid  = (is_maiusc || is_digit);
        if (!is_valid) {
            return false;
        }
    }
    return true;
}

int main() {
    // Definiamo due grandezze, strettamente collegate, che caratterizzano l'array che
    // conterrà i nostri caratteri:
    //  -) chiamiamo _lunghezza massima_ il numero massimo di caratteri che un array
    //     può contenere per rappresentare una cstring, escludendo il terminatore
    //     '\0'
    //  -) chiamiamo _capacità_ la dimensione di questo array.
    //
    // Banalmente: _lunghezza massima_ + 1 == _capacità_
    //
    //  Array di caratteri per contenere una stringa C-style:
    //
    //  str1[CAPACITY] = str1[51]
    //  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    //  │ 'a' │ 'b' │ 'c' │ 'd' │ 'e' │ ... │     │'\0' │
    //  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
    //    [0]   [1]   [2]   [3]   [4]   ...   [49]  [50]
    //     │                                   │
    //     │        MAX_LENGTH = 50            │
    //     └───────────────────────────────────┘
    //     |                                         │
    //     │        CAPACITY = 51                    │
    //     └─────────────────────────────────────────┘
    //

    // Analogamente, quando parleremo della stringa (e non dell'array che la
    // contiene), parleremo di _lunghezza_ della stringa per riferirci al numero di
    // caratteri, escluso il terminatore '\0', presenti nella stringa, mentre
    // parleremo di _capacità minima_ per indicare il minimo numero di byte
    // necessari a contenere la stringa insieme al terminatore.
    // Banalmente: _lunghezza_ + 1 = _capacità minima_
    // La capacità minima è la dimensione minima per un array necessaria a
    // memorizzare una cstring

    // Supponiamo di avere la stringa "Hello",
    //
    //  str1[CAPACITY] = str1[51]
    //  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    //  │ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │'\0' │ ... │ ... │
    //  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
    //    [0]   [1]   [2]   [3]   [4]   [5]   [..]  [..]
    //     │                       │
    //     │      LENGTH = 5       │
    //     └───────────────────────┘
    //     |                             │
    //     │      MIN_CAPACITY = 6       │
    //     └─────────────────────────────┘
    //
    const int MAX_LEN = 50;
    const int CAPACITY = MAX_LEN + 1;

    char str1[CAPACITY] = {};
    char str2[CAPACITY] = {};

    // Fare
    // ```
    // char array[CAPACITY] = {};
    // cin >> array;
    // ```
    // è meno banale di quello che sembra: noi sappiamo che purtroppo in C++ il tipo
    // array non è first-class citizen e può decadere a puntatore al primo elemento
    // quando passato a una funzione. Questo significa che perdiamo l'informazione
    // sulla capacità dell'array, ovvero `cin` legge una quantità indefinita di
    // caratteri e li scrive nell'array senza preoccuparsi di superare la capacità
    // dell'array. Questo overloading di `cin` è INTRINSECAMENTE DIFETTOSO e non
    // dovrebbe MAI essere usato in codice, perché non c'è nessun modo di impedire
    // che l'utente inserisca più caratteri di quanti l'array possa contenerne,
    // causando un buffer overflow e potenzialmente corrompendo la memoria. (*)

    cin >> str1;

    cout << "str1: " << str1 << endl;

    cout << "str2 PRIMA: " << str2 << endl;
    // A noi piacerebbe fare così:
    // str2 = str1; // ERRORE!
    // Ma sappiamo che gli array, e in particolare le stringhe, in C++ non sono
    // first-class citizen, quindi dobbiamo copiare i caratteri uno ad uno o usare
    // una funzione della libreria standard per farlo. Invece di fare quindi
    // `str2 = str1;`, faremo `strcpy(str2, str1);`, dove per ricordare l'ordine
    // degli argomenti possiamo pensare allo stesso ordine dell'assegnazione:
    // `destinazione = sorgente;`
    my_strcpy(str2, str1);

    cout << "str2 DOPO: " << str2 << endl;

    if (is_alpha_maiusc_or_numeric(str1)) {
        cout << "OK" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

// Come si vede chiaramente dall'implementazione, non viene fatto nessun controllo
// sulla capacità dell'array di destinazione `dst`, quindi è responsabilità del
// chiamante assicurarsi che `dst` abbia spazio sufficiente per contenere la stringa
// copiata da `src` più il terminatore di stringa `\0`. Abbiamo detto precedentemente
// che qualsiasi array passato a una funzione viene trattato come un puntatore al
// primo elemento dell'array, e che dovremmo passare anche la lunghezza dell'array
// come argomento alla funzione. Tuttavia, per le stringhe in C-style, esiste una
// convenzione diversa: le stringhe sono terminate da un carattere speciale chiamato
// "null terminator", rappresentato come '\0' (un carattere con valore ASCII 0). È
// stata una decisione che oggi risulta terribile, ma che all'epoca era pensata per
// risparmiare memoria. Questo porta a una quantità di problemi notevoli, e non
// semplifica praticamente nulla, anzi complica le cose.
// -) Problema 1: non possiamo sapere la lunghezza di una stringa semplicemente
//                guardando il puntatore;
// -) Problema 2: dobbiamo usare un carattere tra i 256 disponibili per
//                rappresentare il terminatore di stringa e quindi non possiamo
//                usarlo all'interno della stringa stessa (valore sentinella).
// -) Problema 3: off-by-one errors: dobbiamo sempre ricordarci di allocare spazio
//                per il terminatore di stringa quando dichiariamo un array di
//                caratteri che conterrà una stringa, e dobbiamo sempre ricordarci
//                di copiare anche il terminatore di stringa quando copiamo una
//                stringa in un'altra.
// -) Problema 4: a me piacerebbe trattare buffer binari (array di byte, che posso
//                sempre rappresentare come char buffer[]) nello stesso modo in cui
//                tratto le stringhe, ma i buffer binari possono contenere qualsiasi
//                valore byte, incluso il byte 0. Questo significa che dovrò
//                utilizzare funzioni diverse per trattare i buffer binari e le
//                stringhe, anche se in realtà sono entrambi array di char.
// Il motivo per cui utilizziamo ancora le stringhe in C-style è per motivi legacy e
// di interoperabilità con codice C esistente, se il C++ venisse inventato oggi, non
// avrebbe mai adottato questo modello per le stringhe, useremmo il modello puntatore
// al primo elemento e lunghezza come intero, che è superiore quasi sotto qualsiasi
// punto di vista alla soluzione puntatore al primo elemento e terminatore di stringa.





// (*) APPROFONDIMENTO:
// Da https://en.cppreference.com/w/cpp/io/basic_istream/operator_gtgt2.html
// ```
// template <class Traits>
// basic_istream<char, Traits>&
//     operator>>( basic_istream<char, Traits>& st, char* s );  (until C++20)
//
// template< class Traits, std::size_t N >
// basic_istream<char, Traits>&
//     operator>>( basic_istream<char, Traits>& st, char (&s)[N] );  (since C++20)
// ```
//
// Riportiamo qui alcuni overloading di `operator>>` per `basic_istream` (la classe
// template da cui deriva `std::cin`), che mostrano come nella versione C++20 `cin`
// non abbia più l'overloading difettoso che accetta un puntatore a char (`char* s`),
// ma esista solo l'overloading che accetta un array di char di
// dimensione N (`char (&s)[N]`): noi non abbiamo visto questa sintassi per passare
// un array per riferimento, ma è un trucco per evitare il decadimento dell'array a
// puntatore e preservare l'informazione sulla dimensione dell'array, che è
// recuperata attraverso il template parameter N, detto questo, i template sono una
// funzionalità avanzata che non abbiamo visto e non vedremo in questo corso, quindi
// per noi questa sintassi non esiste. In ogni caso, in C++20 questo:
// ```
// char str[51];
// char *s = &str[0];
// cin >> s;
// ```
// Non compila più, perché `s` è un `char*` e non un `char[51]`, mentre questo:
// ```
// char str[51];
// cin >> str;
// ```
// compila ancora, perché `str` è un `char[51]` e non è un errore passarlo a `cin`,
// detto questo, noi assumeremo lo stesso comportamento di C++17 e inferiori, e
// quindi per noi i due esempi di sopra compilano entrambi, sono equivalenti e sono
// anche difettosi come detto sopra.