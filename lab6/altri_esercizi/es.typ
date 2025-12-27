#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 1.24cm, bottom: 1.24cm, left: 1.24cm, right: 1.24cm),
)

#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)

// Configuration for bullet lists
#show list: set block(above: 1.2em, below: 1.2em)
#set list(marker: ([•], [--]), spacing: 0.8em, indent: 1em)

// Configuration for numbered lists
#show enum: set block(above: 1.2em, below: 1.2em)
#set enum(spacing: 1.2em)


#show title: set block(above: 1.4em, below: 1em)
#show title: it => [
  #v(1em)
  #align(center)[
    #set text(size: 23pt, weight: "regular")
    #it.body
  ]
]

#set heading(numbering: none)

#set par(
  justify: true,
  first-line-indent: 0pt,
  leading: 0.65em,
)


#show heading.where(level: 1): set heading(numbering: "1.")
#title[Esercizi di Programmazione (C++): Array, Cstring e Matrici]

#v(1em)

= Implementazione della funzione my_strlen 

*Testo. * Scrivi una funzione:
#v(1em)
```cpp
int my_strlen(const char s[]);
```
#v(1em)
che calcola la lunghezza di una stringa C-style senza usare la libreria standard.

Nel `main`:
- dichiara un array str di capacità 51;
- leggi una stringa da input;
- calcola la lunghezza usando my_strlen;
- stampa la lunghezza calcolata.

#v(10pt)

== Esempi
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1em,
  [

    === Input

    ```text
    ciao
    ```

    #v(10pt)
    === Output

    ```text
    Lunghezza: 4
    ```
  ],
  [
    === Input

    ```text
    programmazione
    ```

    #v(10pt)
    === Output

    ```text
    Lunghezza: 14
    ```
  ],
)

= Copia dei soli caratteri alfabetici

*Testo. * Scrivi una funzione:
#v(1em)
```cpp
void filtra_alfabetici(char dst[], int dst_capacity, const char src[]);
```
#v(1em)
che copia in `dst` soltanto i caratteri alfabetici (`A-Z`, `a-z`) contenuti in `src`, rispettando la capacità `capacity`.

Nel `main`:
- leggi una stringa in `str1` (capacità 10),
- dichiara `str2` (capacità 100),
- chiama `filtra_alfabetici(str2, 10, str1)`,
- stampa il risultato.

#v(10pt)

== Esempi
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1em,
  [

    === Input

    ```text
    C++17_e'_potente!
    ```

    #v(10pt)
    === Output

    ```text
    Cepotente
    ```
  ],
  [
    === Input

    ```text
    Hello123World!
    ```

    #v(10pt)
    === Output

    ```text
    HelloWorl
    ```
  ],
)

#v(10pt)
_Nota: la capacità di `str2` è 10, quindi l'output contiene al massimo 9 caratteri più il terminatore nullo, per cui "HelloWorld" diventa "HelloWorl"._

= Somma degli elementi per riga in una matrice lineare

*Testo. * Implementa una funzione:
#v(1em)
```cpp
int somma_riga(const int *m, int cols, int rows, int r);
```
#v(1em)
che somma gli elementi della riga indicata.

Nel `main`:
- leggi una matrice 4 x 5 in una matrice;
- per ogni riga, stampa la relativa somma.

#v(10pt)

== Esempio

=== Input
```text
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
```

#v(10pt)
=== Output
```text
Somma riga 0: 15
Somma riga 1: 40
Somma riga 2: 65
Somma riga 3: 90
```

= Trasposizione di una matrice rettangolare

*Testo. * Scrivi una funzione:
#v(1em)
```cpp
void trasponi(const int *src, int *dst, int rows, int cols);
```
#v(1em)

che memorizza in `dst` la matrice trasposta della matrice `src`.

La trasposizione soddisfa:

$ (A^T)_(i, j) = A_(j, i)
  quad forall A in ZZ^(m, n)
  quad 1 <= i <= m,
  quad 1 <= j <= n 
$

$
mat(delim: "[",
  a_(1,1), a_(1,2), dots, a_(1,n);
  a_(2,1), a_(2,2), dots, a_(2,n);
  dots.v,   dots.v,   dots.down,  dots.v;
  a_(m,1), a_(m,2), dots, a_(m,n)
)^T
=
mat(delim: "[",
  a_(1,1), a_(2,1), dots, a_(m,1);
  a_(1,2), a_(2,2), dots, a_(m,2);
  dots.v,   dots.v,   dots.down, dots.v;
  a_(1,n), a_(2,n), dots, a_(m,n)
)
$


Nel `main`:
- leggi una matrice 3 x 4;
- trasponila in una matrice 4 x 3;
- stampa il risultato.

#v(10pt)

== Esempio

=== Input
```text
1 2 3 4
5 6 7 8
9 10 11 12
```

#v(10pt)
=== Output
```text
1 5 9
2 6 10
3 7 11
4 8 12
```

= Verifica dell'alfabeto italiano (21 lettere)

*Testo. * Scrivi una funzione:
#v(1em)
```cpp
bool is_alfabeto_italiano_21(const char s[]);
```
#v(1em)
che restituisce `true` solo se la stringa è composta esclusivamente dalle *21 lettere dell'alfabeto italiano*, maiuscole o minuscole.

Nel `main`:
- leggi una stringa di lunghezza massima 50;
- verifica che rispetti l'alfabeto italiano;
- stampa `OK` oppure `NO`.

#v(10pt)

== Esempi
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1em,
  [

    === Input

    ```text
    casa
    ```

    #v(10pt)
    === Output

    ```text
    OK
    ```
  ],
  [
    === Input

    ```text
    yogurt
    ```

    #v(10pt)
    === Output

    ```text
    NO
    ```
  ],
)
