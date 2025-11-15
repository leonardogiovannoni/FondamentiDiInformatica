#include <iostream>
using namespace std;

//                           ⎧ low     se x < low
//                           ⎪
//     clamp(x, low, high) = ⎨ x       se low ≤ x ≤ high
//                           ⎪
//                           ⎩ high    se x > high
//    
//     Rappresentazione di una funzione y = clamp(x, low=3, high=8)
// 
//     y     
//     ^                                                                                  
//     │                                                                           
//  10 ┤                                                                                                 
//     │                                                                                              
//   9 ┤                                                                                                                     
//     │                                                                                                                     
//   8 ┤ . . . . . . . . . . . . . . . ●───●───●─── ─ ─ ─      
//     │                               │                      
//   7 ┤ . . . . . . . . . . . . . ●───○                             
//     │                           │   .                          
//   6 ┤ . . . . . . . . . . . ●───○   .                          
//     │                       │   .   .                      
//   5 ┤ . . . . . . . . . ●───○   .   .                      
//     │                   │   .   .   .                   
//   4 ┤ . . . . . . . ●───○   .   .   .                                                           
//     │               │   .   .   .   .                                                                                
//   3 ┤─ ─ ───●───●───○   .   .   .   .                                                                                
//     │               .   .   .   .   .                                                                 
//   2 ┤               .   .   .   .   .                                            
//     │               .   .   .   .   .                   
//   1 ┤               .   .   .   .   .                   
//     │               .   .   .   .   .                                               
//   0 ┼───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────> x
//     0   1   2   3   4   5   6   7   8   9  10  11  12 
// 
//   In questo esempio: low = 3, high = 8
//   - Per x < 3:  y = 3  (valore clampato al minimo)
//   - Per 3 ≤ x ≤ 8:  y = x  (valore nell'intervallo, rimane invariato)
//   - Per x > 8:  y = 8  (valore clampato al massimo)
//
//   Notazione:
//   ● = punto incluso (valore raggiunto dalla funzione)
//   ○ = punto escluso (valore non raggiunto dalla funzione)
// 

//
//     ┌─────────────────────────────────────────────────────────┐
//     │                                                         │
//     │   se value < low    →  value = low                      │
//     │   se value > high   →  value = high                     │
//     │   altrimenti        →  value rimane invariato           │
//     │                                                         │
//     └─────────────────────────────────────────────────────────┘
//           


void clamp(int *value_ptr, int low, int high) {
    if (*value_ptr < low) {
        *value_ptr = low;
        
    } else if (*value_ptr > high) {
        *value_ptr = high;
    }
    // Se il valore è già nell'intervallo [low, high], non facciamo nulla e la
    // funzione termina lasciando il valore invariato
}

int main() {
    int a = 0;
    int low = 0;
    int high = 0;
    
    cin >> a >> low >> high;
    
    // Creazione di un puntatore che punta alla variabile `a`
    int *a_ptr = &a;
    
    // Rappresentazione dello stato della memoria prima della chiamata a clamp:
    //
    // Supponiamo che l'utente abbia inserito: 25 10 20
    //
    //      STACK (frame di main)
    //               ┌──────────────────────┐
    //  0x7ffc30     │  a_ptr  :  0x7ffc40  ┼──┐
    //               ├──────────────────────┤  │
    //  0x7ffc38     │  high   :      20    │  │
    //               ├──────────────────────┤  │
    //  0x7ffc3c     │  low    :      10    │  │
    //               ├──────────────────────┤  │
    //  0x7ffc40     │  a      :      25    │<─┘  (a_ptr punta a questo indirizzo)
    //               └──────────────────────┘
    //
    // Nota: gli indirizzi mostrati sono esempi; i valori reali dipendono dalla
    // configurazione del sistema e cambiano ad ogni esecuzione.
    
    // Chiamata alla funzione clamp passando il puntatore a `a`. Questo permette
    // alla funzione di modificare direttamente il valore di `a`
    clamp(a_ptr, low, high);
    
    // Durante l'esecuzione di clamp, lo stack si espande:
    //
    //      STACK (frame di clamp)
    //               ┌──────────────────────┐
    //  0x7ffa44     │  high      :    20   │  (copia del valore)
    //               ├──────────────────────┤
    //  0x7ffa48     │  low       :    10   │  (copia del valore)
    //               ├──────────────────────┤
    //  0x7ffa4c     │  value_ptr : 0x7ffc40┼──┐
    //               └──────────────────────┘  │
    //                                         │
    //      STACK (frame di main)              │
    //               ┌──────────────────────┐  │
    //  0x7ffc30     │  a_ptr  :  0x7ffc40  ┼──┤
    //               ├──────────────────────┤  │
    //  0x7ffc38     │  high   :      20    │  │
    //               ├──────────────────────┤  │
    //  0x7ffc3c     │  low    :      10    │  │
    //               ├──────────────────────┤  │
    //  0x7ffc40     │  a      :      25    │<─┘  (sia a_ptr che value_ptr puntano qui)
    //               └──────────────────────┘
    //
    // La funzione clamp valuta la condizione *value_ptr > high: *value_ptr è 25,
    // high è 20, quindi 25 > 20 è vero. Esegue quindi: *value_ptr = high, ovvero
    // scrive 20 nella locazione di memoria puntata da value_ptr, che è la variabile
    // `a` nel main
    
    // Dopo il ritorno da clamp, lo stato della memoria è:
    //
    //      STACK (frame di main)
    //               ┌──────────────────────┐
    //  0x7ffc30     │  a_ptr  :  0x7ffc40  ┼──┐
    //               ├──────────────────────┤  │
    //  0x7ffc38     │  high   :      20    │  │
    //               ├──────────────────────┤  │
    //  0x7ffc3c     │  low    :      10    │  │
    //               ├──────────────────────┤  │
    //  0x7ffc40     │  a      :      20    │<─┘  (il valore è stato modificato da 25 a 20)
    //               └──────────────────────┘
    
    // Stampa del risultato. Dereferenziamo il puntatore a_ptr per ottenere il
    // valore finale di `a`
    cout << "Il valore clamped è: " << *a_ptr << endl;
    
    // Nota: avremmo potuto stampare direttamente `a` invece di `*a_ptr`, dato che
    // puntano alla stessa locazione di memoria. Il risultato sarebbe identico: cout
    // << "Il valore clamped è: " << a << endl;
    
    return 0;
}

