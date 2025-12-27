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

= Esercizio: Conteggio dei numeri pari in un array

#v(7em)

Scrivi un programma in linguaggio *C++* che:

- dichiari un array di dimensione fissa $N = 6$;
- legga da tastiera $N$ numeri interi e li memorizzi nell'array;
- stampi a video l'intero contenuto dell'array;
- calcoli quanti numeri pari sono presenti nell'array;
- mostri a video il numero totale di elementi pari trovati.

#v(10pt)
== Esempio

=== Input:
```text
5 8 13 20 7 2
```

=== Output:

```text
Array: 5 8 13 20 7 2 
Risultato: 3
```
