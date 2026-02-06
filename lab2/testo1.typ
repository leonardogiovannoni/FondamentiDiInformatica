
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

// Configuration for numbered lists (added to match the LaTeX enumerate)
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
#title[Esercizio 1: Stampa numeri da 0 a n-1]

#v(7em)

Scrivi un programma in linguaggio *C++* che:

+ *Legga* da tastiera un numero intero positivo `n`.
+ *Stampi* tutti i numeri interi da `0` a `n - 1`, ognuno su una riga.

#v(10pt)
== Esempio

=== Input:
```text
5
```
=== Output:

```text
0
1
2
3
4
```

