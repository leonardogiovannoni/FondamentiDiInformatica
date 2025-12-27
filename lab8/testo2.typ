#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 1.54cm, bottom: 1.54cm, left: 2.54cm, right: 2.54cm)
)
#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)
#show list: set block(above: 1.2em, below: 1.2em)
#set list(spacing: 1.2em)
#show heading: set block(above: 1.4em, below: 1em)
#show heading.where(level: 1): it => [
  #v(4em)
  #align(center)[
    #set text(size: 21pt, weight: "regular")
    #it.body
  ]
]

= Esercizio: Inserimento ordinato in una lista concatenata

#v(7em)

Scrivere un programma in linguaggio *C++* che:

- definisca la struttura `Elem`, contenente un valore intero e un puntatore al nodo successivo, così da rappresentare una lista concatenata;
- legga da tastiera una sequenza di numeri interi e, per ciascun valore inserito, aggiunga un nuovo nodo alla lista *mantenendola ordinata in senso crescente*; la lettura termina quando l'utente inserisce un carattere non numerico, ad esempio il punto;
- implementi una funzione `insert_ordered` che inserisca un nuovo elemento nella posizione corretta, in modo che la lista rimanga sempre ordinata;
- implementi una funzione `print` che visualizzi il contenuto della lista nel formato `[v1, v2, v3]`;
- utilizzi la funzione di stampa per mostrare sullo schermo la lista risultante al termine dell'inserimento.

#v(10pt)
```cpp
struct Elem {
    int val;
    Elem *next;
};

void insert_ordered(Elem *&rphead, int value) {
    ...
}

void print(Elem *phead) {
    ...
}
```

#v(10pt)
== Input

```text
3 5 1 .
```

#v(10pt)
== Output

```text
[1, 3, 5]
```

