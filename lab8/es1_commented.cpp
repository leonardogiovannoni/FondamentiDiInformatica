#include <iostream>
using namespace std;

struct Elem {
    int val;
    Elem *next;
};

// Nelle figure, indichiamo con un numero tra parentesi
// le posizioni nel codice a cui si riferiscono, quindi nel caso di
// ```
// int a = 20;
// // (1)
// a = a * 2
// ```
// stiamo indicando con (1) lo stato della memoria subito dopo
// `int a = 20;` e subito prima di `a = a * 2;`.

// Nella visualizzazione grafica qui sotto, facciamo finta che invece di avere un `int` (4 byte), abbiamo un `long` (8 byte),
// che quindi ha la stessa dimensione del puntatore `Elem*` (8 byte su sistemi a 64 bit), in maniera da rendere più semplice la
// visualizzazione, mantenendo la coerenza con le dimensioni reali in memoria. Utilizziamo linee più spesse per ricordarci al volo
// quali sono i puntatori che compongono logicamente la lista.
// Funzione per stampare una lista collegata (print)
//
// Esempio: stampa della lista [1, 3, 5]
// 
//        (1) Stato iniziale                          (2) Primo elemento (scan=0x1000)                 (3) Secondo elemento (scan=0x1010)               (4) Terzo elemento (scan=0x1020)                (5) Fine (scan=nullptr)
//                                                                                                                                                                                                                                       
//         phead                                       phead                                            phead                                            phead                                           phead
//          │                                           │                                                │                                                │                                               │
//          ↓                                           ↓                                                ↓                                                ↓                                               ↓
//        ┌───┬───┐  ┌───┬───┐  ┌───┬───┐             ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                  ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                  ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                 ┌───┬───┐  ┌───┬───┐  ┌───┬───┐
//        │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │             │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │                  │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │                  │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │                 │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │
//        └───┴───┘  └───┴───┘  └───┴───┘             └───┴───┘  └───┴───┘  └───┴───┘                  └───┴───┘  └───┴───┘  └───┴───┘                  └───┴───┘  └───┴───┘  └───┴───┘                 └───┴───┘  └───┴───┘  └───┴───┘
//                                                      ↑                                                           ↑                                                           ↑                                                            
//                                                     scan                                                        scan                                                        scan                                                       scan==nullptr
//                                                                                                                                                                                        
//
//        HEAP                                        HEAP                                             HEAP                                             HEAP                                            HEAP
//               ┌──────────────────────┐                    ┌──────────────────────┐<───────┐                ┌──────────────────────┐                         ┌──────────────────────┐                        ┌──────────────────────┐
//        0x1000 │  val    :      1     │<━━━━┓       0x1000 │  val    :      1     │<━━━━┓  │         0x1000 │  val    :      1     │<━━━━┓            0x1000 │  val    :      1     │<━━━━┓           0x1000 │  val    :      1     │<━━━━┓
//               ├──────────────────────┤     ┃              ├──────────────────────┤     ┃  │                ├──────────────────────┤     ┃                   ├──────────────────────┤     ┃                  ├──────────────────────┤     ┃
//        0x1008 │  next   :  0x1010    ┼━━┓  ┃       0x1008 │  next   :  0x1010    ┼━━┓  ┃  │         0x1008 │  next   :  0x1010    ┼━━┓  ┃            0x1008 │  next   :  0x1010    ┼━━┓  ┃           0x1008 │  next   :  0x1010    ┼━━┓  ┃
//               └──────────────────────┘  ┃  ┃              └──────────────────────┘  ┃  ┃  │                └──────────────────────┘  ┃  ┃                   └──────────────────────┘  ┃  ┃                  └──────────────────────┘  ┃  ┃
//               ┌──────────────────────┐  ┃  ┃              ┌──────────────────────┐  ┃  ┃  │                ┌──────────────────────┐<─╋──╋──┐                ┌──────────────────────┐  ┃  ┃                  ┌──────────────────────┐  ┃  ┃
//        0x1010 │  val    :      3     │<━┛  ┃       0x1010 │  val    :      3     │<━┛  ┃  │         0x1010 │  val    :      3     │<━┛  ┃  │         0x1010 │  val    :      3     │<━┛  ┃           0x1010 │  val    :      3     │<━┛  ┃
//               ├──────────────────────┤     ┃              ├──────────────────────┤     ┃  │                ├──────────────────────┤     ┃  │                ├──────────────────────┤     ┃                  ├──────────────────────┤     ┃
//        0x1018 │  next   :  0x1020    ┼━━┓  ┃       0x1018 │  next   :  0x1020    ┼━━┓  ┃  │         0x1018 │  next   :  0x1020    ┼━━┓  ┃  │         0x1018 │  next   :  0x1020    ┼━━┓  ┃           0x1018 │  next   :  0x1020    ┼━━┓  ┃
//               └──────────────────────┘  ┃  ┃              └──────────────────────┘  ┃  ┃  │                └──────────────────────┘  ┃  ┃  │                └──────────────────────┘  ┃  ┃                  └──────────────────────┘  ┃  ┃
//               ┌──────────────────────┐  ┃  ┃              ┌──────────────────────┐  ┃  ┃  │                ┌──────────────────────┐  ┃  ┃  │                ┌──────────────────────┐<━┛  ┃                  ┌──────────────────────┐  ┃  ┃
//        0x1020 │  val    :      5     │<━┛  ┃       0x1020 │  val    :      5     │<━┛  ┃  │         0x1020 │  val    :      5     │<━┛  ┃  │         0x1020 │  val    :      5     │<────╋──┐        0x1020 │  val    :      5     │<━┛  ┃
//               ├──────────────────────┤     ┃              ├──────────────────────┤     ┃  │                ├──────────────────────┤     ┃  │                ├──────────────────────┤     ┃  │               ├──────────────────────┤     ┃
//        0x1028 │  next   :  nullptr   │     ┃       0x1028 │  next   :  nullptr   │     ┃  │         0x1028 │  next   :  nullptr   │     ┃  │         0x1028 │  next   :  nullptr   │     ┃  │        0x1028 │  next   :  nullptr   │     ┃
//               └──────────────────────┘     ┃              └──────────────────────┘     ┃  │                └──────────────────────┘     ┃  │                └──────────────────────┘     ┃  │               └──────────────────────┘     ┃
//                                            ┃                                           ┃  │                                             ┃  │                                             ┃  │                                            ┃
//      STACK (frame di print)                ┃     STACK (frame di print)                ┃  │       STACK (frame di print)                ┃  │       STACK (frame di print)                ┃  │      STACK (frame di print)                ┃
//               ┌──────────────────────┐     ┃              ┌──────────────────────┐     ┃  │                ┌──────────────────────┐     ┃  │                ┌──────────────────────┐     ┃  │               ┌──────────────────────┐     ┃
//      0x7ffa50 │  phead  :   0x1000   ┼━━━━━┛     0x7ffa50 │  phead  :  0x1000    ┼━━━━━┛  │       0x7ffa50 │  phead  :  0x1000    ┼━━━━━┛  │       0x7ffa50 │  phead  :  0x1000    ┼━━━━━┛  │      0x7ffa50 │  phead  :  0x1000    ┼━━━━━┛
//               ├──────────────────────┤                    ├──────────────────────┤        │                ├──────────────────────┤        │                ├──────────────────────┤        │               ├──────────────────────┤
//      0x7ffa58 │ (scan)  :    ...     │           0x7ffa58 │  scan   :  0x1000    ┼────────┘       0x7ffa58 │  scan   :  0x1010    ┼────────┘       0x7ffa58 │  scan   :  0x1020    ┼────────┘      0x7ffa58 │  scan   :  nullptr   │
//               └──────────────────────┘                    └──────────────────────┘                         └──────────────────────┘                         └──────────────────────┘                        └──────────────────────┘
//                                                                                                                                                                                     
//               Output: [                                       Output: [1,                                        Output: [1, 3,                                 Output: [1, 3, 5                              Output: [1, 3, 5]                                              
//                                                         
//     

void print(Elem *phead) {
    cout << "[";
    // (1)
    for (Elem *scan = phead; scan != nullptr; scan = scan->next) {
        cout << scan->val;
        bool is_last = (scan->next == nullptr);
        if (!is_last) {
            cout << ", ";
        }
        // (2), (3), (4)
    }
    cout << "]" << endl;
    // (5)
}

// Funzione per inserire un elemento in testa alla lista (push_front)
//
//                                                    Elem *new_elem = new Elem;                     *pphead = new_elem;
//                                                    new_elem->val = n;                  
//                                                    new_elem->next = *pphead;                                              
//
//
//        (1) Stato iniziale                          (2) Crea e collega elemento                    (3) Aggiorna *pphead, ovvero `phead` nel chiamante
//
//                                                                                                  new_elem    
//         phead                                     new_elem     phead                               phead
//          │                                           │          │                                   │
//          ↓                                           ↓          ↓                                   ↓
//        ┌───┬───┐  ┌───┬───┐                        ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                ┌───┬───┐  ┌───┬───┐  ┌───┬───┐
//        │ 3 │ ●─┼─>│ 5 │ 0 │                        │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │                │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ 0 │
//        └───┴───┘  └───┴───┘                        └───┴───┘  └───┴───┘  └───┴───┘                └───┴───┘  └───┴───┘  └───┴───┘
//
//
//                                                                                                        
//                                                    HEAP                                           HEAP                      
//                                                           ┌──────────────────────┐                       ┌──────────────────────┐<━━━━━━┓
//                                                    0x1000 │  val    :      1     │<───────┐       0x1000 │  val    :      1     │<────┐ ┃   
//                                                           ├──────────────────────┤        │              ├──────────────────────┤     │ ┃
//                                                    0x1008 │  next   :  0x1010    ┼──┐     │       0x1008 │  next   :  0x1010    ┼━━┓  │ ┃
//        HEAP                                               └──────────────────────┘  │     │              └──────────────────────┘  ┃  │ ┃
//               ┌──────────────────────┐                    ┌──────────────────────┐<─┘     │              ┌──────────────────────┐  ┃  │ ┃
//        0x1010 │  val    :      3     │<━━━━┓       0x1010 │  val    :      3     │<━━━━━┓ │       0x1010 │  val    :      3     │<━┛  │ ┃
//               ├──────────────────────┤     ┃              ├──────────────────────┤      ┃ │              ├──────────────────────┤     │ ┃
//        0x1018 │  next   :  0x1020    ┼━━┓  ┃       0x1018 │  next   :  0x1020    ┼━━┓   ┃ │       0x1018 │  next   :  0x1020    ┼━━┓  │ ┃
//               └──────────────────────┘  ┃  ┃              └──────────────────────┘  ┃   ┃ │              └──────────────────────┘  ┃  │ ┃
//               ┌──────────────────────┐  ┃  ┃              ┌──────────────────────┐  ┃   ┃ │              ┌──────────────────────┐  ┃  │ ┃
//        0x1020 │  val    :      5     │<━┛  ┃       0x1020 │  val    :      5     │<━┛   ┃ │       0x1020 │  val    :      5     │<━┛  │ ┃
//               ├──────────────────────┤     ┃              ├──────────────────────┤      ┃ │              ├──────────────────────┤     │ ┃
//        0x1028 │  next   :     0x0    │     ┃       0x1028 │  next   :     0x0    │      ┃ │       0x1028 │  next   :     0x0    │     │ ┃
//               └──────────────────────┘     ┃              └──────────────────────┘      ┃ │              └──────────────────────┘     │ ┃
//                                            ┃                                            ┃ │                                           │ ┃
//      STACK (frame di push_front)           ┃     STACK (frame di push_front)            ┃ │     STACK (frame di push_front)           │ ┃
//               ┌──────────────────────┐     ┃              ┌──────────────────────┐      ┃ │              ┌──────────────────────┐     │ ┃
//      0x7ffa50 │  n      :      1     │     ┃     0x7ffa50 │  n      :      1     │      ┃ │     0x7ffa50 │  n      :      1     │     │ ┃
//               ├──────────────────────┤     ┃              ├──────────────────────┤      ┃ │              ├──────────────────────┤     │ ┃
//      0x7ffa58 │  pphead  :  0x7ffc40 ┼──┐  ┃     0x7ffa58 │  pphead  :  0x7ffc40 ┼──┐   ┃ │     0x7ffa58 │  pphead  :  0x7ffc40 ┼──┐  │ ┃
//               ├──────────────────────┤  │  ┃              ├──────────────────────┤  │   ┃ │              ├──────────────────────┤  │  │ ┃
//      0x7ffa60 │  (new_elem)  : ...   │  │  ┃     0x7ffa60 │  new_elem  : 0x1000  ┼──│───╋─┘     0x7ffa60 │  new_elem  : 0x1000  ┼──│──┘ ┃
//               └──────────────────────┘  │  ┃              └──────────────────────┘  │   ┃                └──────────────────────┘  │    ┃
//                                         │  ┃                                        │   ┃                                          │    ┃
//      STACK (frame di main)              │  ┃     STACK (frame di main)              │   ┃       STACK (frame di main)              │    ┃
//               ┌──────────────────────┐<─┘  ┃              ┌──────────────────────┐<─┘   ┃                ┌──────────────────────┐<─┘    ┃
//      0x7ffc40 │  phead   :  0x1010   ┼━━━━━┛     0x7ffc40 │  phead   :  0x1010   ┼━━━━━━┛       0x7ffc40 │  phead   :  0x1000   ┼━━━━━━━┛
//               └──────────────────────┘                    └──────────────────────┘                       └──────────────────────┘
//                                                  
// In figura, gli indirizzi di memoria (es. `0x1000`, `0x1010`, ecc.) sono
// puramente esemplificativi e servono solo a illustrare i collegamenti
// tra i vari elementi della lista, non rappresentano indirizzi "reali".
// L'unica cosa reale è l'ordine degli stack frame (il main, come chiamante, ha uno stack frame a indirizzi più alti
// rispetto a quello di push_front, che è il chiamato), il fatto che l'heap ha indirizzi più bassi (numericamente) rispetto allo stack,
// e che lo stack cresce verso indirizzi più bassi, mentre l'heap cresce verso indirizzi più alti (ma può riutilizzare spazi liberati, 
// nell'esempio infatti l'indirizzo allocato per ultimo, 0x1000, è più basso, che comunque abbiamo scelto solo per una questione grafica).
// In (**) riportiamo per completezza la struttura logica della memoria.

// Perché il parametro è un *puntatore a puntatore* (`Elem **phead`) e non un
// semplice puntatore (`Elem *phead`)?
//
// In C++ sappiamo che, per modificare un valore e propagare la modifica
// all'esterno della funzione, possiamo usare sia puntatori sia riferimenti.
//
// Un parametro `Elem *phead` è sufficiente se vogliamo solo modificare
// *l'oggetto puntato* (cioè la struct `Elem`: i campi `val`, `next`, ecc.).
// In quel caso, ci basta dereferenziare `phead` e non serve un puntatore
// al puntatore: lavoriamo direttamente sulla struct.
//
// Con un parametro `Elem **phead`, invece, stiamo dicendo che la funzione
// può modificare *il puntatore Elem* stesso* che esiste nel chiamante (per esempio
// in `main`). Non solo quindi il contenuto della struct puntata, ma proprio
// il valore di `phead` (cioè l’indirizzo a cui punta).
//
// Se avessimo solo `Elem *phead`, dentro `push_front` lavoreremmo su una
// *copia del puntatore*: potremmo modificare la struct puntata da `phead`,
// perfino sovrascriverla con qualcosa tipo
// ```
//     *phead = Elem{ .val = 20, .next = nullptr };
// ```
// ma non potremmo cambiare il puntatore `phead` del chiamante.
//
// Usare `Elem **pphead` ci permette invece di far puntare `phead` (del chiamante) a un nuovo
// elemento (come avviene in questa `push_front`, dove `pphead` viene aggiornato
// per puntare al nodo appena inserito in testa). In questo modo, la modifica
// al puntatore è visibile anche in `main`.

// Come discusso in fondo (vedere (*) per i dettagli che dovrebbero essere già noti),
// un riferimento altro non è che un puntatore implicito con casi d'uso più limitati.
// Per conformità a quanto visto a lezione, utilizzeremo dalle prossime funzioni
// un riferimento a puntatore (`Elem *&rphead`) invece di un puntatore a puntatore (`Elem **pphead`),
// tenendo a mente che per il compilatore è la stessa cosa. 

void push_front(Elem **pphead, int n) {
    // (1)
    Elem *new_elem = new Elem;
    new_elem->val = n;
    new_elem->next = *pphead;
    // (2)
    *pphead = new_elem;
    // (3)
}

int main() {
    Elem *phead = nullptr;
    cout << "Inserisci una sequenza di numeri interi positivi:" << endl;
    int n = 0;
    while (cin >> n) {
        push_front(&phead, n);
    }

    print(phead);

    return 0;
}







// (*)
// Con `(A)` e `(B)` indichiamo 
// le posizioni nel `main`, per mostrare l'effetto delle
// chiamate alle funzioni una volta ritornate.




//      (1) Stato iniziale                                          (2) Assegnamento tmp = *x
//                                                     
//      STACK (frame di f1)                                         STACK (frame di f1)           
//               ┌──────────────────────┐                                    ┌──────────────────────┐
//      0x7ffa50 │  x      :  0x7ffc40  ┼──┐                        0x7ffa50 │  x      :  0x7ffc40  ┼──┐
//               ├──────────────────────┤  │                                 ├──────────────────────┤  │
//      0x7ffa58 │  (tmp)  :    ...     │  │                        0x7ffa58 │  tmp    :     40     │  │
//               └──────────────────────┘  │                                 └──────────────────────┘  │
//                                         │                                                           │
//      STACK (frame di main)              │                         STACK (frame di main)             │
//               ┌──────────────────────┐  │                                 ┌──────────────────────┐  │ 
//      0x7ffc40 │  a      :     20     │<─┘                        0x7ffc40 │  a      :     20     │<─┘
//               └──────────────────────┘                                    └──────────────────────┘
//
//
//      (3) Assegnamento *x = tmp                                   (A) Dopo return
//                                                     
//      STACK (frame di f1)                                                    
//               ┌──────────────────────┐                                    
//      0x7ffa50 │  x      :  0x7ffc40  ┼──┐                      
//               ├──────────────────────┤  │                                 
//      0x7ffa58 │  tmp    :     40     │  │
//               └──────────────────────┘  │
//                                         │
//      STACK (frame di main)              │                        STACK (frame di main) 
//               ┌──────────────────────┐  │                                 ┌──────────────────────┐
//      0x7ffc40 │  a      :     40     │<─┘                        0x7ffc40 │  a      :     40     │
//               └──────────────────────┘                                    └──────────────────────┘


// passo il valore dell'indirizzo della variabile `a`,
// con lo stesso tipo della variabile `a` (int),
// per cui dereferenziare `x`, equivale a leggere
// un int all'indirizzo in memoria della variabile `a`,
// ovvero proprio a leggere il valore di `a`.
// ```
// void f1(int *x) {
//     // (1)
//     int tmp = *x * 2;
//     // (2)
//     // in questo caso sto andato a scrivere (tramite la sintassi *x = ..)
//     // all'indirizzo della variabile `a` un intero, ovvero sto andando a
//     // sovrascrivere `a`
//     *x = tmp;
//     // (3)
// }
// ```


// Indichiamo informalmente con `ref` il fatto che
// una variabile è un riferimento a un'altra variabile.

//      (1) Stato iniziale                                          (2) Assegnamento tmp = x
//                                            
//      STACK (frame di f2)                                         STACK (frame di f2)           
//               ┌──────────────────────┐                                    ┌──────────────────────┐
//      0x7ffa50 │  x      :  0x7ffc40  ┼──┐                        0x7ffa50 │  x      :  0x7ffc40  ┼──┐
//               ├──────────────────────┤  │                                 ├──────────────────────┤  │
//      0x7ffa58 │  (tmp)  :    ...     │  │                        0x7ffa58 │  tmp    :     80     │  │
//               └──────────────────────┘  │                                 └──────────────────────┘  │
//                                         │                                                           │
//      STACK (frame di main)              │                        STACK (frame di main)              │
//               ┌──────────────────────┐  │                                 ┌──────────────────────┐  │
//      0x7ffc40 │  a      :     40     │<─┘                        0x7ffc40 │  a      :     80     │<─┘
//               └──────────────────────┘                                    └──────────────────────┘
//
//
//      (3) Assegnamento x = tmp                                    (B) Dopo return
//                                                     
//      STACK (frame di f2)                                     
//               ┌──────────────────────┐                        
//      0x7ffa50 │  x      :  0x7ffc40  ┼──┐                       
//               ├──────────────────────┤  │        
//      0x7ffa58 │  tmp    :     80     │  │                                                                      
//               └──────────────────────┘  │                                                                                      
//                                         │                                                                         
//      STACK (frame di main)              │                        STACK (frame di main)                                
//               ┌──────────────────────┐  │                                 ┌──────────────────────┐                                            
//      0x7ffc40 │  a      :     80     │<─┘                        0x7ffc40 │  a      :     80     │   
//               └──────────────────────┘                                    └──────────────────────┘



// Codice equivalente a quello di sopra.
// Purtroppo, per i riferimenti è stato scelto di utilizzare lo stesso simbolo
// dell'operatore address-of, ovvero la `&`: i due operatori non hanno nulla a che fare l'uno
// con l'altro e non vanno confusi, esattamente come non si confonderebbero quando si fa l'operazione di
// `and` bit a bit. Nel caso del riferimento, la `&` è parte del nome del tipo, quindi il tipo
// di `x` è proprio `int&`, mentre nello use case del puntatore, la `&` è un operatore (noto come operatore address-of)
// che opera sulle variabili, ovvero è una funzione che data una variabile in input restituisce il suo indirizzo in memoria in output
// (nel caso di `int`, in input darò un `int` e in output riceverò un `int*`).
// Il riferimento è, secondo lo standard del C++, un alias a una variabile
// ovvero un altro nome per la variabile. In questo caso, questo significa
// che `x` è "un altro nome" per `a`, volendo dare una visione generica e poco chiara,
// che lo standard usa per essere il più generale possibile.
// Detto questo, in qualsiasi compilatore, un riferimento è una sintassi (opinabilmente) più carina
// per nascondere un puntatore. Possiamo quindi vederlo come zucchero sintattico rispetto al codice di sopra
// (sia lato del chiamato, dove non devo utilizzare gli asterischi, che lato chiamante,
// dove non devo usare la `&` per ottenere l'indirizzo della variabile)
// In particolare, valgono gli stessi ragionamenti fatti prima:
// qui il compilatore passa alla funzione esattamente come nel caso di prima l'indirizzo di `a`,
// e per vederlo, posso fare..

// ```
// void f2(int &x) {
//     // ..una stampa del genere
//     // ```
//     // cout << &x << endl;
//     // ```
//     // (1)
//     // (* qui invece il compilatore fa una lettura di un int all'indirizzo di `a`
//     int tmp = x * 2;
//     // *)
//     // (2)
//     // (* qui invece il compilatore fa una scrittura di un int all'indirizzo di `a`
//     x = tmp; // "leggi il valore di `tmp` e scrivilo all'indirizzo di `x`, che è lo stesso indirizzo di `a`"
//     // *)
//     // (3)
// }
// ```

// quindi, il riferimento può essere visto come un `puntatore implicito`, in quanto il compilatore
// genererà lo stesso codice (codice macchina) per f1 e per f2, mascherando anche lato chiamante
// l'operazione di `&` (address-of). Ciò rende tutto trasparente al programmatore, che non si deve
// preoccupare né di ottendere l'indirizzo della variabili lato chiamante `&`, né di dereferenziare
// il puntatore lato del chiamato.
//
// Gli use case del riferimento sono strettamente contenuti dentro gli use case del puntatore,
// cioè con il puntatore è possibile fare le stesse cose rispetto al riferimento e anche di più.
// I puntatori supportando il `rebinding`, che altro non è che il riassegnamento
// *della variabile puntatore* (quindi, non del *valore puntato dalla variabile puntatore*),
// ovvero:
// ```
// int a = 10;
// int b = 20;
// int *x = &a;
// cout << *x << endl; // 10
// x = &b;
// cout << *x << endl; // 20
// ```
// Questo non può essere fatto con i riferimenti: una volta fatto il binding a una variabile (tipo `a`), non
// può cambiare e "puntare" ad altre variabili
//
// Come convenzione, il riferimento verrà utilizzato *sempre* per riferirsi a una sola variabile,
// mentre il puntatore (purtroppo) viene utilizzato anche per riferirsi a locazioni contigue rispetto
// a quella variabile (quindi, utilizzato per passare parametri di tipo array, fatti decadere a puntatore).
// Questo significa che quando vedo un puntatore (per esempio, int *), potrebbe riferirsi a più locazioni di memoria:
// in questi casi, la cosa più pulita è scrivere in un commento a cosa è adibita la variabile puntatore.

// Come ultima nota, posso passare da un puntatore a un riferimento in maniera molto semplice
// supponiamo di riferire una singola variabile con un puntatore int *
// ```
// int a = 10;
// int *p = &a;
// ```
// Posso passare ad avere un riferimento in questo maniera
// ```
// int &r = *p;
// ```
// in questo caso varrà la seguente, banale, proprietà
// ```
// &r == p; // dove con `&` si sta ovviamente indicando l'operatore "address-of"
// ```
//
// mentre se voglio passare alla notazione a puntatore, basta che faccia questo:
// ```
// int *p2 = &r;
// ```
//
// Come ultima nota, il puntatore può essere nullo (ovvero, valere NULL), e in generale
// può contenere un valore *non valido* di memoria *a patto* che non venga dereferenziato.
// il riferimento invece *deve* sempre riferirsi a un oggetto valido, ne segue che non può
// mai riferirsi a NULL.
//
// ```
// int *a = NULL; // OK
// int &b = *a; // NO: BUG
// ```
// in particolare nel caso di binding del riferimento a un oggetto non valido il comportamento non è definito
// (cioè, il programma ha un bug e qualsiasi output pensabile può, in teoria, verificarsi)

// ```
// int main() {
//     int a = 0;
//     cout << "Inserisci un numero intero: ";
//     cin >> a;
// 
//     cout << "\nValore iniziale: " << a << endl;
// 
//     f1(&a); // Passaggio per puntatore
//     // (A)
//     cout << "Dopo f1(&x): " << a << endl;
// 
//     f2(a); // Passaggio per riferimento
//     // (B)
//     cout << "Dopo f2(x): " << a << endl;
// 
//     return 0;
// }
// ```


// (**)
//       ↑
// Indirizzi bassi
// ┌───────────┐
// │           │
// |           │    
// |           │    
// ├───────────┤    
// │███████████│  CODE (Istruzioni del programma, dimensione fissa una volta caricato il programma)
// │██ CODE ███│  
// │███████████│
// ├───────────┤    
// │▓▓▓▓▓▓▓▓▓▓▓│  DATA (Variabili globali/statiche, dimensione fissa una volta caricato il programma)
// │▓▓ DATA ▓▓▓│  
// │▓▓▓▓▓▓▓▓▓▓▓│
// ├───────────┤    
// │░░░░░░░░░░░│  HEAP
// │░░ HEAP ░░░│  ↓ cresce verso il basso (verso indirizzo più alti numericamente)
// │░░░░░↓░░░░░│  ↓
// │░░░░░↓░░░░░│
// │░░░░░░░░░░░│    
// │     .     │
// │     .     │
// │     .     │
// │▒▒▒▒▒▒▒▒▒▒▒│    
// │▒▒▒▒▒↑▒▒▒▒▒│  
// │▒▒▒▒▒↑▒▒▒▒▒│  ↑ 
// │▒▒ STACK ▒▒│  ↑ cresce verso l'alto (verso indirizzo più bassi numericamente)
// │▒▒▒▒▒▒▒▒▒▒▒│  STACK
// ├───────────┤    
// │           │
// │           │    
// │           │
// └───────────┘
// Indirizzi alti 
//       ↓


