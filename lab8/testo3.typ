#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 2.54cm, bottom: 1.54cm, left: 2.54cm, right: 2.54cm)
)
#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)
#show list: set block(above: 1.2em, below: 1.2em)
#set list(spacing: 1.2em)
#show title: set block(above: 1.4em, below: 1em)
#show title: it => [
  #v(1em)
  #align(center)[
    #set text(size: 23pt, weight: "regular")
    #it.body
  ]
]
#title[Esercizio: Stampa di una lista concatenata]

#v(6em)
Scrivi una funzione `pop_front` che gestisca una lista concatenata di interi, permettendo di inserire elementi in testa e di estrarne un certo numero dalla testa stessa.
- definisca la struttura `Elem`, contenente un valore intero e un puntatore al nodo successivo, così da rappresentare una lista concatenata;
- legga da tastiera una sequenza di numeri interi positivi e, per ciascun valore inserito, aggiunga un nuovo nodo *in testa* alla lista; la lettura termina quando viene inserito un carattere;
- implementi una funzione `pop_front` che rimuova e restituisca il primo elemento della lista; se la lista è vuota, la funzione deve restituire un puntatore nullo;
- utilizzi la funzione di stampa per mostrare sullo schermo la lista risultante.
#v(1em)

```cpp
struct Elem {
    int val;
    Elem *next;
};

Elem *pop_front(Elem *&rphead) {
    ...
}
```

#v(1em)

_Nota: dopo aver inserito un carattere, `cin` entra in uno stato di errore. Per resettare lo stato di `cin` e permettere ulteriori letture, puoi usare il seguente codice_:
#v(1em)
```cpp
cin.clear();
cin.ignore(10000, '\n');
```

#v(10pt)
== Esempi
#v(10pt)
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1em,
  [
    === Esempio 1:
    #v(10pt)

    `Inserisci una sequenza di numeri interi:` #text(fill: orange)[`1 2 3 4 .`]

    `Lista inserita: [4, 3, 2, 1]`

    `Elementi da estrarre:` #text(fill: orange)[`2`]

    `Lista dopo l'estrazione: [2, 1]`
  ],
  [
    === Esempio 2:
    #v(10pt)
    `Inserisci una sequenza di numeri interi:` #text(fill: orange)[`10 20 30 40 50 .`]

    `Lista inserita: [50, 40, 30, 20, 10]`
    
    `Elementi da estrarre:` #text(fill: orange)[`50`]

    `Lista dopo l'estrazione: []`
  ],
)
