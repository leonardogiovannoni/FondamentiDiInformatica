#include <cmath>
#include <iostream>
using namespace std;
struct Point {
    int x;
    int y;
};

// Funzione che somma due punti.
// Nota sui parametri: `Point p1`, `Point p2`.
// Qui stiamo passando le strutture *per valore*. Questo significa che quando
// chiamiamo `point_add(a, b)`, vengono create delle COPIE locali di `a` e `b`
// all'interno dello stack frame della funzione `point_add`.
// Poiché `Point` è piccolo (8 byte, ovvero 4 byte per `x` e 4 byte per `y`, la
// dimensione di un puntatore a 64 bit o di un registro della CPU), il passaggio
// per valore è molto efficiente. Se la struttura fosse stata grande (es. una
// matrice 100x100), avremmo preferito il passaggio per riferimento costante
// (`const Point &p1`) per evitare la copia.
//
//     STACK (frame di point_add)
//              ┌──────────────────────────┐
//     0x7fea10 │       p1: {1, 2}         │
//              ├──────────────────────────┤
//     0x7fea18 │       p2: {3, 4}         │
//              └──────────────────────────┘
//                    
//                    
//     STACK (frame di main)
//              ┌──────────────────────────┐
//     0x7feb10 │       p1: {1, 2}         │
//              ├──────────────────────────┤
//     0x7feb18 │       p2: {3, 4}         │
//              └──────────────────────────┘
Point point_add(Point p1, Point p2) {
    // Inizializziamo il punto risultato nella stessa maniera in cui
    // inizializziamo gli array (corrisponde ad azzerare tutti i campi).
    Point result = {};
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    
    // Ritorniamo il risultato *per valore*. `result` verrà copiato
    // nella variabile nel chiamante.
    return result;
}

void point_print(Point me) {
    cout << "(" << me.x << ", " << me.y << ")" << endl;
}

// Parte A: Utilizzo base e memoria automatica (STACK).
int parte_a() {
    int x = 0;
    int y = 0;
    cin >> x >> y;
    Point p1 = {};
    p1.x = x;
    p1.y = y;
    cin >> x >> y;
    Point p2 = {};
    p2.x = x;
    p2.y = y;
    cout << "p1 = ";
    point_print(p1);
    cout << "p2 = ";
    point_print(p2);
    // Qui chiamiamo la funzione che restituisce un nuovo Point.
    // Il valore di ritorno viene copiato in p3.
    Point p3 = point_add(p1, p2);
    cout << "p1 + p2 = ";
    point_print(p3);
    
    return 0;
}

// Parte B: Allocazione Dinamica e Mappatura Array -> Struct.
int parte_b() {
    int n = 0;
    cin >> n;
    // Controllo di validità: poiché ogni punto richiede 2 coordinate (x, y),
    // il numero totale di interi in input deve essere pari.
    if (n % 2 != 0) {
        cout << "Errore: il numero di coordinate deve essere pari." << endl;
        return 1;
    }
    // Allocazione dinamica di un vettore di interi.
    // `coords` è un puntatore che risiede sullo STACK, ma punta a un blocco di
    // memoria di dimensione `n * sizeof(int)` byte allocato sullo HEAP, ovvero una
    // sequenza di `n` valori interi.
    int *coords = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> coords[i];
    }
    //
    //   HEAP
    //          ┌───────────────┬───────────────┐
    //   0x2000 │ coords[1]: 20 │ coords[0]: 10 │<────┐
    //          ├───────────────┼───────────────┤     │
    //   0x2008 │ coords[3]: 40 │ coords[2]: 30 │     │
    //          ├───────────────┼───────────────┤     │
    //   0x2010 │ coords[5]: 60 │ coords[4]: 50 │     │
    //          └───────────────┴───────────────┘     │
    //                                                │
    //                                                │
    // STACK                                          │
    //          ┌───────────────────────────────┐     │
    // 0x7ffb10 │       coords : 0x2000         ┼─────┘
    //          ├───────────────────────────────┤
    // 0x7ffb18 │           size 6              │
    //          └───────────────────────────────┘
    //
    // Allocazione dinamica di una sequenza di Point.
    // La dimensione del vettore è n/2 perché ogni punto consuma 2 interi.
    Point *points = new Point[n / 2];
    
    // Esempio: n = 6 (quindi 3 punti).
    // coords: [ x0, y0, x1, y1, x2, y2 ]
    // indici:    0   1   2   3   4   5
    //
    // Vogliamo riempire:
    // punti: [ P0, P1, P2 ]
    //
    // Iterazione i=0:
    //   points[0].x prende coords[0] (indice base: 2*0 = 0)
    //   points[0].y prende coords[1] (indice base: 2*0 + 1 = 1)
    //
    // Iterazione i=1:
    //   points[1].x prende coords[2] (indice base: 2*1 = 2)
    //   points[1].y prende coords[3] (indice base: 2*1 + 1 = 3)
    //
    // Formula generale per l'i-esimo punto:
    //   x si trova all'indice `2 * i` del vettore coords.
    //   y si trova all'indice `2 * i + 1` del vettore coords.
    // Visualizzazione Mappatura:
    //
    //                         ┌───┬───┬───┬───┬───┬───┐
    //                         │ 1 │ 2 │ 5 │ 9 │ 8 │ 3 │
    //                         └───┴───┴───┴───┴───┴───┘
    //         Indici coords:    0   1   2   3   4   5
    //                           │   │   │   │   │   │
    //               ┌───────────┘   │   │   │   │   └───────────┐
    //               │    ┌──────────┘   │   │   └───────────┐   │
    //               │    │              │   │               │   │
    //               ▼    ▼              ▼   ▼               ▼   ▼
    //            ┌────┬────┐         ┌────┬────┐         ┌────┬────┐
    //            │.x=1│.y=2│         │.x=5│.y=9│         │.x=8│.y=3│
    //            └────┴────┘         └────┴────┘         └────┴────┘
    // Indici arr:     0                   1                   2
    
    for (int i = 0; i < n / 2; i++) {
        int x = coords[2 * i];
        int y = coords[2 * i + 1];
        
        points[i].x = x;
        points[i].y = y;
    }
    //
    //   HEAP
    //          ┌───────────────┬───────────────┐
    //   0x2100 │ arr[0].y: 20  │ arr[0].x: 10  │<────┐
    //          ├───────────────┼───────────────┤     │
    //   0x2108 │ arr[1].y: 40  │ arr[1].x: 30  │     │
    //          ├───────────────┼───────────────┤     │
    //   0x2110 │ arr[2].y: 60  │ arr[2].x: 50  │     │
    //          └───────────────┴───────────────┘     │
    //                                                │
    //                                                │
    // STACK                                          │
    //          ┌───────────────────────────────┐     │
    // 0x7ffa10 │       arr : 0x2100            ┼─────┘
    //          └───────────────────────────────┘
    for (int i = 0; i < n / 2; i++) {
        cout << "Point " << i << ": ";
        point_print(points[i]);
    }
    
    // Pulizia della memoria (deallocazione).
    // È fondamentale liberare la memoria allocata con `new` per evitare un consumo
    // di memoria non controllato: chiamando la `delete`, la `new` può riutilizzare
    // quel blocco di memoria per future allocazioni, evitando di doverne chiedere
    // altra al sistema operativo. Se facessimo per esempio una cosa del genere in
    // un ciclo infinito senza mai fare `delete`:
    // ```
    // while (true) {
    //     int *v = new int[1000];
    // }
    // ```
    // il programma continuerebbe a consumare sempre più memoria fino a esaurirla,
    // causando una terminazione forzata del programma. Si parla di OOM (Out Of
    // Memory), e in caso di OOM la `new` termina il programma (per quanto ci
    // riguarda). Usiamo `delete[]` (con le parentesi quadre) perché abbiamo
    // allocato blocchi di memoria per più elementi.
    delete[] coords;
    delete[] points;
    
    return 0;
}

int main() {
    // Decommentare una delle due righe per testare le diverse modalità
    return parte_a();
    // return parte_b();
}
