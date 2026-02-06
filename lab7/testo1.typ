#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 0.54cm, bottom: 0.54cm, left: 0.54cm, right: 0.54cm),
)
#set text(size: 11pt, font: "New Computer Modern")
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
#title[Esercizio: Gestione di punti 2D in C++]

#v(1em)

= Parte A: Implementazione di una struttura `Point` e operazioni sui punti

Scrivi un programma in linguaggio *C++* che:

- definisca una struttura `Point` che rappresenti un punto nel piano tramite due valori interi;
- nel `main`, dichiari due variabili di tipo `Point` e legga da tastiera quattro valori interi per inizializzarle (due per ciascun punto);
- dopo la lettura, stampi i due punti;
- calcoli la loro somma ottenendo un nuovo punto e ne stampi il valore;
- per supportare queste operazioni, è possibile implementare funzioni dedicate:

#v(1em)
```cpp
void point_print(Point p) {
    ...
}

Point point_add(Point p1, Point p2) {
    ...
}
```

== Esempio

=== Input

```text
3 4
1 2
```

#v(1em)
=== Output

```text
p1 = (3, 4)
p2 = (1, 2)
p1 + p2 = (4, 6)
```

#v(2em)

= Parte B: Allocazione dinamica di coordinate e costruzione di punti

Estendi il programma precedente introducendo la seguente funzionalità:

- leggere da tastiera un numero intero `n`;
- verificare che `n` sia pari; in caso contrario stampare un messaggio di errore;
- allocare dinamicamente un array di `n` interi contenenti coordinate;
- creare dinamicamente un array di `n/2` punti costruiti a partire dalle coordinate lette;
- stampare ciascun punto generato.
== Esempi
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1em,
  [

    === Input

    ```text
    6
    3 4 1 2 7 8
    ```

    #v(10pt)
    === Output

    ```text
    Point 0: (3, 4)
    Point 1: (1, 2)
    Point 2: (7, 8)
    ```
  ],
  [
    === Input

    ```text
    5
    ```

    #v(10pt)
    === Output

    ```text
    Errore: il numero di coordinate deve essere pari.
    ```
  ],
)

