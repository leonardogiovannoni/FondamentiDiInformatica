#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 2.54cm, bottom: 2.54cm, left: 2.54cm, right: 2.54cm)
)
#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)

// Configuration for bullet lists
#show list: set block(above: 1.2em, below: 1.2em)
#set list(spacing: 1.2em)

// Configuration for numbered lists
#show enum: set block(above: 1.2em, below: 1.2em)
#set enum(spacing: 1.2em)

#show heading: set block(above: 1.4em, below: 1em)
#show heading.where(level: 1): it => [
  #v(4em)
  #align(center)[
    #set text(size: 21pt, weight: "regular")
    #it.body
  ]
]

= Esercizio: Risoluzione di un'equazione di secondo grado

#v(7em)

Scrivi un programma in linguaggio *C++* che trovi le soluzioni reali dell'equazione di secondo grado nella forma:

$ a x^2 + b x + c = 0 $
#v(0.5em)
dove i coefficienti $a$, $b$ e $c$ sono numeri reali inseriti dall'utente.
Gestire i casi particolari in cui alcuni (o tutti i) coefficienti sono nulli.
Utilizzare una funzione per calcolare le soluzioni dell'equazione di secondo grado.

#v(10pt)
== Esempi

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    === Input:
    ```text
    1 -3 2
    ```
    === Output:
    ```text
    Due soluzioni reali distinte:
    x1 = 2
    x2 = 1
    ```
  ],
  [
    === Input:
    ```text
    1 2 1
    ```
    === Output:
    ```text
    Una soluzione reale doppia:
    x = -1
    ```
  ]
)

#v(1em)

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    === Input:
    ```text
    1 0 1
    ```
    === Output:
    ```text
    Nessuna soluzione reale
    (discriminante negativo).
    ```
  ],
  [
    === Input:
    ```text
    0 2 -4
    ```
    === Output:
    ```text
    Equazione di primo grado.
    Soluzione: x = 2
    ```
  ]
)

#v(1em)

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    === Input:
    ```text
    0 0 3
    ```
    === Output:
    ```text
    L'equazione non ha soluzioni.
    ```
  ],
  [
    === Input:
    ```text
    0 0 0
    ```
    === Output:
    ```text
    L'equazione ha infinite soluzioni.
    ```
  ]
)
