#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 1.54cm, bottom: 1.54cm, left: 1.54cm, right: 1.54cm),
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
  #v(3em)
  #align(center)[
    #set text(size: 21pt, weight: "regular")
    #it.body
  ]
]

= Esercizio: Funzione `clamp` con puntatori

#v(4em)

Scrivi un programma in linguaggio *C++* che:

- legga da tastiera tre valori interi: un numero `k`, un limite inferiore `low` e un limite superiore `high`;
- definisca una funzione `clamp` che riceva come parametro un puntatore a intero e due limiti `low` e `high`;
- faccia in modo che la funzione `clamp` modifichi il valore puntato, portandolo:
  - a `low`, se è minore di `low`;
  - a `high`, se è maggiore di `high`;
  - lasciandolo invariato, se è già compreso tra `low` e `high`.

In termini matematici:
$
  "clamp"(k)
  =
  cases(
    l o w & "se" k < l o w,
    h i g h & "se" k > h i g h,
    k & "se" l o w <= k <= h i g h
  )
$

Dove $k in ZZ$. da cui seguirà una funzione C++ del tipo:
#v(1em)
```cpp
void clamp(int* pk, int low, int high) { .. }
```

- stampi infine il valore di `k` aggiornato dopo la chiamata alla funzione.

#v(10pt)
== Esempi

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    === Input:
    ```text 15 0 10  ```
    === Output:
    ```text Il valore clamped è: 10  ```
  ],
  [
    === Input:
    ```text -5 0 10  ```
    === Output:
    ```text Il valore clamped è: 0  ```
  ],
)

#v(1em)

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    === Input:
    ```text 7 0 10  ```
    === Output:
    ```text Il valore clamped è: 7  ```
  ],
  [
    === Input:
    ```text -15 -10 -5  ```
    === Output:
    ```text Il valore clamped è: -10  ```
  ],
)

#v(1em)

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    === Input:
    ```text 0 0 10  ```
    === Output:
    ```text Il valore clamped è: 0  ```
  ],
  [
    === Input:
    ```text 10 0 10  ```
    === Output:
    ```text Il valore clamped è: 10  ```
  ],
)
