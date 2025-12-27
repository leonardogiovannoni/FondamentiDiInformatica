#include <iostream>
using namespace std;

struct Elem {
    int val;
    Elem *next;
};

void print(Elem *phead) {
    cout << "[";
    
    for (Elem *scan = phead; scan != nullptr; scan = scan->next) {
        cout << scan->val;
        bool is_last = (scan->next == nullptr);
        if (!is_last)
            cout << ", ";
    }
    
    cout << "]" << endl;
}


// Funzione per inserire un elemento mantenendo l'ordine crescente (insert_ordered)
//
// Esempio: inserimento di val=3 in una lista ordinata [1, 5, 7]
//
//                                                                            Elem *new_elem = new Elem;                                                     Elem *scan = rphead;                                                         prev = scan;                                                                   new_elem->next = scan;                                              
//                                                                            new_elem->val = n;                                                             Elem *prev = nullptr;                                                        scan = scan->next;                                                             prev->next = new_elem;                              
//                                                                            new_elem->next = nullptr;                                                
//  (1) Stato iniziale                                                        (2) Crea nuovo elemento                                                        (3) Inizializza `scan` e `prev`                                              (4) Cerca posizione                                                            (5) Inserisce tra prev e scan
//                                                                                                                                                                                                                                                                                                                                                             
//   phead                                                                     phead                                                                          phead                                                                        phead                                                                          phead
//    │                                                                         │                                                                              │                                                                            │                                                                              │
//    ↓                                                                         ↓                                                                              ↓                                                                            ↓                                                                              ↓
//  ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                                           ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                                               ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                                               ┌───┬───┐  ┌───┬───┐  ┌───┬───┐                                                ┌───┬───┐  ┌───┬───┐  ┌───┬───┐  ┌───┬───┐
//  │ 1 │ ●─┼─>│ 5 │ ●─┼─>│ 7 │ 0 │                                           │ 1 │ ●─┼─>│ 5 │ ●─┼─>│ 7 │ 0 │                                               │ 1 │ ●─┼─>│ 5 │ ●─┼─>│ 7 │ 0 │                                               │ 1 │ ●─┼─>│ 5 │ ●─┼─>│ 7 │ 0 │                                                │ 1 │ ●─┼─>│ 3 │ ●─┼─>│ 5 │ ●─┼─>│ 7 │ 0 │
//  └───┴───┘  └───┴───┘  └───┴───┘                                           └───┴───┘  └───┴───┘  └───┴───┘                                    0          └───┴───┘  └───┴───┘  └───┴───┘                                               └───┴───┘  └───┴───┘  └───┴───┘                                                └───┴───┘  └───┴───┘  └───┴───┘  └───┴───┘
//                                                                                                                                               ↑            ↑                                                                             ↑          ↑                                                                   ↑          ↑          ↑
//                                                                                                                                             prev         scan                                                                          prev       scan                                                                prev    new_elem      scan
//                                                                                                                                                                                                                                                                                                                                                                                                           
//     HEAP                                                                   HEAP                                                                           HEAP                                                                          HEAP                                                                           HEAP
//                                                                       ┌───────────┐  ┌──────────────────────┐                                        ┌───────────┐  ┌──────────────────────┐                                       ┌───────────┐  ┌──────────────────────┐                                        ┌───────────┐  ┌──────────────────────┐
//                                                                       │    0x0FF0 └─>│  val    :      3     │                                        │    0x0FF0 └─>│  val    :      3     │                                       │    0x0FF0 └─>│  val    :      3     │                                        │    0x0FF0 └─>│  val    :      3     │<━━━━━━┓
//                                                                       │              ├──────────────────────┤                                        │              ├──────────────────────┤                                       │              ├──────────────────────┤                                        │              ├──────────────────────┤       ┃
//                                                                       │    0x0FF8    │  next   :  nullptr   │                                        │    0x0FF8    │  next   :  nullptr   │                                       │    0x0FF8    │  next   :  nullptr   │                                        │    0x0FF8    │  next   :  0x1010    ┼━━┓    ┃
//                                                                       │              └──────────────────────┘                                        │              └──────────────────────┘                                       │              └──────────────────────┘                                        │              └──────────────────────┘  ┃    ┃         
//               ┌──────────────────────┐                                │              ┌──────────────────────┐                                     ┌──│───────────┐  ┌──────────────────────┐                                 ┌─────│───────────┐  ┌──────────────────────┐                                  ┌─────│───────────┐  ┌──────────────────────┐  ┃    ┃ 
//     0x1000    │  val    :      1     │<━━━━━━━━━┓                     │    0x1000    │  val    :      1     │<━━━━━━━━━┓                          │  │    0x1000 └─>│  val    :      1     │<━━━━━━━━━┓                      │     │    0x1000 └─>│  val    :      1     │<━━━━━━━━━┓                       │     │    0x1000 └─>│  val    :      1     │<━┃━━━━┃━━┓   
//               ├──────────────────────┤          ┃                     │              ├──────────────────────┤          ┃                          │  │              ├──────────────────────┤          ┃                      │     │              ├──────────────────────┤          ┃                       │     │              ├──────────────────────┤  ┃    ┃  ┃         
//     0x1008    │  next   :  0x1010    ┼━━┓       ┃                     │    0x1008    │  next   :  0x1010    ┼━━┓       ┃                          │  │    0x1008    │  next   :  0x1010    ┼━━┓       ┃                      │     │    0x1008    │  next   :  0x1010    ┼━━┓       ┃                       │     │    0x1008    │  next   :  0x0FF0    ┼━━┃━━━━┛  ┃                      
//               └──────────────────────┘  ┃       ┃                     │              └──────────────────────┘  ┃       ┃                          │  │              └──────────────────────┘  ┃       ┃                      │     │              └──────────────────────┘  ┃       ┃                       │     │              └──────────────────────┘  ┃       ┃                  
//               ┌──────────────────────┐  ┃       ┃                     │              ┌──────────────────────┐  ┃       ┃                          │  │              ┌──────────────────────┐  ┃       ┃                      │  ┌──│───────────┐  ┌──────────────────────┐  ┃       ┃                       │  ┌──│───────────┐  ┌──────────────────────┐  ┃       ┃             
//     0x1010    │  val    :      5     │<━┛       ┃                     │    0x1010    │  val    :      5     │<━┛       ┃                          │  │    0x1010    │  val    :      5     │<━┛       ┃                      │  │  │    0x1010 └─>│  val    :      5     │<━┛       ┃                       │  │  │    0x1010 └─>│  val    :      5     │<━┛       ┃           
//               ├──────────────────────┤          ┃                     │              ├──────────────────────┤          ┃                          │  │              ├──────────────────────┤          ┃                      │  │  │              ├──────────────────────┤          ┃                       │  │  │              ├──────────────────────┤          ┃                  
//     0x1018    │  next   :  0x1020    ┼━━┓       ┃                     │    0x1018    │  next   :  0x1020    ┼━━┓       ┃                          │  │    0x1018    │  next   :  0x1020    ┼━━┓       ┃                      │  │  │    0x1018    │  next   :  0x1020    ┼━━┓       ┃                       │  │  │    0x1018    │  next   :  0x1020    ┼━━┓       ┃           
//               └──────────────────────┘  ┃       ┃                     │              └──────────────────────┘  ┃       ┃                          │  │              └──────────────────────┘  ┃       ┃                      │  │  │              └──────────────────────┘  ┃       ┃                       │  │  │              └──────────────────────┘  ┃       ┃              
//               ┌──────────────────────┐  ┃       ┃                     │              ┌──────────────────────┐  ┃       ┃                          │  │              ┌──────────────────────┐  ┃       ┃                      │  │  │              ┌──────────────────────┐  ┃       ┃                       │  │  │              ┌──────────────────────┐  ┃       ┃                          
//     0x1020    │  val    :      7     │<━┛       ┃                     │    0x1020    │  val    :      7     │<━┛       ┃                          │  │    0x1020    │  val    :      7     │<━┛       ┃                      │  │  │    0x1020    │  val    :      7     │<━┛       ┃                       │  │  │    0x1020    │  val    :      7     │<━┛       ┃                     
//               ├──────────────────────┤          ┃                     │              ├──────────────────────┤          ┃                          │  │              ├──────────────────────┤          ┃                      │  │  │              ├──────────────────────┤          ┃                       │  │  │              ├──────────────────────┤          ┃                
//     0x1028    │  next   :  nullptr   │          ┃                     │    0x1028    │  next   :  nullptr   │          ┃                          │  │    0x1028    │  next   :  nullptr   │          ┃                      │  │  │    0x1028    │  next   :  nullptr   │          ┃                       │  │  │    0x1028    │  next   :  nullptr   │          ┃                
//               └──────────────────────┘          ┃                     │              └──────────────────────┘          ┃                          │  │              └──────────────────────┘          ┃                      │  │  │              └──────────────────────┘          ┃                       │  │  │              └──────────────────────┘          ┃               
//                                                 ┃                     │                                                ┃                          │  │                                                ┃                      │  │  │                                                ┃                       │  │  │                                                ┃                 
//   STACK (insert_ordered)                        ┃                     │  STACK (insert_ordered)                        ┃                          │  │  STACK (insert_ordered)                        ┃                      │  │  │  STACK (insert_ordered)                        ┃                       │  │  │  STACK (insert_ordered)                        ┃               
//               ┌──────────────────────┐          ┃                     │              ┌──────────────────────┐          ┃                          │  │              ┌──────────────────────┐          ┃                      │  │  │              ┌──────────────────────┐          ┃                       │  │  │              ┌──────────────────────┐          ┃               
//   0x7ffa50    │  rphead : ref phead  ┼──┐       ┃                     │  0x7ffa50    │  rphead : ref phead  ┼──┐       ┃                          │  │  0x7ffa50    │  rphead : ref phead  ┼──┐       ┃                      │  │  │  0x7ffa50    │  rphead : ref phead  ┼──┐       ┃                       │  │  │  0x7ffa50    │  rphead : ref phead  ┼──┐       ┃               
//               ├──────────────────────┤  │       ┃                     │              ├──────────────────────┤  │       ┃                          │  │              ├──────────────────────┤  │       ┃                      │  │  │              ├──────────────────────┤  │       ┃                       │  │  │              ├──────────────────────┤  │       ┃               
//   0x7ffa58    │  val    :      3     │  │       ┃                     │  0x7ffa58    │  val    :      3     │  │       ┃                          │  │  0x7ffa58    │  val    :      3     │  │       ┃                      │  │  │  0x7ffa58    │  val    :      3     │  │       ┃                       │  │  │  0x7ffa58    │  val    :      3     │  │       ┃              
//               ├──────────────────────┤  │       ┃                     │              ├──────────────────────┤  │       ┃                          │  │              ├──────────────────────┤  │       ┃                      │  │  │              ├──────────────────────┤  │       ┃                       │  │  │              ├──────────────────────┤  │       ┃               
//   0x7ffa60    │  new_elem: (uninit)  │  │       ┃                     │  0x7ffa60   ┌┼  new_elem:  0x0FF0   │  │       ┃                          │  │  0x7ffa60   ┌┼  new_elem:  0x0FF0   │  │       ┃                      │  │  │  0x7ffa60   ┌┼  new_elem:  0x0FF0   │  │       ┃                       │  │  │  0x7ffa60   ┌┼  new_elem:  0x0FF0   │  │       ┃                
//               ├──────────────────────┤  │       ┃                     └─────────────┘├──────────────────────┤  │       ┃                          │  └─────────────┘├──────────────────────┤  │       ┃                      │  │  └─────────────┘├──────────────────────┤  │       ┃                       │  │  └─────────────┘├──────────────────────┤  │       ┃               
//   0x7ffa68    │  scan   : (uninit)   │  │       ┃                        0x7ffa68    │  scan   : (uninit)   │  │       ┃                          │     0x7ffa68   ┌┼  scan   :  0x1000    │  │       ┃                      │  │     0x7ffa68   ┌┼  scan   :  0x1010    │  │       ┃                       │  │     0x7ffa68   ┌┼  scan   :  0x1010    │  │       ┃
//               ├──────────────────────┤  │       ┃                                    ├──────────────────────┤  │       ┃                          └────────────────┘├──────────────────────┤  │       ┃                      │  └────────────────┘├──────────────────────┤  │       ┃                       │  └────────────────┘├──────────────────────┤  │       ┃               
//   0x7ffa70    │  prev   : (uninit)   │  │       ┃                        0x7ffa70    │  prev   : (uninit)   │  │       ┃                                0x7ffa70    │  prev   :  nullptr   │  │       ┃                      │        0x7ffa70   ┌┼  prev   :  0x1000    │  │       ┃                       │        0x7ffa70   ┌┼  prev   :  0x1000    │  │       ┃ 
//               └──────────────────────┘  │       ┃                                    └──────────────────────┘  │       ┃                                            └──────────────────────┘  │       ┃                      └───────────────────┘└──────────────────────┘  │       ┃                       └───────────────────┘└──────────────────────┘  │       ┃
//                                         │       ┃                                                              │       ┃                                                                      │       ┃                                                                     │       ┃                                                                      │       ┃
//   STACK (main)                          │       ┃                        STACK (main)                          │       ┃                                STACK (main)                          │       ┃                               STACK (main)                          │       ┃                                STACK (main)                          │       ┃
//               ┌──────────────────────┐<─┘       ┃                                    ┌──────────────────────┐<─┘       ┃                                            ┌──────────────────────┐<─┘       ┃                                           ┌──────────────────────┐<─┘       ┃                                            ┌──────────────────────┐<─┘       ┃
//   0x7ffc40    │  phead  :  0x1000    ┼━━━━━━━━━━┛                        0x7ffc40    │  phead  :  0x1000    ┼━━━━━━━━━━┛                                0x7ffc40    │  phead  :  0x1000    ┼━━━━━━━━━━┛                               0x7ffc40    │  phead  :  0x1000    ┼━━━━━━━━━━┛                                0x7ffc40    │  phead  :  0x1000    ┼━━━━━━━━━━┛ 
//               └──────────────────────┘                                               └──────────────────────┘                                                       └──────────────────────┘                                                      └──────────────────────┘                                                       └──────────────────────┘ 
//
//                   
//
// Per manipolare una lista utilizziamo quella che si chiama la "tecnica dei due puntatori":
// - un puntatore (scan) che scorre la lista alla ricerca della posizione corretta
// - un puntatore (prev) che tiene traccia dell'elemento precedente a scan
// La tecnica dei due puntatori ha il vantaggio di evitare di dover utilizzare tecniche
// più complesse (in primis, il puntatore a puntatore, che è l'arma definitiva per
// manipolare le liste), ma ha come svantaggio quello di dover gestire esplicitamente
// il caso speciale dell'inserimento in testa.
// Infatti, quando facciamo una manipolazione della lista, ci si potrebbe chiedere
// perché non usiamo semplicemente un puntatore a Elem (Elem *phead), e in effetti per
// qualsiasi caso che non coinvolge direttamente la modifica del puntatore phead presente
// nello stack frame di main, il riferimento non serve, ma quando dobbiamo modificare
// il valore stesso di phead (inserimento in testa, cancellazione in testa), allora il
// riferimento al puntatore diventa necessario, perché il main deve vedere la modifica
// fatta alla testa della lista, di cui possiede un puntatore (che appunto verrà
// aggiornato). Qualora invece non si facciano inserimenti/cancellazioni in testa, allora
// il riferimento al puntatore non serve, e come si può evincere dalla logica qui sotto,
// non viene sfruttato nel caso generale di inserimento in posizione > 0.
// In maniera analoga, nel caso particolare di inserimento in testa, si farà uso
// esplicitamente del riferimento al puntatore "phead", per propagare la modifica al main.
// Se volessimo dare una motivazione ulteriore al perché serve gestire in maniera
// particolare il caso della modifica della testa della lista, si potrebbe dire che la
// testa della lista non ha un elemento precedente (prev), mentre prev deve puntare a
// un elemento valido.

// Ordine crescente -> [1, 3, 5, 7, ..]
void insert_ordered(Elem *&rphead, int val) {
    // (1)
    Elem *new_elem = new Elem;
    new_elem->val = val;
    new_elem->next = nullptr;
	// (2)


    Elem *scan = rphead;
    Elem *prev = nullptr;
	
    // (3)
	// Mi devo posizionare in modo che `prev` punti all'ultimo elemento per cui vale `elem->val < val`
	// e `scan` punti o al primo elemento per cui vale `elem->val >= val` o a `nullptr`
	// (in quest'ultimo caso, `prev` punta all'ultimo elemento della lista), 
	// così da poter inserire `new_elem` tra `prev` e `scan`.
	
	//	   [1,  3, 5]	
	//		  ↑
	//	      2
    while (scan != nullptr && val > scan->val) {
        prev = scan;
        scan = scan->next;
    }

    // (4)
    new_elem->next = scan;
    // Nel caso in cui `prev` == nullptr, questo è equivalente a `new_elem->next = head`
    if (prev == nullptr) {
	    // Caso particolare: inserimento in testa.
        // Questo sembra un assegnamento normale, ma in realtà `head` è un riferimento
        // a un puntatore (che vive nello stack frame di `main`), quindi questa istruzione
        // modifica effettivamente il puntatore `head` che vive nello stack frame di `main`.
        rphead = new_elem;
    } else {
        // Caso generale: inserimento in posizione > 0
        prev->next = new_elem;
	    // (5)
    }

    // Ci potremmo chiedere, visto che abbiamo uniformato il caso dell'inserimento del
    // successivo a `new_elem` (facendo `new_elem->next = scan` in ogni caso), perché non
    // possiamo semplicemente fare `scan = new_elem` invece che distinguere i due casi
    // (inserimento in testa e inserimento in posizione > 0), utilizzando `rphead` e
    // `prev->next` rispettivamente invece del semplice `scan`.
    // La risposta è che vogliamo avere un effetto collaterale sulla lista originale, e
    // sovrascrivere `scan` semplicemente cambierebbe l'indirizzo di una variabile locale
    // (ovvero modificherebbe solo una variabile che appartiene allo stack frame di questa
    // funzione), mentre noi utilizziamo `rphead` con *riferimento* per modificare il
    // puntatore che si trova nello stack frame di `main` (nel caso di inserimento in testa),
    // oppure `prev->next` per modificare il campo `next` di un elemento appartenente alla
    // lista. Tecniche (opinabilmente) più complesse permettono di evitare di dover
    // distinguere i due casi (tecnica del puntatore a puntatore e tecnica della "dummy head").
}

int main() {
    Elem *phead = nullptr;

    int n = 0;

    cout << "Inserisci una sequenza di numeri interi ";

    while (cin >> n) {
        insert_ordered(phead, n);
    }

    print(phead);

    return 0;
}
