#include <iostream>
using namespace std;


// ================================================================================
//                    M A S S I M O   C O M U N E   D I V I S O R E
//                                (Algoritmo di Euclide)
// ================================================================================
// 
// Obiettivo
// --------------------------------------------------------------------------------
// Dati due numeri naturali a e b, calcolare il loro massimo comune divisore:
// MCD(a, b).
// 
// Nota sul lessico (solo in QUESTO commento):
// - Usiamo "//" per indicare la divisione intera, per evitare confusione con la
//   divisione reale (non c'è ambiguità perché siamo in ℕ, ma è più chiaro).
// - Quindi: q = a // b  (quoziente),  r = a % b  (resto).
// 
// 
// ┌────────────────────────────────────────────────────────────────────┐
// │                        a = b * q + r                               │      (1)
// └────────────────────────────────────────────────────────────────────┘
//                              ↑   ↑   ↑
//                              │   │   └────────── r : resto di a diviso b (a % b)
//                              │   └────────────── q : quoziente (a // b)
//                              └────────────────── b : divisore (> 0)
// 
// dove vale 0 <= r < b
// 
// Sostituendo:
//     q = a // b
//     r = a %  b
// Otteniamo:
// 
// ┌────────────────────────────────────────────────────────────────────┐
// │                   a = b * (a // b) + (a % b)                       │
// └────────────────────────────────────────────────────────────────────┘
// 
// 
// Esempi
// --------------------------------------------------------------------------------
// 
// 1) a = 20, b = 6        →      20 = 6  * (20 // 6)  + (20 % 6)  = 6  * 3 + 2
// 2) a =  7, b = 10       →       7 = 10 * (7  // 10) + (7  % 10) = 10 * 0 + 7
// 
// 
// Principio dell'algoritmo di Euclide
// 
// ┌────────────────────────────────────────────────────────────────────┐
// │                      MCD(a, b) = MCD(b, r)                         │
// └────────────────────────────────────────────────────────────────────┘
// 
// con r = a % b
// 
// 
// Iterando:
//     MCD(a, b) = MCD(b, a % b) = MCD(a % b, b % (a % b)) = ...
//                                                   = ultimo secondo elemento != 0
// 
// --------------------------------------------------------------------------------
// Perché termina?
// --------------------------------------------------------------------------------
// Ad ogni passo sostituiamo (a, b) con (b, r) con 0 <= r < b. Quindi la seconda
// componente diminuisce strettamente: b = r0 > r1 > r2 > ... >= 0. Quando il resto
// diventa 0, l'ultimo divisore non nullo è il MCD.
// 
// ┌────────────────────────────────────────────────────────────────────┐
// │                  CONDIZIONE DI ARRESTO:  r == 0                    │
// │            ⇒ MCD(a, b) è l'ultimo valore non nullo di b           │
// └────────────────────────────────────────────────────────────────────┘
// 
// --------------------------------------------------------------------------------
// Casi particolari e normalizzazioni
// --------------------------------------------------------------------------------
// - Se b == 0  ⇒  MCD(a, 0) = a.
// - Se a < b   ⇒  primo passo: MCD(a, b) = MCD(b, a) (poiché MCD(a, b) = MCD(b, a %
//   b) = MCD(b, a) quando a < b). Quindi si può assumere a >= b
// 
// --------------------------------------------------------------------------------
// Schema operativo
// --------------------------------------------------------------------------------
// 1) Se b == 0, ritorna a.
// 2) r = a % b
// 3) (a, b) ← (b, r) e torna al punto 1.
// 
// Invariante:
//     Ad ogni iterazione vale     MCD(a, b) = MCD(b, a % b)
// 
// --------------------------------------------------------------------------------
// Esempi di esecuzione
// --------------------------------------------------------------------------------
// Esempio A: a = 20, b = 6
// 
// Iterazione 1:  a = 20,  b = 6
//                ↓
//                r = 20 % 6 = 2
//                ↓
//                Nuovi valori: a = 6, b = 2
// 
// Iterazione 2:  a = 6,   b = 2
//                ↓
//                r = 6 % 2 = 0
//                ↓
//                Nuovi valori: a = 2, b = 0
// 
//                b = 0  → STOP!
// 
//                Il MCD è l'ultimo valore di `b` diverso da 0
//                (ovvero l'ultimo valore di `a` corrispondente a `b = 0`)
//                ↓
//     ┌───────────────┐
//     │    MCD = 2    │
//     └───────────────┘
// 
// Esempio B: a = 7, b = 10
// 
// Iterazione 1:  a = 7,   b = 10
//                ↓
//                r = 7 % 10 = 7
//                ↓
//                Nuovi valori: a = 10, b = 7
// 
// Iterazione 2:  a = 10,  b = 7
//                ↓
//                r = 10 % 7 = 3
//                ↓
//                Nuovi valori: a = 7, b = 3
// 
// Iterazione 3:  a = 7,   b = 3
//                ↓
//                r = 7 % 3 = 1
//                ↓
//                Nuovi valori: a = 3, b = 1
// 
// Iterazione 4:  a = 3,   b = 1
//                ↓
//                r = 3 % 1 = 0
//                ↓
//                Nuovi valori: a = 1, b = 0
// 
//                b = 0  → STOP!
// 
//                Il MCD è l'ultimo valore di `b` diverso da 0
//                (ovvero l'ultimo valore di `a` corrispondente a `b = 0`)
//                ↓
//     ┌───────────────┐
//     │    MCD = 1    │
//     └───────────────┘
//

int main() {
    int a = 0;
    int b = 0;
    cout << "Inserisci due numeri interi:" << endl;
    cin >> a >> b;
    while (b != 0) {  // (1) Se b == 0, ritorna a.
        //  (*    (a, b) ← (b, a % b) e..
        int r = a % b;  // idealmente, vorrei fare questo: (a, b) = (b, a % b) tuttavia
                        // C++ non supporta questa sintassi, quindi uso una variabile di
                        // appoggio (`r`)
        a = b;
        b = r;
        // ..torna al punto 1 *)
    }
    cout << "Il massimo comune divisore è: " << a << endl;
    return 0;
}


// 
// --------------------------------------------------------------------------------
// Approfondimento: idea della dimostrazione
// --------------------------------------------------------------------------------
// 
// Dobbiamo dimostrare che MCD(a, b) = MCD(b, r) con r = a % b. Per fare ciò, basta
// dimostrare che `a` e `b` hanno gli stessi divisori comuni di `b` e `r`.
// 
// 
// Definizione di `n | m` (n divide m):
// ┌────────────────────────────────────┐
// │   n ∣ m  ⟺  ∃ k ∈ ℕ : m = k * n  │
// └────────────────────────────────────┘
// 
// Ovvero m % n = 0
// 
// Definizione di insieme dei divisori comuni di n e m:
// ┌──────────────────────────────────────────────────────────┐
// │  D(n, m) = { d ∈ ℕ : d > 0,  d | n  e  d | m }           │
// └──────────────────────────────────────────────────────────┘
// 
// Vogliamo mostrare:       D(a, b)  =  D(b, r)
// ovvero che `a` e `b` hanno gli stessi divisori comuni di `b` e `r` da cui segue
// che MCD(a, b) = MCD(b, r)
// 
// Basta provare le due inclusioni:
// 
// ---------------------------------------------------------------------
// (2)  Se d ∈ D(a, b)  allora d ∈ D(b, r)      [quindi D(a,b) ⊆ D(b,r)]
//      (Se `d` divide `a` e `d` divide `b` allora `d` divide `r`)
// ---------------------------------------------------------------------
//     Dalla (1) abbiamo
//     ┌─────────────────────┐
//     │    r = a - q * b    │
//     └─────────────────────┘
// 
//     Se d | a e d | b, esistono s, t ∈ ℕ tali che:
//     ┌──────────────────┐           ┌──────────────────┐
//     │    a = s * d     │     e     │    b = t * d     │
//     └──────────────────┘           └──────────────────┘
// 
//     Sostituendo in r:
// 
//         r   =        a  -  q *       b
//             =    s * d  -  q *  (t * d)
// 
//             =   d * (s - q * t)
// 
//     ⇒ d | r.  Poiché d | b per ipotesi, d divide sia b sia r.
//     ⇒ d ∈ D(b, r).
// 
// ---------------------------------------------------------------------
// (3)  Se d ∈ D(b, r)  allora d ∈ D(a, b)      [quindi D(b,r) ⊆ D(a,b)]
//      (Se `d` divide `b` e `d` divide `r` allora `d` divide `a`)
// ---------------------------------------------------------------------
//     Dalla (1) abbiamo
//     ┌─────────────────────┐
//     │    a = q * b + r    │
//     └─────────────────────┘
// 
//     Se d | b e d | r, esistono s, t ∈ ℕ tali che:
//     ┌──────────────────┐           ┌──────────────────┐
//     │    b = s * d     │     e     │    r = t * d     │
//     └──────────────────┘           └──────────────────┘
// 
//     Sostituendo in a:
// 
//         a   =   q *      b    +          r
//             =   q * (s * d)   +    (t * d)
// 
//             =   d * (q * s + t)
// 
//     ⇒ d | a.  Poiché d | b per ipotesi, d divide sia a sia b.
//     ⇒ d ∈ D(a, b).
// 
// Conclusione dalle (2) e (3):
// ┌──────────────────┐        ┌──────────────────┐
// │    D(a, b)       │   =    │     D(b, r)      │
// └──────────────────┘        └──────────────────┘
// 
// Poiché MCD(n, m) è il massimo elemento di D(n, m), dall'uguaglianza degli insiemi
// segue immediatamente:
// 
// ┌────────────────────────────────────────────────────────────────────┐
// │                      MCD(a, b) = MCD(b, r)                         │
// └────────────────────────────────────────────────────────────────────┘
//
 